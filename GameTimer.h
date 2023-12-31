#pragma once
#include <iostream>
#include <chrono>
#include <thread>
class GameTimer
{
public:
    GameTimer(int durationInSeconds); 

    void DisplayThread();
    void Start();
private:
    int duration;
};

