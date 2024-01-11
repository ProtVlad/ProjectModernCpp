#include "GameTimer.h"

GameTimer::GameTimer()
{
}

GameTimer::GameTimer(int durationInSeconds) : m_duration(durationInSeconds)
{
}

void GameTimer::DisplayThread()
{
    for (int m_currentTimeValue = m_duration; m_currentTimeValue > 0; --m_currentTimeValue)
    {
        std::cout << "Seconds left: " << m_currentTimeValue << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void GameTimer::Start()
{
    std::thread displayThread(&GameTimer::DisplayThread, this);
    std::this_thread::sleep_for(std::chrono::seconds(m_duration));
    std::cout << "Timer expired!\n";
    displayThread.join();
}

const uint8_t GameTimer::GetDuration() const
{
    return m_duration;
}

const uint8_t GameTimer::GetCurrentTimeValue() const
{
    return m_currentTimeValue;
}
