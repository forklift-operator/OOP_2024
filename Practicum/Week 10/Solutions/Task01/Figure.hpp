#pragma once
#include <iostream>

enum class FIGURE_TYPE{
    Triangle,
    Circle,
    Rhombus,
    Square,
    Rectangle,
    Parallelogram,
    Trapezoid
};

class Figure
{
public:
    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;
    virtual void Print(std::ostream &) = 0;
    virtual FIGURE_TYPE GetType() const = 0;
    virtual ~Figure(){};

    virtual Figure *clone() = 0;
};
