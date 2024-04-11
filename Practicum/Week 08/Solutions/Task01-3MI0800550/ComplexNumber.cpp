#include "ComplexNumber.hpp"

ComplexNumber::ComplexNumber()
{
    a = 0;
    b = 0;
}

ComplexNumber::ComplexNumber(double real, double imag)
{
    a = real;
    b = imag;

    if (imag == 0)
        throw std::invalid_argument("Imaginary must me diff than 0!");
}

ComplexNumber::ComplexNumber(const ComplexNumber &other)
{
    a = other.a;
    b = other.b;
}

ComplexNumber &ComplexNumber::operator=(const ComplexNumber &other)
{
    if (this != &other)
    {
        a = other.a;
        b = other.b;
    }
    return *this;
}

const double ComplexNumber::getReal()
{
    return this->a;
}

const double ComplexNumber::getImag()
{
    return this->b;
}

void ComplexNumber::SetReal(const double real)
{
    this->a = real;
}

void ComplexNumber::SetImag(const double imag)
{
    this->b = imag;
}

double ComplexNumber::AbsComplex()
{
    return sqrt(this->a * this->a + this->b * this->b);
}

bool ComplexNumber::operator!()
{
    return this->a == 0 && this->b == 0;
}

// ComplexNumber ComplexNumber::operator+(const ComplexNumber &other)
// {
//     return ComplexNumber(this->a + other.a, this->b + other.b);
// }

// ComplexNumber ComplexNumber::operator+(const double x)
// {
//     return ComplexNumber(this->a + x, this->b);
// }

ComplexNumber &ComplexNumber::operator-=(const ComplexNumber &other)
{
    this->a - other.a;
    this->b - other.b;
    return *this;
}

ComplexNumber &ComplexNumber::operator-=(const double x)
{
    this->a - x;
    return *this;
}

ComplexNumber &ComplexNumber::operator+=(const ComplexNumber &other)
{
    this->a + other.a;
    this->b + other.b;
    return *this;
}

ComplexNumber &ComplexNumber::operator+=(const double x)
{
    this->a + x;
    return *this;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &other)
{
    return ComplexNumber(this->a - other.a, this->b - other.b);
}

ComplexNumber ComplexNumber::operator-(const double x)
{
    return ComplexNumber(this->a - x, this->b);
}

ComplexNumber &ComplexNumber::operator*=(const ComplexNumber &other)
{
    this->a *other.a;
    this->b *other.b;
    return *this;
}

ComplexNumber &ComplexNumber::operator*=(double x)
{
    this->a *x;
    this->b *x;
    return *this;
}

// ComplexNumber ComplexNumber::operator*(const ComplexNumber &other)
// {
//     return ComplexNumber(this->a * other.a - this->b * other.b, this->a * other.b - this->b * other.a);
// }

// ComplexNumber ComplexNumber::operator*(const double x)
// {
//     return ComplexNumber(this->a * x, this->b * x);
// }

ComplexNumber operator+(const ComplexNumber &num, double real)
{
    return ComplexNumber(real + num.a, num.b);
}

ComplexNumber operator+(double real, const ComplexNumber &num)
{
    return ComplexNumber(real + num.a, num.b);
}

ComplexNumber operator*(const ComplexNumber &num, double real)
{
    return ComplexNumber(num.a*real, num.b*real);
}

ComplexNumber operator*(double real, const ComplexNumber &num)
{
    return ComplexNumber(num.a*real, num.b*real);
}

std::ostream &operator<<(std::ostream &out, const ComplexNumber &num)
{
    out << num.a << " + " << num.b << 'i';
    return out;
}

std::istream &operator>>(std::istream &in, ComplexNumber &num)
{
    in >> num.a;
    in >> num.b;

    if (num.b == 0)
    {
        in.setstate(std::ios::failbit);
    }

    return in;
}
