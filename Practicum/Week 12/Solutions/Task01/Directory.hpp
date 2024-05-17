#pragma once
#include "Entity.hpp"

class Directory : public Entity
{
private:
    std::vector<Entity *> fd;
    size_t length = 0;

    Entity *clone();

public:
    std::string getName() const override;
    size_t getSize() const override;
    void display(int indent = 0) override;
    size_t getFilesCount() const override;
    Entity *find(const std::string &) override;
    void addEntity(Entity *);
    void copy(Entity *);

    Directory(const std::string name);
    ~Directory();
};
