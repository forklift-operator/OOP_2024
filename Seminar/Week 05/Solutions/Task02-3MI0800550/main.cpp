#include "Beer.hpp"

int main()
{
    Beer a("Kamenica", 250);
    Beer b("Burgasko", 500);

    a.Add(b, 250);

    std::cout << a.GetBeerBrand() << " " << a.GetBeerVolume() << std::endl;

    return 0;
}
