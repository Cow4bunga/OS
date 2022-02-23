#pragma once
#include "NumberLibrary.h"

#ifdef VECTORLIBRARY_EXPORTS
#define VECTORLIBRARY_API _declspec(dllexport)
#else 
#define VECTORLIBRARY_API _declspec(dllimport)
#endif

extern "C" class VECTORLIBRARY_API Vector {
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