#include <iostream>
#include <cstring>

class Beer
{
private:
    const size_t MAX_BRAND_CAP = 128;
    char* brand;
    double mils;
    
public:
    Beer();
    Beer(const char* brand, double mils);
    Beer(const Beer& other);
    Beer& operator=(const Beer& other);
    ~Beer(){delete[] brand;};

    const char* GetBeerBrand();
    double GetBeerVolume();
    Beer& Add(Beer& other, double mils);
    Beer& AddMils(double mils);
    bool Check(const char* brand);
};
