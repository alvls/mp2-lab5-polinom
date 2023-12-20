#include "monom.h"
#include <cmath>
#include <sstream>
#include <stdexcept>


Monom::Monom(double coef, size_t deg) 
{
	if (deg > 999)
	{
		throw std::invalid_argument("Превышена максимальная степень переменной(-ых)");
	}
	coefficient = coef;
	degree = deg;
}

Monom::Monom(const string& monomString) 
{
	size_t xDeg = 0, yDeg = 0, zDeg = 0;

	istringstream iss(monomString);
	bool isNegative = false;
	if (!iss.eof() && iss.peek() == '-') 
	{
		isNegative = true;
		iss.ignore();  
	}
	if (!(iss >> coefficient)) 
	{
		coefficient = 1.0;
		iss.clear();  
	}	
	if (isNegative) 
	{
		coefficient *= -1.0;
	}

	char variable;
	int power;
	while (iss >> variable) 
	{
		if (variable == 'x' || variable == 'y' || variable == 'z') 
		{
			
			if (iss.peek() == '^') {
				iss.ignore();
				if (iss >> power && power >= 0) 
				{
				   
					switch (variable) {
					case 'x':
						xDeg = power;
						break;
					case 'y':
						yDeg = power;
						break;
					case 'z':
						zDeg = power;
						break;
					}
				}
				else 
				{
					throw invalid_argument("Некорректная степень в строке монома");
				}
			}
			else 
			{
				
				switch (variable) 
				{
				case 'x':
					xDeg = 1;
					break;
				case 'y':
					yDeg = 1;
					break;
				case 'z':
					zDeg = 1;
					break;
				}
			}
		}
		else 
		{
			throw invalid_argument("Некорректная степень в строке монома");
		}
	}
	if (xDeg > MAX_DEGREE || yDeg > MAX_DEGREE || zDeg > MAX_DEGREE)
	{
		throw invalid_argument("Превышена максимальная степень переменной(-ых)");
	}
	degree = xDeg * 100 + yDeg * 10 + zDeg;
}

bool Monom::operator<(const Monom& other) const 
{
	return degree < other.degree;
}

bool Monom::operator>(const Monom& other) const 
{
	return degree > other.degree;
}

bool Monom::operator==(const Monom& other) const 
{
	return degree == other.degree && coefficient == other.coefficient;
}

bool Monom::operator!=(const Monom& other) const 
{
	return !(*this == other);
}

double Monom::calculate(double x, double y, double z) const 
{
	size_t xPower = (degree / 100) % 10;
	size_t yPower = (degree / 10) % 10;
	size_t zPower = degree % 10;

	return coefficient * pow(x, xPower) * pow(y, yPower) * pow(z, zPower);
}

string Monom::toString() const 
{
	ostringstream oss;

	if (coefficient < 0)
	{
		oss << "- ";
	}
	if (abs(coefficient) != 1)
	{
		oss << abs(coefficient);
	}

	int xDeg = degree / 100;
	int yDeg = (degree / 10) % 10;
	int zDeg = degree % 10;

	if (xDeg == 1) oss << "x"; else if (xDeg > 0) oss << "x^" << xDeg;
	if (yDeg == 1) oss << "y"; else if (yDeg > 0) oss << "y^" << yDeg;
	if (zDeg == 1) oss << "z"; else if (zDeg > 0) oss << "z^" << zDeg;

	return oss.str();
}


Monom Monom::operator*(const Monom& other) const 
{
	size_t xDeg = (degree / 100) % 10;
	size_t yDeg = (degree / 10) % 10;
	size_t zDeg = degree % 10;

	size_t other_xDeg = (other.degree / 100) % 10;
	size_t other_yDeg = (other.degree / 10) % 10;
	size_t other_zDeg = other.degree % 10;

	if (xDeg + other_xDeg > MAX_DEGREE || yDeg + other_yDeg > MAX_DEGREE || zDeg + other_zDeg > MAX_DEGREE) 
	{
		throw invalid_argument("Превышена максимальная степень переменной(-ых) при умножении");
	}

	return Monom(coefficient * other.coefficient, degree + other.degree);
}


