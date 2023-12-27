#include <iostream>
#include "Polynom.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	system("title Аналитические преобразования полиномов от трёх переменных");

	string str1;

	cout << "Введите полином от трёх переменных (x, y, z): ";
	getline(cin, str1);

	shared_ptr<TPolynom> polynom;
	try
	{
		polynom = make_shared<TPolynom>(str1);
	}
	catch (const exception& e)
	{
		cerr << "Ошибка при создании полинома: " << e.what() << endl;
		return EXIT_FAILURE;
	}

	TPolynom p1(str1);

	char op;
	cout << "Выберите операцию (+, -, *, =): ";
	cin >> op;

	switch (op)
	{
	case '+':
	{
		string summand;
		cout << "Введите второе слагаемое: ";
		cin >> summand;
		TPolynom p2(summand);
		p1 += p2;
		break;
	}
	case '-':
	{
		string subtrahend;
		cout << "Введите второе слагаемое: ";
		cin >> subtrahend;
		TPolynom p2(subtrahend);
		p1 -= p2;
		break;
	}
	case '*':
	{
		string multiplier;
		cout << "Введите второй множитель (число или другой полином): ";
		cin >> multiplier;
		TPolynom p2(multiplier);
		p1 *= p2;
		break;
	}
	case '=':
	{
		double x, y, z;
		double res = 0.0;
		cout << "Введите значения переменных 'x', 'y', 'z' для расчёта в точке: ";
		cin >> x >> y >> z;
		res += p1.calculate(x, y, z);
		cout << "Рассчитанное значение: " << res;
		exit(0);
	}
	default:
		break;
	}

	cout << "Рассчитанное значение: " << p1;


	return EXIT_SUCCESS;
}