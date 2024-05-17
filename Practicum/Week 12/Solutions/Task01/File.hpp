#pragma once
#include "Entity.hpp"

class File : public Entity
{
private:
    std::string content;
    size_t size = 0;

public:
    Entity *clone() override;
    Entity *find(const std::string &) override;

    std::string getName() const;
    size_t getSize() const;
    void display(int indent = 0);
    size_t getFilesCount() const override;

    File(const std::string &name);
    File(const std::string &name, const std::string &content);
    ~File() = default;
};