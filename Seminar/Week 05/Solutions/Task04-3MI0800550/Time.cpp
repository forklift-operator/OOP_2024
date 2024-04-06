#include "Time.hpp"

Time::Time()
{
    seconds = 0;
    minutes = 0;
    hours = 0;
}

Time::Time(unsigned seconds)
{
    this->total_seconds = seconds;

    this->hours = seconds / 3600;
    this->minutes = (seconds % 60) / 60;
    this->seconds = (seconds % 3600) % 60;
}

Time::Time(unsigned hours, unsigned minutes, unsigned seconds)
{
    this->total_seconds = hours * 3600 + minutes * 60 + seconds;

    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
}

Time Time::TimeLeftTillMidnight()
{
    unsigned midnight_in_sec = 24 * 3600;

    return Time(midnight_in_sec - this->total_seconds);
}

void Time::AddSec()
{
    this->total_seconds++;
    this->seconds++;
}

bool Time::IsTimeForDinner()
{
    unsigned time_for_dinner_start = 20 * 3600 + 30 * 60;
    unsigned time_for_dinner_end = 22 * 3600;

    if (this->total_seconds >= time_for_dinner_start && this->total_seconds <= time_for_dinner_end)
        return true;

    return false;
}

bool Time::IsTimeForParty()
{
    unsigned time_for_party_start = 23 * 3600;
    unsigned time_for_party_end = 6 * 3600;

    if (this->total_seconds <= time_for_party_end && this->total_seconds <= time_for_party_start)
        return true;

    return false;
}

Time Time::Difference(Time &other)
{
    if (other.total_seconds >= this->total_seconds)
    {
        return Time(other.total_seconds - this->total_seconds);
    }
    return Time(24 * 3600 - this->total_seconds - other.total_seconds);
}

bool Time::Compare(Time &other)
{
    if (other.total_seconds >= this->total_seconds)
    {
        return false;
    }
    return true;
}

void Time::Print()
{
    if (hours < 10)
    {
        std::cout << "0" << this->hours;
    }
    else
        std::cout << this->hours;
    if (minutes < 10)
    {
        std::cout << ":0" << this->minutes;
    }
    else
        std::cout << ":" << this->minutes;
    if (seconds < 10)
    {
        std::cout << ":0" << this->seconds << std::endl;
    }
    else
        std::cout << ":" << this->seconds << std::endl;
}
