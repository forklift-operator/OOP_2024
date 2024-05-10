#pragma once
#include "Point.hpp"
#include "Figure.hpp"

class Circle : public Figure
{
private:
    Point center;
    double radius;

    FIGURE_TYPE type = FIGURE_TYPE::Circle;
public:
    FIGURE_TYPE GetType() const {return this->type;};
    Circle() = default;
    Circle(const Point center, const double radius);
    virtual double GetArea() const;
    virtual double GetPerimeter() const;
    void Print(std::ostream &os);

    Figure *clone() override;

    ~Circle() = default;
};
