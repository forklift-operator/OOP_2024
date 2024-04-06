#pragma once
#include <iostream>

class Time
{
private:
    unsigned total_seconds = 0;
    unsigned seconds = 0;
    unsigned minutes = 0;
    unsigned hours = 0;
public:
    Time();
    Time(unsigned seconds);
    Time(unsigned hours, unsigned minutes, unsigned seconds);

    Time TimeLeftTillMidnight();
    void AddSec();

    bool IsTimeForDinner();
    bool IsTimeForParty();

    Time Difference(Time& other);
    bool Compare(Time& other);

    void Print();
};


