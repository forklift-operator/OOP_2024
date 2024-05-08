#include "FigureCollection.hpp"

void FigureCollection::doubleCap()
{
    cap *= 2;
    Figure **temp = figures; 
    figures = new Figure *[cap];
    for (size_t i = 0; i < size; i++)
    {
        figures[i] = temp[i];
    }
}

void FigureCollection::free()
{
    delete[] figures;
}

void FigureCollection::addFigure(const Figure *figure)
{
    size++;
    if (size > cap)
    {
        cap *= 2;
        figures = new Figure *[cap];
    }
}

void FigureCollection::clear()
{
    for (size_t i = 0; i < size; i++)
    {
        figures[i] = nullptr;
    }
}

FigureCollection::~FigureCollection()
{
    free();
}
