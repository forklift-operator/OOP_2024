#pragma once

#include <iostream>
#include <cstring>

enum class Gender
{
    MALE,
    FEMALE
};

enum class Status
{
    SINGLE,
    TAKEN,
    MARRIED
};

enum class Personstatus
{
    GROOM,
    BRIDE,
    GUEST,
    PRIEST
};

class Person
{
private:
    static int id;

    char *name;
    unsigned age;
    Gender gender;
    Status status;
    Personstatus person_status;

    void copy(const Person &other)
    {
        name = new char[strlen(other.name + 1)];
        strcpy(name, other.name);

        age = other.age;
        gender = other.gender;
        id = other.id;
        status = other.status;
        person_status = other.person_status;
    }

    void free()
    {
        delete[] name;
    }

public:
    size_t person_id;

    const char *GetName() const;
    unsigned GetAge();
    Gender GetGender();
    Status GetStatus();
    void SetStatus(Status new_status);

    Person();
    Person(const char *name, unsigned age, Gender gender, Status status, Personstatus person_status);
    Person &operator=(const Person &other);
    bool operator==(const Person &other);
    Person(const Person &other);
    ~Person() { delete[] name; };
};
