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

enum class Wedding_Status
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
    Wedding_Status wedding_status;

    void copy(const Person &other)
    {
        name = new char[strlen(other.name + 1)];
        strcpy(name, other.name);

        age = other.age;
        gender = other.gender;
        id = other.id;
        status = other.status;
        wedding_status = other.wedding_status;
    }

    void free()
    {
        delete[] name;
    }

public:
    size_t person_id;

    const char *GetName() const;
    unsigned GetAge() const;
    Gender GetGender();
    Status GetStatus();
    Wedding_Status GetWeddingStatus();
    void SetStatus(Status new_status);

    Person();
    Person(const char *name, unsigned age, Gender gender, Status status, Wedding_Status wedding_status);
    Person &operator=(const Person &other);
    bool operator==(const Person &other);
    Person(const Person &other);
    ~Person() { delete[] name; };
};
