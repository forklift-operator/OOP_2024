#include "Circle.hpp"

Circle::Circle(const Point center, const double radius)
{
    this->center = center;
    this->radius = radius;
}

double Circle::GetArea() const
{
    return M_PI * this->radius * this->radius;
}

double Circle::GetPerimeter() const
{
    return 2 * M_PI * this->radius;
}

void Circle::Print(std::ostream &out)
{
    out << "Center: " ;
    this->center.Print(out);
    out << "Radius: " << this->radius;
}

Figure *Circle::clone()
{
    return new Circle(*this);
}
