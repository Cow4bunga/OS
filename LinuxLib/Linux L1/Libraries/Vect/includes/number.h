#ifndef NUM_NUMBER_H
#define NUM_NUMBER_H
#pragma once
#include<math.h>

class Number {
public:
    double num;
    Number();
    Number(double n);

    //...
    //functions & operators

    static Number add(Number a, Number b);
    static Number subtract(Number a, Number b);
    static Number multiply(Number a, Number b);
    static Number divide(Number a, Number b);

    static Number asinNum(Number n);
    static Number sqrtNum(Number n);

    static Number create(double n);

    Number operator+(const Number& n1);
    Number operator-(const Number& n1);
    Number operator*(const Number& n1);
    Number operator/(const Number& n1);

    bool operator==(const Number& n1);
    bool operator!=(const Number& n1);
};

const Number zero(0);
const Number one(1);
#endif //NUM_NUMBER_H
