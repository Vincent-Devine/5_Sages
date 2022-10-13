#pragma once

#include <mutex>

#include <Utils.hpp>

enum class Stats
{
	EAT,
	THINK,
	HUNGRY,
	SLEEP,
	NONE
};

class Sage
{
	// Attribute
public:
	std::mutex* chopstick;
	std::mutex* chopstickNeighbour;

private:
	unsigned int timeTotalEat = 0;
	Stats stat;

	// Methode
public:
	Sage(std::mutex* p_chopstick);

	void Update(const Utils::InitValue& p_initValue);
	void NewDay();

	const int GetTimeTotalEat() const { return timeTotalEat; };
	const Stats GetStat() const { return stat; };
	void SetChopstickNeighbour(std::mutex* p_chopstickNeighbour) { chopstickNeighbour = p_chopstickNeighbour; };

private:
	void Think(const unsigned int p_timeMin, const unsigned int p_timeMax);
	void Sleep();
	void Eat(const unsigned int p_timeMin, const unsigned int p_timeMax, const unsigned int p_timeEatTotal);
};
