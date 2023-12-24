#ifndef MONOMIAL_H
#define MONOMIAL_H

#include "math.h"
#include <vector>
#include <iostream>
using namespace std;
struct monom
{
	unsigned int sumdeg;
	double coef;
	int getXDegree() const;
	int getYDegree() const;
	int getZDegree() const;
	bool operator<(const monom& other) const;
	bool operator==(const monom& other) const;
	monom(double coef_ = 0.0, unsigned int sumgeg_ = 0) : coef(coef_), sumdeg(sumgeg_) {}
	double evaluate(double x, double y, double z) const;
	void print() const;
	static monom parseMonom(const std::string& monomStr);

};
#endif 