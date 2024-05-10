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

private:
    FIGURE_TYPE type = FIGURE_TYPE::Rhombus;
public:
    FIGURE_TYPE GetType() const {return this->type;};
    Quadrilateral(){};
    Quadrilateral(Point A, Point B, Point C, Point D);
    virtual double GetArea() const;
    virtual double GetPerimeter() const;
    void Print(std::ostream &os);
    
    Figure* clone() override;

    ~Quadrilateral() = default;
};
