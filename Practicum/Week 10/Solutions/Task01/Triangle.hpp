#pragma once
#include "Point.hpp"
#include "Figure.hpp"

class Triangle : public Figure
{
private:
    Point a;
    Point b;
    Point c;

    FIGURE_TYPE type = FIGURE_TYPE::Triangle;
public:
    FIGURE_TYPE GetType() const {return this->type;};
    Triangle(){};
    Triangle(Point a, Point b, Point c);
    double GetArea() const;
    double GetPerimeter() const;
    void Print(std::ostream &os);

    Figure* clone() override;
    
    ~Triangle() = default;
};
