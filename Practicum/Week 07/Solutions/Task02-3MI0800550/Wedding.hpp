#pragma once
#include "Table.hpp"
#include "Date.hpp"
const size_t MAX_TABLES = 10;

class Wedding
{
private:
    Table tables[MAX_TABLES];
    char *location;
    Date date;
    size_t taken_spaces = 0;
    static void Blessing(Person &, Person &);

public:
    Wedding();
    Wedding(const char *location);
    Wedding(const Wedding &other);
    Wedding &operator=(const Wedding &other);
    ~Wedding();

    void AddTable(const Table &table);
    void RemoveTable(const Table &table);

    void Marry(Person &person1, Person &person2);
};

