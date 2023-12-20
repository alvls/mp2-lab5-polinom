#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <vector>
#include <regex>
#include <map>
#include "sorted_list.h"
#include "monom.h"


using namespace std;

class Polinom {

	SortedList<Monom> monoms;
	map<char, double> operands;

public:
	Polinom();
	Polinom(string s);
	Polinom(const Polinom& p);
	void add(const Monom& m);
	double calculate(double x, double y, double z);
	const LinkedList<Monom>& get_monoms() const;
	const map<char, double>& get_operands() const;

	Polinom operator+(const Polinom& p);
	Polinom& operator+=(const Polinom& p);
	Polinom operator-(const Polinom& p);
	Polinom& operator-=(const Polinom& p);
	Polinom operator*(const Polinom& p);
	Polinom& operator*=(const Polinom& p);
	Polinom operator*(const double& k);
	Polinom& operator*=(const double& k); 
	Polinom operator/(const Polinom& p);
	Polinom& operator/=(const Polinom& p);
	friend ostream& operator<<(ostream& os, const Polinom& p);
};





#endif 


