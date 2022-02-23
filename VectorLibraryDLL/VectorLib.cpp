#include "pch.h"
#include "VectorLib.h"

Vector::Vector() : x(zero), y(zero)
{
}

Vector::Vector(Number x1, Number y1) : x(x1), y(y1)
{
}

Number Vector::getRadius()
{
	return Number(Number::sqrtNum(x * x + y * y));
}

Number Vector::getAngle()
{
	Number radius = Vector::getRadius();
	if (radius == zero)
		return zero;
	else return Number::asinNum(y / radius);
}

Number Vector::getX()
{
	return Number(x.num);
}

Number Vector::getY()
{
	return Number(y.num);
}

Vector Vector::addVector(Vector v1, Vector v2)
{
	return Vector(v1.x + v2.x, v1.y + v2.y);
}

Vector Vector::operator+(Vector& v)
{
	return Vector(v.x+this->x,v.y+this->y);
}
