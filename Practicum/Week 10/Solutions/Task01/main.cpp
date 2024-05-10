#include "Circle.hpp"
#include "Triangle.hpp"
#include "FigureCollection.hpp"

int main()
{
    Triangle c(Point(0, 0), Point(1, 0), Point(1, 1));
    // std::cout << c.GetArea() << std::endl;
    Circle a(Point(0,0), 1.3);

    FigureCollection fc;

    fc.addFigure(c);
    fc.addFigure(a);
    fc.Print(std::cout);
    
    return 0;
}
