#include "Monom.h"

bool Monom::operator<(const Monom& other) const {
	return degree < other.degree;
}

bool Monom::operator==(const Monom& other) const {
	return degree == other.degree && abs(coefficient - other.coefficient) < 1e-10; // с некоторой точностью
}

double Monom::evaluate(double x, double y, double z) const {
	int xDeg = degree / 100;
	int yDeg = (degree / 10) % 10;
	int zDeg = degree % 10;
	return coefficient * pow(x, xDeg) * pow(y, yDeg) * pow(z, zDeg);
}

void Monom::print() const {
	int xDeg = degree / 100;
	int yDeg = (degree / 10) % 10;
	int zDeg = degree % 10;

	cout << coefficient;
	if (xDeg > 0) cout << "x^" << xDeg;
	if (yDeg > 0) cout << "y^" << yDeg;
	if (zDeg > 0) cout << "z^" << zDeg;
}