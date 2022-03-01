#include "library.h"

Number::Number() :num(0)
{
}

Number::Number(double n) : num(n)
{
}

Number Number::create(double n)
{
    return Number(n);
}

Number Number::operator+(const Number& n1)
{
    return Number(this->num + n1.num);
}

Number Number::operator-(const Number& n1)
{
    return Number(this->num - n1.num);
}

Number Number::operator*(const Number& n1)
{
    return Number(this->num * n1.num);
}

Number Number::operator/(const Number& n1)
{
    return Number(this->num / n1.num);
}

bool Number::operator==(const Number& n1)
{
    return this->num == n1.num;
}

bool Number::operator!=(const Number& n1)
{
    return !(operator==(n1));
}