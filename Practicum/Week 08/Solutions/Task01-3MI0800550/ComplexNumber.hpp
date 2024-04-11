#pragma once
#include <iostream>
#include <cmath>

class ComplexNumber
{
public:
    double AbsComplex();
    bool operator!();
    
    


    ComplexNumber &operator+=(const ComplexNumber &other);
    ComplexNumber &operator+=(const double x);
    friend ComplexNumber operator+(const ComplexNumber &num, double real);
    friend ComplexNumber operator+(double real, const ComplexNumber &num);
    // ComplexNumber operator+(const ComplexNumber &other);
    // ComplexNumber operator+(const double x);

    ComplexNumber &operator-=(const ComplexNumber &other);
    ComplexNumber &operator-=(const double x);
    ComplexNumber operator-(const ComplexNumber &other);
    ComplexNumber operator-(const double x);

    ComplexNumber &operator*=(const ComplexNumber &other);
    ComplexNumber &operator*=(double x);
    friend ComplexNumber operator*(const ComplexNumber &num, double real);
    friend ComplexNumber operator*(double real, const ComplexNumber &num);
    // ComplexNumber operator*(const ComplexNumber &other);
    // ComplexNumber operator*(const double x);

    friend std::ostream &operator<<(std::ostream& out, const ComplexNumber &num);
    friend std::istream &operator>>(std::istream& in, ComplexNumber &num);

    ComplexNumber();
    ComplexNumber(double, double);
    ComplexNumber(const ComplexNumber &other);
    ComplexNumber &operator=(const ComplexNumber &other);
    ~ComplexNumber(){};

    const double getReal();
    const double getImag();

private:
    double a, b;
};
