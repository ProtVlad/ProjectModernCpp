#pragma once
#include <iostream>
#include <chrono>
#include <thread>
class GameTimer
{
public:
    GameTimer(int durationInSeconds); 

    void DisplayThread();
private:
    int duration;
};

