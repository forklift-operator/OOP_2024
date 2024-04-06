#include "Beer.hpp"

bool isSubstring(const char *str, const char *substr)
{
    int len_str = std::strlen(str);
    int len_substr = std::strlen(substr);

    for (int i = 0; i <= len_str - len_substr; ++i)
    {
        int j;
        for (j = 0; j < len_substr; ++j)
        {
            if (str[i + j] != substr[j])
                break;
        }
        if (j == len_substr)
            return true;
    }
    return false;
}

Beer::Beer()
{
    brand = new (std::nothrow) char[1];
    mils = 0;
}

Beer::Beer(const char *brand, double mils)
{
    this->brand = new (std::nothrow) char[strlen(brand) + 1];
    strcpy(this->brand, brand);
    this->mils = mils;
}

Beer::Beer(const Beer &other)
{
    this->brand = new (std::nothrow) char[strlen(other.brand) + 1];
    strcpy(this->brand, other.brand);
    this->mils = other.mils;
}

Beer &Beer::operator=(const Beer &other)
{
    if (this == &other)
        return *this;

    this->brand = new (std::nothrow) char[strlen(other.brand) + 1];
    strcpy(this->brand, other.brand);
    this->mils = other.mils;

    return *this;
}

const char *Beer::GetBeerBrand()
{
    return this->brand;
}

double Beer::GetBeerVolume()
{
    return this->mils;
}

Beer &Beer::Add(Beer &other, double mils)
{
    char *temp = this->brand;
    this->brand = new (std::nothrow) char[strlen(this->brand) + strlen(other.brand) + 2];
    strcat(strcat(strcat(this->brand, temp), "&"), other.brand);
    this->mils += mils;
    other.mils -= mils;

    return *this;
}

Beer &Beer::AddMils(double mils)
{
    this->mils += mils;

    return *this;
}

bool Beer::Check(const char *brand)
{
    if (isSubstring(this->brand, brand))
        return true;
    return false;
}
