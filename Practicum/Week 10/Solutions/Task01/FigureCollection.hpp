#pragma once
#include <iostream>
#include <vector>
#include "Figure.hpp"


class FigureCollection
{
private:
    std::vector<Figure *> figures;

public:
    FigureCollection() = default;

    void addFigure(const Figure &figure);
    void removeFigure(const Figure &figure);
    void clear();

    void Print(std::ostream &os);

    ~FigureCollection();
};
