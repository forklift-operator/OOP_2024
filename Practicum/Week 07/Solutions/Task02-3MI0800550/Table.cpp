#include "Table.hpp"

void Table::AddPerson(const Person &person)
{
    if (taken_seats > MAX_PEOPLE_ON_TABLE)
    {
        std::cout << "Table doesnt have more seats" << std::endl;
        return;
    }

    this->people[this->taken_seats] = person;
    taken_seats++;
}

void Table::RemovePerson(const Person &person)
{
    for (size_t i = 0; i < MAX_PEOPLE_ON_TABLE; i++)
    {
        if (person.person_id == this->people[i].person_id)
        {
            this->people[i] = this->people[taken_seats];
            taken_seats--;
            return;
        }
    }
    std::cout << "There is no " << person.GetName() << " on the table" << std::endl;
}

unsigned Table::GetRemainingSeats()
{
    return MAX_PEOPLE_ON_TABLE-taken_seats;
}

Table::Table()
{
    this->name = new char[0];
}

Table::Table(const char *name, const unsigned min_age)
{
    this->name = new char[strlen(name + 1)];
    strcpy(this->name, name);
    size_t people_count = 0;
    this->min_age = min_age;
}
