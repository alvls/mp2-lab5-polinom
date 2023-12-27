#include "Monom.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

TMonom::TMonom(const string& str)
{
	if (str.empty())
	{
		throw invalid_argument("Source string is empty!");
	}

	istringstream iss(str);

	const int sign = iss.peek() == '-' ? -1 : 1;
	if (sign == -1)
	{
		iss.ignore();
	}

	if (!(iss >> coefficient))
	{
		iss.clear();
		coefficient = 1.0;
	}
	coefficient *= sign;

	char var;
	unsigned int deg;

	while (iss >> var)
	{
		if (var < 'x' || var > 'z')
		{
			throw invalid_argument("Invalid variables! You have to use lowercase 'x', 'y' and 'z'");
		}

		if (iss.peek() == '^')
		{
			iss.ignore();
			iss >> deg;

			if (deg < MIN_DEGREE || deg > MAX_DEGREE)
			{
				throw invalid_argument("Degree must be from 0 to 9");
			}
		}
		else
		{
			deg = 1;
		}

		degree += deg * pow(10, (2 - (var - 'x')));
	}
}

TMonom::TMonom(double _coef, unsigned int _deg)
{
	if (_deg < 0 || _deg > 999)
	{
		throw invalid_argument("Degree must be from 0 to 999");
	}
	coefficient = _coef;
	degree = _deg;
}

ostream& operator<<(ostream& os, const TMonom& monom)
{
	os << monom.to_string() << endl;
	return os;
}

bool TMonom::operator<(const TMonom& other) const
{
	if (equals(other))
		return coefficient < other.coefficient;
	else
		return degree < other.degree;
}

bool TMonom::operator>(const TMonom& other) const
{
	if (equals(other))
		return coefficient > other.coefficient;
	else
		return degree > other.degree;
}

bool TMonom::operator==(const TMonom& other) const
{
	return degree == other.degree && coefficient == other.coefficient;
}

bool TMonom::operator!=(const TMonom& other) const
{
	return !(*this == other);
}

TMonom TMonom::operator*(const TMonom& other) const
{
	unsigned int degX = (degree / 100) % 10;
	unsigned int degY = (degree / 10) % 10;
	unsigned int degZ = degree % 10;
	unsigned int other_degX = (other.degree / 100) % 10;
	unsigned int other_degY = (other.degree / 10) % 10;
	unsigned int other_degZ = other.degree % 10;

	if (degX + other_degX > MAX_DEGREE || degY + other_degY > MAX_DEGREE
		|| degZ + other_degZ > MAX_DEGREE)
	{
		throw invalid_argument("The product of monomials multiplication must have degree from min to max degree value");
	}

	return TMonom(coefficient * other.coefficient, degree + other.degree);
}

double TMonom::calculate(double x, double y, double z) const
{
	unsigned int alpha = (degree / 100) % 10; // degX
	unsigned int beta = (degree / 10) % 10; // degY
	unsigned int gamma = degree % 10;       // degZ

	return coefficient * pow(x, alpha) * pow(y, beta) * pow(z, gamma);
}

string TMonom::to_string() const
{
	ostringstream oss;

	if (coefficient < 0.0)
	{
		oss << "- ";
	}
	if (abs(coefficient) != 1.0)
	{
		oss << abs(coefficient);
	}

	int degX = degree / 100;
	int degY = (degree / 10) % 10;
	int degZ = degree % 10;

	if (degX == 1)
		oss << "x";
	else if (degX > 0)
		oss << "x^" << degX;

	if (degY == 1)
		oss << "y";
	else if (degY > 0)
		oss << "y^" << degY;

	if (degZ == 1)
		oss << "z";
	else if (degZ > 0)
		oss << "z^" << degZ;

	return oss.str();
}

bool TMonom::equals(const TMonom& other) const
{
	return degree == other.degree;
}