#pragma once
#include "Person.hpp"

const size_t MAX_PEOPLE_ON_TABLE = 5;

class Table
{
private:
    char *name;
    unsigned min_age;
    unsigned taken_seats = 0;

public:
    Person people[5];
    void AddPerson(const Person &person);
    void RemovePerson(const Person &person);
    unsigned GetRemainingSeats();

    Table();
    Table(const char *name, const unsigned min_age);
    Table(const char *name, const unsigned min_age, const Person *people, const size_t num_of_people);
    ~Table() { delete[] name; };
};
