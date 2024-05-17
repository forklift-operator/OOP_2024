#include "File.hpp"

Entity *File::clone()
{
    return new File(*this);
}

Entity *File::find(const std::string &o_name)
{
    if (this->getName() == o_name)
        return this;
    else
        return nullptr;
}

std::string File::getName() const
{
    return name;
}

size_t File::getSize() const
{
    return size;
}

void File::display(int indent)
{
    std::cout << this->getName() << std::endl;
}

size_t File::getFilesCount() const
{
    return 1;
}

File::File(const std::string &name)
{
    this->name = name;
    size++;
}

File::File(const std::string &name, const std::string &content)
{
    this->name = name;
    this->content = content;
    size = content.length();
}
