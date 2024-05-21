#include "Directory.hpp"

Entity *Directory::clone()
{
    return new Directory(*this);
}

std::string Directory::getName() const
{
    return name;
}

size_t Directory::getSize() const
{
    size_t total_size = 0;
    for (Entity *ent : fd)
    {
        total_size += ent->getSize();
    }
    return total_size;
}

void Directory::display(int indent)
{
    std::cout << this->getName() << std::endl;
    indent++;
    for (Entity *ent : fd)
    {
        for (size_t i = 0; i < indent; i++)
        {
            std::cout << "  |";
        }
        std::cout << "_";
        ent->display(indent);
    }
}

size_t Directory::getFilesCount() const
{
    size_t total_files = 0;
    for (Entity *ent : fd)
    {
        total_files += ent->getFilesCount();
    }
    return total_files;
}

Entity *Directory::find(const std::string &c_name)
{
    if (this->getName() == c_name)
        return this;

    Entity *found = nullptr;

    for (Entity *ent : fd)
    {
        found = ent->find(c_name);

        if (found)
            return found;
    }
    return found;
}

void Directory::addEntity(Entity *n_fd)
{
    fd.push_back(n_fd);
    length++;
}

void Directory::copy(Entity *n_fd)
{
    fd.push_back(n_fd->clone());
}

Directory::Directory(const std::string name)
{
    this->name = name;
}

Directory::~Directory() {}
