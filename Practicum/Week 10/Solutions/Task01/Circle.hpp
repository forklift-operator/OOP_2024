#pragma once
#include "Point.hpp"
#include "Figure.hpp"

class Circle : public Figure
{
private:
    Point center;
    double radius;

public:
    Circle()=default;
    Circle(const Point center, const double radius);
    virtual double GetArea() const;
    virtual double GetPerimeter() const;
    void Print(std::ostream &os);

    ~Circle(){};
};
