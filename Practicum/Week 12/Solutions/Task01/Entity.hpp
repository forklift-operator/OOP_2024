#pragma once
#include <iostream>
#include <vector>
#include <string>

class Entity
{
public:
    std::string name;

    virtual Entity *clone() = 0;

    virtual Entity* find(const std::string&) = 0;
    virtual size_t getFilesCount() const = 0;

    virtual std::string getName() const = 0;
    virtual size_t getSize() const = 0;
    virtual void display(int indent = 0) = 0;
    virtual ~Entity() = default;
};
