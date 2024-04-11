#include "Person.hpp"

int Person::id = 1;

const char* Person::GetName() const
{
    return this->name;
}

unsigned Person::GetAge()
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

Person::Person(const char *name, unsigned age, Gender gender, Status status, Personstatus person_status)
{

    person_id = id;
    id++;
    this->name = new char[strlen(name + 1)];

    strcpy(this->name, name);

    this->age = age;
    this->gender = gender;
    this->status = status;
    this->person_status = person_status;
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
