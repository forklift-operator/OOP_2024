#include "FigureCollection.hpp"

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
        os << "**** " << count << " ****" << std::endl;
        fig->Print(os);
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
