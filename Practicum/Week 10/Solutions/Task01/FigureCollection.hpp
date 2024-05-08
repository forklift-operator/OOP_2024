#pragma once
#include <iostream>
#include "Figure.hpp"

class FigureCollection : public Figure
{
private:
    Figure **figures;
    size_t size = 0, cap;

    void doubleCap();
    void copy();
    void free();
public:
    FigureCollection() : cap(1), size(0){};
    void addFigure(const Figure *figure);
    void removeFigure(Figure figure);
    void clear();
    ~FigureCollection();
};
