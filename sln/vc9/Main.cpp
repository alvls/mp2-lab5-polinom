#include <iostream>
#include <string>
#include "Polinom.cpp"
using namespace std;
void main() {
	bool flag = true;
	int ans;
	int x, y, z;
	string polynomial;
	cout << "Enter polinon \n";
	cin >> polynomial;
	Polinom polin(polynomial);
	while (flag)
	{
		cout << "1 - Print polynomial\n";
		cout << "2 - Solve polynomial\n";
		cout << "3 - Bring similar ones in a polynomial\n";
		cout << "4 - Addition of polynomials\n";
		cout << "5 - Multiplication of polynomials\n";
		cout << "6 - Exit\n";
		cin >> ans;
		switch (ans)
		{
		case 1:
			cout << polin.prPolinom() << endl;
			break;
		case 2:
			cout << "Enter x" << endl;
			cin >> x;
			cout << "Enter y" << endl;
			cin >> y;
			cout << "Enter z" << endl;
			cin >> z;
			cout << polin.Calculate(x, y, z) << endl;
			break;
		case 3:
			polin.BringSimular();
			cout << polin.prPolinom();
			break;
		case 4:
			cout << "Enter polinon \n";
			cin >> polynomial;
			polin.aditional(Polinom(polynomial));
			cout << polin.prPolinom();
		case 5:
			cout << "Enter polinon \n";
			cin >> polynomial;
			polin.Multiplication(Polinom(polynomial));
			cout << polin.prPolinom();
		case 6:
			flag = false;
			break;
		default:
			break;
		}
	}
}