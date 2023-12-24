#ifndef __POLINOM_H__
#define __POLINOM_H__

#include "monom.h"
#include "monomlist.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <regex>

class Polinom 
{
private:
    monomlist<monom> monoms;

public:
    Polinom() {}
    Polinom(const string& polinomStr);
    Polinom(const Polinom& other);
    bool isEmpty();

    void addMonom(const monom& monom);
    void simplify();
    Polinom& operator=(const Polinom& other);
    Polinom operator+(const Polinom& other) const;
    Polinom operator-(const Polinom& other) const;
    Polinom multiplyByConstant(int constant) const;

    Polinom operator*(const Polinom& other) const;
    pair<Polinom, Polinom> divide(const Polinom& divisor) const;
    double evaluate(double x, double y, double z) const;
    void print() const;
};
#endif

