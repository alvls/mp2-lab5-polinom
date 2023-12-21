#include <iostream>
#include <fstream>
#include "List.h"
#include "Polinom.h"

using namespace std;

int main()
{
	string expression;
	int deg;
	cin >> expression;
	cin >> deg;
	Polinom p(deg, expression);

	cout << p.ToString() << endl;
	Polinom p1(deg, "2x^2+13y^2");
	Polinom p10(deg, "0");
	p10 = p + p1;
	cout << p10.ToString() << endl;
	p10 = p * p1;
	cout << p10.ToString() << endl;
	p += p1;
	cout << p.ToString() << endl;
	Polinom p2(deg, "2x^2+13y^2");
	p *= p2;
	cout << p.ToString() << endl;
	Polinom p3(p.Differentiation("x"));
	Polinom p4(p.Differentiation("y"));
	cout << p3.ToString() << endl;
	cout << p4.ToString() << endl;
	Polinom p5(p3.Integration("x"));
	Polinom p6(p4.Integration("y"));
	cout << p5.ToString() << endl;
	cout << p6.ToString() << endl;
	map<string, double> values;
	values.emplace("x", 1);
	values.emplace("y", 2);
	cout << p6.Calculation(values) << endl;
	return 0;
}