#ifndef __MONOM_H__
#define __MONOM_H__

#include <iostream>
#include <sstream>

using namespace std;

struct TMonom
{
	static const unsigned int MIN_DEGREE = 0;
	static const unsigned int MAX_DEGREE = 9;

	double coefficient = 1.0;
	unsigned int degree = 0; // свёрнутая степень монома

	TMonom(double _coef = 0.0, unsigned int _deg = 0);
	TMonom(const string& str);

	friend ostream& operator<<(ostream& os, const TMonom& monom);

	bool operator<(const TMonom& other) const;
	bool operator>(const TMonom& other) const;
	bool operator==(const TMonom& other) const;
	bool operator!=(const TMonom& other) const;

	TMonom operator*(const TMonom& other) const;

	double calculate(double x, double y, double z) const;
	string to_string() const;
	bool equals(const TMonom& other) const;
};

#endif