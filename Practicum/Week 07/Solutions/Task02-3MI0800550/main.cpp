#include <iostream>
#include "Table.hpp"
#include "Person.hpp"
#include "Wedding.hpp"
#include "Date.hpp"

int main()
{

    Person p1("ivan", 23, Gender::MALE, Status::SINGLE, Wedding_Status::GROOM);
    Person p2("ema", 44, Gender::FEMALE, Status::SINGLE, Wedding_Status::BRIDE);
    Person p3("gergi", 17, Gender::MALE, Status::SINGLE, Wedding_Status::GUEST);
    Person p4("maria", 17, Gender::FEMALE, Status::SINGLE, Wedding_Status::GUEST);
    Person p5("stoqn", 17, Gender::MALE, Status::SINGLE, Wedding_Status::GUEST);

    Person people[5] = {p1, p2, p3, p4, p5};

    Table t("ADULTS", 18, people, 5);

    // t.AddPerson(p1);
    // t.AddPerson(p2);
    // t.AddPerson(p3);

    Wedding w("Bulgaria");
    w.AddTable(t);

    w.Marry(p1, p2);

    return 0;
}
