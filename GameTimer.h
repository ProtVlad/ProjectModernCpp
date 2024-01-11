#pragma once
#include <iostream>
#include <chrono>
#include <thread>
class GameTimer
{
public:
    GameTimer();
    GameTimer(int durationInSeconds); 

    void DisplayThread();
    void Start();

    const uint8_t GetCurrentTimeValue() const;
    const uint8_t GetDuration() const;
private:
    uint8_t m_duration;
    uint8_t m_currentTimeValue;
};

