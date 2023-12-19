#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <regex>
#include "Monom.h"
#include "TSinglyList.h"

class Polinom {
private:
	TSinglyList<Monom> monoms;

public:
	Polinom() {}
	Polinom(const string& polinomStr);
	Polinom(const Polinom& other);
	bool isEmpty();

	void addMonom(const Monom& monom);
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


#endif __POLINOM_H__
