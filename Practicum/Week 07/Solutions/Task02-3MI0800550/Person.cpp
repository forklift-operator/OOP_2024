#include "Person.hpp"

int Person::id = 1;

const char *Person::GetName() const
{
    return this->name;
}

unsigned Person::GetAge() const
{
    return this->age;
}

Gender Person::GetGender()
{
    return this->gender;
}

Status Person::GetStatus()
{
    return this->status;
}

Wedding_Status Person::GetWeddingStatus()
{
    return this->wedding_status;
}

void Person::SetStatus(Status new_status)
{
    this->status = new_status;
}

Person::Person()
{
    person_id = id;
    id++;
    this->name = new char[1];
}

Person::Person(const char *name, unsigned age, Gender gender, Status status, Wedding_Status wedding_status)
{

    person_id = id;
    id++;
    this->name = new char[strlen(name + 1)];

    strcpy(this->name, name);

    this->age = age;
    this->gender = gender;
    this->status = status;
    this->wedding_status = wedding_status;
}

Person::Person(const Person &other)
{
    copy(other);
}

Person &Person::operator=(const Person &other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

bool Person::operator==(const Person &other)
{
    if (this->person_id == other.person_id)
    {
        return true;
    }
    return false;
}
