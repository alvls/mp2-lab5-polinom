#pragma once
#include "myList.h"

class Polynom
{
	myList<Monom> poly;
public:
	Polynom() {}
	Node<Monom>* getPolyFrontNode();
	void parseAndAddMonoms(const string input);
	void printPolynom();
	void castMonom();
	void addPolynom(Polynom& p);
	void multiplyPolynom(Polynom& p);
	double calcPolynom(double x, double y, double z);
};