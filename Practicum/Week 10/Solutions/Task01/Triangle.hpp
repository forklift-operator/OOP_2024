#pragma once
#include "Point.hpp"
#include "Figure.hpp"

class Triangle : public Figure
{
private:
    Point a;
    Point b;
    Point c;

public:
    Triangle(){};
    Triangle(Point a, Point b, Point c);
    double GetArea() const;
    double GetPerimeter() const;
    void Print(std::ostream &os);
    
    ~Triangle() = default;
};
