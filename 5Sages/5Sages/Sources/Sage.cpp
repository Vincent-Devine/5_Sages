#include <Sage.hpp>

#include <random>
#include <thread>
#include <chrono>

Sage::Sage(std::mutex* p_chopstick)
	: chopstick(p_chopstick)
	, chopstickNeighbour(nullptr)
	, timeTotalEat(0)
	, stat(Stats::NONE)
{
}

void Sage::Update(const Utils::InitValue& p_initValue)
{
	while (stat != Stats::SLEEP)
	{
		if (stat == Stats::HUNGRY)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			Eat(p_initValue.timeEatMin, p_initValue.timeEatMax, p_initValue.timeEatTotal);
		}
		else if (timeTotalEat >= p_initValue.timeEatTotal)
			Sleep();
		else
			Think(p_initValue.timeThinkMin, p_initValue.timeThinkMax);
	}
}

void Sage::NewDay()
{
	timeTotalEat = 0;
	stat = Stats::THINK;
}

void Sage::Think(const unsigned int p_timeMin, const unsigned int p_timeMax)
{
	stat = Stats::THINK;

	const unsigned int time = Utils::GetRandomValue(p_timeMin, p_timeMax);
	std::this_thread::sleep_for(std::chrono::seconds(time));

	stat = Stats::HUNGRY;
}

void Sage::Sleep()
{
	stat = Stats::SLEEP;
}

void Sage::Eat(const unsigned int p_timeMin, const unsigned int p_timeMax, const unsigned int p_timeEatTotal)
{
	if (chopstick->try_lock())
	{
		if (chopstickNeighbour->try_lock())
		{
			stat = Stats::EAT;
	
			unsigned int time = Utils::GetRandomValue(p_timeMin, p_timeMax);

			if (time + timeTotalEat >= p_timeEatTotal)
				time = p_timeEatTotal - timeTotalEat;

			timeTotalEat += time;
			std::this_thread::sleep_for(std::chrono::seconds(time));

			chopstick->unlock();
			chopstickNeighbour->unlock();
		}
		else
		{
			chopstick->unlock();
		}
	}
}