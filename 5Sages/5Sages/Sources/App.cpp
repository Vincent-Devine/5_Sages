#include <App.hpp>

App::~App()
{
    for (std::mutex* chopstick : chopsticks)
        delete chopstick;
}

void App::Init()
{
    Draw::AskValue(initValue);

    for (unsigned int i = 0; i < initValue.nbSages; i++)
    {
        chopsticks.push_back(new std::mutex);
        sages.push_back(Sage(chopsticks.back()));
    }

    for (unsigned int i = 0; i < sages.size(); i++)
    {
        if (i != 0)
        {
            sages[i - 1].SetChopstickNeighbour(chopsticks[i]);
        }
    }
    sages[sages.size() - 1].SetChopstickNeighbour(chopsticks[0]);

    for (unsigned int i = 0; i < sages.size(); i++)
        threads.push_back(std::thread());
}

void App::UpdateAndDraw()
{
    for (unsigned int i = 0; i < initValue.nbDays; i++)
    {
        Start(); // Start Sage::Update
        Draw(i);

        for (Sage& sage : sages)
            sage.NewDay();

        for (std::thread& thread : threads)
            thread.join();
    }
}

void App::Start()
{
    for (unsigned int i = 0; i < threads.size(); i++)
        threads[i] = std::thread(&Sage::Update, std::ref(sages[i]), initValue);
}

const void App::Draw(const unsigned int p_day)
{
    while (!CheckAllSage())
        Draw::DrawStat(sages, p_day);

    Draw::DrawStat(sages, p_day);
}

const bool App::CheckAllSage() const
{
    for (const Sage& sage : sages)
    {
        if (sage.GetStat() != Stats::SLEEP)
            return false;
    }
    return true;
}