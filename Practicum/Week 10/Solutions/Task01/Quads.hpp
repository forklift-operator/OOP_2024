#pragma once
#include "Quadrilateral.hpp"

class Trapezoid : public Quadrilateral
{

private:
    FIGURE_TYPE type = FIGURE_TYPE::Trapezoid;
public:
    FIGURE_TYPE GetType() const {return this->type;};
    Trapezoid(Point A, Point B, Point C, Point D);
    ~Trapezoid(){};
};

class Parallelogram : public Quadrilateral
{
private:
    FIGURE_TYPE type = FIGURE_TYPE::Parallelogram;
public:
    FIGURE_TYPE GetType() const {return this->type;};
    Parallelogram() = default;
    Parallelogram(Point A, Point B, Point C, Point D);
    ~Parallelogram(){};
};

class Rectangle : public Parallelogram
{
private:
    FIGURE_TYPE type = FIGURE_TYPE::Rectangle;
public:
    FIGURE_TYPE GetType() const {return this->type;};
    Rectangle(Point A, Point B, Point C, Point D);
    ~Rectangle(){};
};

class Square : public Parallelogram
{
private:
    FIGURE_TYPE type = FIGURE_TYPE::Square;
public:
    FIGURE_TYPE GetType() const {return this->type;};
    Square(Point A, Point B, Point C, Point D);
    ~Square(){};
};

class Rhombus : public Parallelogram
{
private:
    FIGURE_TYPE type = FIGURE_TYPE::Rhombus;
public:
    FIGURE_TYPE GetType() const {return this->type;};
    Rhombus(Point A, Point B, Point C, Point D);
    ~Rhombus(){};
};
