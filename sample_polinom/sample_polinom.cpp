#include <iostream>
#include "list.h"

using namespace std;

int main() {
	Polynom pol1;
	Polynom pol2;
	Polynom res;
	Polynom ress;
	string p1, p2;
	int choice = 0;
	char a;
	cout << "Enter polynomial(For example: -x5z4+2.2y3z4-2x6)" << endl;
	cin >> p1;
	pol1.construct_polynom(p1);
	cout << "Polynom1" << endl;
	pol1.print();

	while (choice != 7) {
		cout << "Select the desired function" << endl;
		cout << "1) Calculate the polynomial at a given point\n 2) Add a polynomial\n 3) Subtract the polynomia\n 4) Multiply polynomial\n 5) Calculate derivative \n 6) Calculate antiderivative\n 7) Exit the program\n" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			double x, y, z;
			cout << "Enter x value" << endl;
			cin >> x;
			cout << "Enter y value" << endl;
			cin >> y;
			cout << "Enter z value" << endl;
			cin >> z;
			cout << pol1.get_val(x, y, z) << endl;;
			break;
		case 2:
			cout << "Enter the second polynomial (For example: -x5z4+2.2y3z4-2x6)" << endl;
			cin >> p2;
			pol2.construct_polynom(p2);
			cout << "Polynom2" << endl;
			pol2.print();
			cout << "Polynom1 + Polynom2" << endl;
			pol1.add(pol2).print();
			break;
		case 3:
			cout << "Enter the second polynomial (For example: -x5z4+2.2y3z4-2x6)" << endl;
			cin >> p2;
			pol2.construct_polynom(p2);
			cout << "Polynom2" << endl;
			pol2.print();
			cout << "Polynom1 - Polynom2" << endl;
			pol1.sub(pol2).print();
			break;
		case 4:
			cout << "Enter the second polynomial (For example: -x5z4+2.2y3z4-2x6)" << endl;
			cin >> p2;
			pol2.construct_polynom(p2);
			cout << "Polynom2" << endl;
			pol2.print();
			cout << "Polynom1 * Polynom2" << endl;
			pol1.mul(pol2).print();
			break;
		case 5:
			cout << "Enter the variable by which to calculate the derivative " << endl;
			cin >> a;
			res = pol1.get_derivative(a);
			cout << "Derivative of Polynom1 " << endl;
			res.print();
			break;
		case 6:
			cout << "Enter the variable by which to calculate the antiderivative" << endl;
			cin >> a;
			ress = pol1.get_antiderivative(a);
			cout << "Antiderivative of Polynom1" << endl;
			ress.print();
			break;
		default:
			break;
		}
	}
	return 0;
}