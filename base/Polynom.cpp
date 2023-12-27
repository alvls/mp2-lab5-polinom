#include "Polynom.h"

#include <iostream>
#include <stdexcept>

TPolynom::TPolynom(const string& p)
{
	unsigned int idx = 0;
	size_t length = p.length();

	while (idx < length)
	{
		int start_idx = idx;

		if (p[idx] == '-')
		{
			idx++;
		}

		while (idx < length && p[idx] != '+' && p[idx] != '-')
		{
			idx++;
		}

		string monom_str = p.substr(start_idx, idx - start_idx);
		TMonom monom(monom_str);

		if (start_idx > 0 && p[start_idx - 1] == '-')
		{
			monom.coefficient *= -1.0;
		}

		add_monom(monom);

		if (idx < length)
		{
			idx++;
		}
	}
	transform();
}

TPolynom::TPolynom(const TPolynom& other)
{
	monoms = other.monoms;
}

ostream& operator<<(ostream& os, const TPolynom& polynom)
{
	//os << "The result of polynomial calculation: " << polynom.to_string() << endl;
	os << polynom.to_string() << endl;
	return os;
}

void TPolynom::transform()
{
	int idx = 0;
	while (idx < monoms.size())
	{
		if (monoms[idx].coefficient == 0.0)
		{
			monoms.remove(idx);
		}
		else
		{
			idx++;
		}
	}
}

void TPolynom::add_monom(const TMonom& monom)
{
	if (monom.coefficient == 0.0)
	{
		return;
	}

	for (auto& current_monom : monoms)
	{
		if (current_monom.equals(monom))
		{
			current_monom.coefficient += monom.coefficient;
			return;
		}
	}
	monoms.push_back(monom);
}

double TPolynom::calculate(double x, double y, double z) const
{
	double res = 0.0;

	for (int i = 0; i < monoms.size(); i++)
	{
		res += monoms[i].calculate(x, y, z);
	}

	return res;
}

string TPolynom::to_string() const
{
	if (monoms.is_empty())
	{
		return "Polynom is empty!\n";
	}

	string res;

	for (int i = 0; i < monoms.size(); i++)
	{
		res += monoms[i].to_string();

		if (i < monoms.size() - 1)
		{
			if (monoms[i + 1].coefficient >= 0.0)
			{
				res += " + ";
			}
			else
			{
				res += " ";
			}
		}
	}

	return res;
}

TPolynom& TPolynom::operator=(const TPolynom& other)
{
	if (this != &other)
	{
		monoms = other.monoms;
	}
	return *this;
}

TPolynom TPolynom::operator+(const TPolynom& other) const
{
	TPolynom res(*this);
	res += other;

	return res;
}

TPolynom& TPolynom::operator+=(const TPolynom& other)
{
	for (const TMonom& monom : other.monoms)
	{
		add_monom(monom);
	}
	transform();

	return *this;
}

TPolynom TPolynom::operator-(const TPolynom& other) const
{
	TPolynom res(*this);
	res -= other;

	return res;
}

TPolynom& TPolynom::operator-=(const TPolynom& other)
{
	TPolynom inversion = other;
	inversion *= -1;
	(*this) += inversion;

	return *this;
}

TPolynom TPolynom::operator*(double number) const
{
	TPolynom res(*this);
	res *= number;

	return res;
}

TPolynom TPolynom::operator*(const TPolynom& other) const
{
	TPolynom res;

	for (const TMonom& multiplier1 : monoms)
	{
		for (const TMonom& multiplier2 : other.monoms)
		{
			TMonom product = multiplier1 * multiplier2;
			res.add_monom(product);
		}
	}

	res.transform();
	return res;
}

TPolynom& TPolynom::operator*=(double number)
{
	if (number == 0.0)
	{
		monoms = TLinkedList<TMonom>();
	}

	for (TMonom& monom : monoms)
	{
		monom.coefficient *= number;
	}

	return *this;
}

TPolynom& TPolynom::operator*=(const TPolynom& other)
{
	TPolynom product = (*this) * other;
	(*this) = product;

	return *this;
}


bool TPolynom::operator==(const TPolynom& other) const
{
	return monoms == other.monoms;
}

bool TPolynom::operator!=(const TPolynom& other) const
{
	return !(*this == other);
}