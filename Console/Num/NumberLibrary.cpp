#include "NumberLibrary.h"

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

Number Number::add(Number a, Number b)
{
	return Number(a.num + b.num);
}

Number Number::subtract(Number a, Number b)
{
	return Number(a.num - b.num);
}

Number Number::multiply(Number a, Number b)
{
	return Number(a.num * b.num);
}

Number Number::divide(Number a, Number b)
{
	return Number(a.num / b.num);
}

Number Number::asinNum(Number n)
{
	return Number(asin(n.num));
}

Number Number::sqrtNum(Number n)
{
	return Number(sqrt(n.num));
}