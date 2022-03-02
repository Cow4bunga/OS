#ifndef VECT_VECTOR_H
#define VECT_VECTOR_H

#pragma once
#include "number.h"

class Vector {
public:
Vector();
Vector(Number x1, Number y1);

Number getRadius();
Number getAngle();
Number getX();
Number getY();

Vector addVector(Vector v1, Vector v2);
//alternative
Vector operator+(Vector& v);
private:
Number x, y;
};

const Vector zeroVector(zero, zero);
const Vector oneVector(one, one);

#endif //VECT_VECTOR_H
