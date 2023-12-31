#include "GameTimer.h"

GameTimer::GameTimer(int durationInSeconds) : duration(durationInSeconds)
{
}

void GameTimer::DisplayThread()
{
    for (int i = duration; i > 0; --i)
    {
        std::cout << "Seconds left: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}