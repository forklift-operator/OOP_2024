#pragma once
#include <iostream>

class Date
{
private:
    unsigned day;
    unsigned month;
    unsigned year;

    const int MAX_VALID_YR = 9999;
    const int MIN_VALID_YR = 1800;

    bool isLeap(int year)
    {
        return (((year % 4 == 0) &&
                 (year % 100 != 0)) ||
                (year % 400 == 0));
    }

    bool isValidDate(int d, int m, int y)
    {
        if (y > MAX_VALID_YR ||
            y < MIN_VALID_YR)
            return false;
        if (m < 1 || m > 12)
            return false;
        if (d < 1 || d > 31)
            return false;

        if (m == 2)
        {
            if (isLeap(y))
                return (d <= 29);
            else
                return (d <= 28);
        }

        if (m == 4 || m == 6 ||
            m == 9 || m == 11)
            return (d <= 30);

        return true;
    }

public:
    Date()
    {
        unsigned day = 1;
        unsigned month = 1;
        unsigned year = 1;
    };

    Date(const unsigned day, const unsigned month, const unsigned year)
    {
        if (isValidDate(day, month, year))
        {
            this->day = day;
            this->month = month;
            this->year = year;
        }
        else
            throw "Error in date";
    };

    void Print()
    {
        std::cout << day << '.' << month << '.' << year << std::endl;
    };
};
