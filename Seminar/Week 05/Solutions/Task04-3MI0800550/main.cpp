#include "Time.hpp"

int main()
{
    Time a(3,0,8);
    Time b(5,0,0);

    Time x(b.Difference(a));
    Time y(a.TimeLeftTillMidnight());
    y.Print();

    std::cout << x.IsTimeForDinner() << std::endl;

    return 0;
}
