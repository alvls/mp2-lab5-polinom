#ifndef __POLYNOM_H__
#define __POLYNOM_H__

#include "LinkedList.h"
#include "Monom.h"

#include <iostream>
#include <string>

class TPolynom
{
private:
	TLinkedList<TMonom> monoms;

	void transform();

public:
	TPolynom() {};
	TPolynom(const string& polynom);
	TPolynom(const TPolynom& other);

	friend ostream& operator<<(ostream& os, const TPolynom& polynom);

	void add_monom(const TMonom& monom);
	double calculate(double x, double y, double z) const;
	string to_string() const;

	TPolynom& operator=(const TPolynom& other);
	TPolynom operator+(const TPolynom& other) const;
	TPolynom operator-(const TPolynom& other) const;
	TPolynom operator*(double number) const;
	TPolynom operator*(const TPolynom& other) const;

	TPolynom& operator+=(const TPolynom& other);
	TPolynom& operator-=(const TPolynom& other);
	TPolynom& operator*=(double number);
	TPolynom& operator*=(const TPolynom& other);

	bool operator==(const TPolynom& other) const;
	bool operator!=(const TPolynom& other) const;

};


#endif