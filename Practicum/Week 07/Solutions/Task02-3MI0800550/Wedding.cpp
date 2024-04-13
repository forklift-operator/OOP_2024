#include "Wedding.hpp"

void Wedding::Blessing(Person &person1, Person &person2)
{
    std::cout << "Congratulations to " << person1.GetName() << " and " << person2.GetName() << " on their marriage!" << std::endl;
}

Wedding::Wedding()
{
    this->location = new char[1];
}

Wedding::Wedding(const char *location)
{
    this->location = new char[strlen(location) + 1];
    strcpy(this->location, location);
}

Wedding::Wedding(const Wedding &other)
{
    this->location = new char[strlen(other.location) + 1];
    strcpy(this->location, other.location);
}

Wedding &Wedding::operator=(const Wedding &other)
{
    if (this != &other)
    {
        delete[] this->location;
        this->location = new char[strlen(other.location) + 1];
        strcpy(this->location, other.location);
    }
    return *this;
}

Wedding::~Wedding()
{
    delete[] location;
}

void Wedding::AddTable(const Table &table)
{
    this->tables[taken_spaces] = table;
    taken_spaces++;
}

void Wedding::Marry(Person &person1, Person &person2)
{
    if (person1.GetWeddingStatus() == Wedding_Status::BRIDE && person2.GetWeddingStatus() == Wedding_Status::GROOM ||
        person1.GetWeddingStatus() == Wedding_Status::GROOM && person2.GetWeddingStatus() == Wedding_Status::BRIDE)
    {
        if (person1.GetStatus() == Status::SINGLE && person2.GetStatus() == Status::SINGLE)
        {
            if (person1.GetAge() > 18 && person2.GetAge() > 18)
            {
                if (person1.GetGender() != person2.GetGender())
                {
                    Wedding::Blessing(person1, person2);
                    person1.SetStatus(Status::MARRIED);
                    person2.SetStatus(Status::MARRIED);
                }
                else
                    std::cout << "No gay marriage!" << std::endl;
            }
            else
                std::cout << "Both people must be over 18!" << std::endl;
        }
        else
            std::cout << "Both people must be singe!" << std::endl;
    }
    else
        std::cout << "Both people must be either bride or groom!" << std::endl;
};