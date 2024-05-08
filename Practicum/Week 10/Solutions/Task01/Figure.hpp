#pragma once

class Figure
{
public:
    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const {};
    virtual void Print(std::ostream &) {};
    virtual ~Figure(){};
};
