#include "Monom.h"

Monom::Monom(double _key, double _koeff, map<string, int> _variables) : key(_key), koefficient(_koeff), variables(_variables) {}

Monom& Monom::operator=(const Monom& m)
{
	if (!(*this == m))
	{
		this->key = m.key;
		this->koefficient = m.koefficient;
		this->variables = m.variables;
	}
	return *this;
}

bool Monom::operator<(const Monom& new_monom)
{
	return (this->key < new_monom.key);
}

bool Monom::operator>(const Monom& new_monom)
{
	return (this->key > new_monom.key);
}

bool Monom::operator==(const Monom& new_monom)
{
	return (this->key == new_monom.key);
}

void Monom::operator+=(const Monom& new_monom)
{
	if (!(*this == new_monom))
		throw - 1;
	this->koefficient += new_monom.koefficient;
}

void Monom::operator*=(int num)
{
	this->koefficient *= num;
}

void Monom::operator*=(const Monom& new_monom)
{
	this->koefficient *= new_monom.koefficient;
	this->key += new_monom.key;
	this->variables.insert(new_monom.variables.begin(), new_monom.variables.end());
}

Monom Monom::Differentiation(int p, string variable)
{
	if (this->variables.count(variable) == 0)
	{
		this->koefficient = 0;
		return *this;
	}
	int v = this->key % (int)pow(p, this->variables[variable] + 1) / pow(p, this->variables[variable]);
	this->key -= pow(p, this->variables[variable]);
	this->koefficient *= v;
	if (v == 1)
		this->variables.erase(variable);
	return *this;
}

Monom Monom::Integration(int p, string variable, int degree)
{
	if (this->variables.count(variable) == 0)
		this->variables.emplace(variable, degree);
	int v = this->key % (int)pow(p, degree + 1) / pow(p, degree) + 1;
	this->key += pow(p, degree);
	this->koefficient /= v;
	return *this;
}

bool Monom::is_empty()
{
	return (this->koefficient == 0);
}

double Monom::Calculation(int p, const map<string, double>& values)
{
	double res = this->koefficient;
	for (auto it = this->variables.begin(); it != this->variables.end(); it++)
	{
		auto ss = values.find(it->first);
		res *= pow(ss->second, ((int)(this->key % (int)pow(p, it->second + 1) / pow(p, it->second))));
	}
	return res;
}

string Monom::ToString(int p)
{
	string str = "";
	if (this->koefficient > 0)
		str += '+';
	if (this->koefficient == (int)this->koefficient)
		str += to_string((int)this->koefficient);
	else
		str += to_string(this->koefficient);
	for (const auto& s : this->variables)
	{
		str += s.first;
		str += "^" + to_string((int)(this->key % (int)pow(p, s.second + 1) / pow(p, s.second)));
	}
	return str;
}

Monom Monom::operator+(const Monom& m)
{
	Monom m1(*this);
	m1 += m;
	return m1;
}

Monom Monom::operator*(const Monom& m)
{
	Monom m1(*this);
	m1 *= m;
	return m1;
}
