#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

class Monom
{
	int key;
	double koefficient;
	map<string, int> variables;
public:
	Monom(double _key, double _koeff, map<string, int> _variables);
	Monom(const Monom&) = default;
	Monom& operator=(const Monom& m);
	bool operator<(const Monom& new_monom);
	bool operator>(const Monom& new_monom);
	bool operator==(const Monom& new_monom);
	void operator+=(const Monom& new_monom);
	Monom operator+(const Monom& m);
	void operator*=(int num);
	void operator*=(const Monom& new_monom);
	Monom operator*(const Monom& m);
	Monom Differentiation(int p, string variable);
	Monom Integration(int p, string variable, int degree);
	bool is_empty();
	double Calculation(int p, const map<string, double>& values);
	string ToString(int p);
};
