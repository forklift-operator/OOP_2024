#include "FigureCollection.hpp"

const char *FigureCollection::CheckType(FIGURE_TYPE type)
{
    switch (type)
    {
    case FIGURE_TYPE::Triangle:
        return "Triangle";
    case FIGURE_TYPE::Circle:
        return "Circle";
    case FIGURE_TYPE::Rhombus:
        return "Rhombus";
    case FIGURE_TYPE::Square:
        return "Sqaure";
    case FIGURE_TYPE::Rectangle:
        return "Rectangle";
    case FIGURE_TYPE::Parallelogram:
        return "Parallelogram";
    case FIGURE_TYPE::Trapezoid:
        return "Trapezoid";
    default:
        return "idk";
    }
}

void FigureCollection::addFigure(const Figure &figure)
{
    figures.push_back((Figure *)&figure);
}

void FigureCollection::removeFigure(const Figure &figure)
{
    for (Figure *fig : figures)
    {
        if (fig == (Figure *)&figure)
        {
            delete fig;
        }
    }
}

void FigureCollection::clear()
{
    for (size_t i = 0; i < figures.size(); i++)
    {
        delete figures[i];
    }
}

void FigureCollection::Print(std::ostream &os)
{
    size_t count = 1;
    for (Figure *fig : figures)
    {
        os << "**** " << CheckType(fig->GetType()) << " ****" << std::endl;
        fig->Print(os);
        os << std::endl;
        count++;
    }
}

FigureCollection::~FigureCollection()
{
    for (size_t i = 0; i < figures.size(); i++)
    {
        delete figures[i];
    }
}
