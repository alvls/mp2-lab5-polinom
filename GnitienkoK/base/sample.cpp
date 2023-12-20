#include <iostream>
#include <string>
#include "Polynom.h"
#include "menu.h"
#include <locale>

void main() {
	setlocale(LC_ALL, "rus");
	char* menu1[3] = { (char*)"Вычислить полином в точке", 
		(char*)"Умножить полином на число или полином", 
		(char*)"Сложить два полинома" };
	int selector = 0;
	string str;
	while (selector != KEY_EXIT) {
		system("cls");
		selector = menu(menu1, 3);
		switch (selector) {
		case 0: {
			system("cls");
			cout << "Enter the first polynom ";
			cin >> str;
			double x, y, z;
			Polynom p;
			p.parseAndAddMonoms(str);
			cout << endl << "1st polynom: "; p.printPolynom(); cout << endl;
			cout << "Enter x, y, z for calculation polynom: ";
			cin >> x;
			cin >> y;
			cin >> z;
			cout << "result = " << p.calcPolynom(x, y, z) << endl;;
			system("pause");
			break;
		}
		case 1: {
			system("cls");
			cout << "Enter the first polynom ";
			cin >> str;
			double x, y, z;
			Polynom p;
			p.parseAndAddMonoms(str);
			cout << endl << "1st polynom: "; p.printPolynom(); cout << endl;
			cout << "Enter the second polynom ";
			cin >> str;
			Polynom p2;
			p2.parseAndAddMonoms(str);
			cout << endl << "2nd polynom: "; p2.printPolynom();
			p.multiplyPolynom(p2);
			cout << "p1 * p2: "; p.printPolynom(); cout << endl; 
			system("pause");
			break;
		}
		case 2:{
			system("cls");
			cout << "Enter the first polynom ";
			cin >> str;
			double x, y, z;
			Polynom p;
			p.parseAndAddMonoms(str);
			cout << endl << "1st polynom: "; p.printPolynom(); cout << endl;
			cout << "Enter the second polynom "; cin >> str;
			Polynom p2;
			p2.parseAndAddMonoms(str);
			cout << endl << "2nd polynom: "; p2.printPolynom();
			p2.addPolynom(p);
			cout << "p1 + p2: "; p2.printPolynom(); cout << endl;
			system("pause");
			break;
		}
		}
	}
}