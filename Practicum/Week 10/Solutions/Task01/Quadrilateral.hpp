#pragma once
#include "Point.hpp"
#include "Figure.hpp"

class Quadrilateral : public Figure
{
protected:
    Point A;
    Point B;
    Point C;
    Point D;

public:
    Quadrilateral(){};
    Quadrilateral(Point A, Point B, Point C, Point D);
    virtual double GetArea() const;
    virtual double GetPerimeter() const;
    void Print(std::ostream &os);

    ~Quadrilateral() = default;
};
