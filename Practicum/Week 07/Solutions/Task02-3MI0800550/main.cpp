#include <iostream>
#include "Table.hpp"
#include "Person.hpp"
#include "Wedding.hpp"
#include "Date.hpp"

int main()
{

    Person p1("ivan", 23, Gender::MALE, Status::SINGLE, Personstatus::GUEST);
    Person p2("ema", 44, Gender::FEMALE, Status::SINGLE, Personstatus::GUEST);
    Person p3("gergi", 17, Gender::MALE, Status::SINGLE, Personstatus::GUEST);
    Person p4("maria", 17, Gender::FEMALE, Status::SINGLE, Personstatus::GUEST);
    Person p5("stoqn", 17, Gender::MALE, Status::SINGLE, Personstatus::GUEST);

    Person people[5] = {p1, p2, p3, p4, p5};

    Table t("ADULTS", 99);

    t.AddPerson(p1);
    t.AddPerson(p2);
    t.AddPerson(p3);

    Wedding w("Bulgaria");
    w.AddTable(t);

    w.Marry(p1, p2);

    return 0;
}
