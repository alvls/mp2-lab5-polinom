#ifndef __Polynom_H__
#define __Polynom_H__

#include <vector>
#include <regex>
#include <map>
#include "sorted_list.h"
#include "monom.h"
#include <functional>


using namespace std;

class Polynom {

	SortedList<Monom> monoms;
	map<char, double> operands;
	static map<string, function<Polynom(const Polynom&, const Polynom&)> > binary_operations;
	static map<string, function<Polynom(const Polynom&)> > unary_operations;
	void parse_polynom(const string& str);
	string erase_spaces(const string& str);
	
public:
	Polynom();
	Polynom(const string& str);
	Polynom(const Polynom& p);
	void add(const Monom& m);
	double calculate(double x, double y, double z);
	Polynom differential(char variable) const ;
	Polynom primitive(char variable) const;
	const LinkedList<Monom>& get_monoms() const;
	const map<char, double>& get_operands() const;

	Polynom operator+(const Polynom& p)const;
	Polynom& operator+=(const Polynom& p);
	Polynom operator-(const Polynom& p)const;
	Polynom& operator-=(const Polynom& p);
	Polynom operator+(const Monom& m)const;
	Polynom& operator+=(const Monom& m);
	Polynom operator-(const Monom& m)const;
	Polynom& operator-=(const Monom& m);
	Polynom operator*(const Polynom& p)const;
	Polynom& operator*=(const Polynom& p);
	Polynom operator/(const Monom& p)const;
	Polynom& operator/=(const Monom& p);
	Polynom operator*(const Monom& m)const;
	Polynom& operator*=(const Monom& m);
	Polynom operator*(const double& k)const;
	Polynom& operator*=(const double& k); 
	Polynom operator/(const Polynom& p)const;
	//Polynom& operator/=(const Polynom& p);
	bool operator==(const Polynom& p)const;
	bool operator!=(const Polynom& p)const;
	bool operator>(const Polynom& p)const;
	bool operator>=(const Polynom& p)const;
	bool operator<(const Polynom& p)const;
	bool operator<=(const Polynom& p)const;
	friend ostream& operator<<(ostream& os, const Polynom& p);
};





#endif 


