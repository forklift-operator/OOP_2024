#include <iostream>

class Natural
{
protected:
    unsigned num;

public:
    Natural(){};
    Natural(unsigned x){num = x;};
    void Print(){std::cout << num << std::endl;};
};

class Integer : public Natural
{
private:
    bool isNegative;

public:
    Integer(){};
    Integer(int num){(num < 0) ? isNegative = true : isNegative = true;};
    void Print(){
        (isNegative) ? std::cout << '-' <<num << std::endl : std::cout << num << std::endl;
    };
};

class Real : public Integer
{
private:
    unsigned denominator;

public:
    Real(int numenator, unsigned denom){
        num = numenator;
        denominator = denom;
    };
    void Print(){
        std::cout << num << '/' << denominator << std::endl;
    };
};

class Complex : public Real
{
private:
    Real imaginary;

public:
    void Print();
};
