#include "Circle.hpp"
#include "Triangle.hpp"

int main()
{
    Triangle c(Point(0, 0), Point(1, 0), Point(1, 1));
    std::cout << c.GetArea() << std::endl;

    return 0;
}
