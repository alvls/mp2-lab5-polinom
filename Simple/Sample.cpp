#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
#include "List.h"
#include "Polinom.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER '\r'

int choice_in_menu(vector <string> list_for_choice)
{
	int selected = 1;
	char c;
	int i;

	do
	{
		std::cout << list_for_choice[0] << endl;
		for (i = 1; i < __min(list_for_choice.size(), 10); i++)
		{
			if (i == selected)
				std::cout << " > ";
			else std::cout << "   ";
			std::cout << i << ".  " << list_for_choice[i] << endl;
		}
		for (; i < list_for_choice.size(); i++)
		{
			if (i == selected)
				std::cout << " > ";
			else std::cout << "   ";
			std::cout << i << ". " << list_for_choice[i] << endl;
		}
		switch ((c = _getch()))
		{
		case KEY_UP:
			if (selected > 1)
				selected--;
			break;
		case KEY_DOWN:
			if (selected < list_for_choice.size() - 1)
				selected++;
			break;
		default: break;
		}
		system("cls");
	} while (c != KEY_ENTER);
	return(selected);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	vector<string> menu = { "Выберите действие:", "Сложить с новым полиномом", "Умножить на новый полином",
		"Интегрировать полином", "Дифференциировать полином", "Вычислить полином", "Выход" };
	bool flag = true;
	string expression;
	int deg;
	vector<string> v;
	double value;
	map<string, double> values;
	cout << "Введите полином (например, 2x^2+4x^3y^2): ";
	cin >> expression;
	cout << "Введите максимальную степень переменной в полиноме (от 0 до 50): ";
	cin >> deg;
	Polinom p1(deg, "0");
	try
	{
		Polinom p(deg, expression);

		while (flag)
		{
			system("cls");
			try
			{
				switch (choice_in_menu(menu))
				{
				case 1:
					cin.clear();
					system("cls");
					cout << "Введите полином (например, 2x^2+4x^3y^2): ";
					cin >> expression;
					cout << "Исходное выражение: " << p.ToString() << endl;
					p1 = Polinom(deg, expression);
					p += p1;
					cout << "Результат: " << p.ToString() << endl;
					system("pause");
					break;
				case 2:
					cin.clear();
					system("cls");
					cout << "Введите полином (например, 2x^2+4x^3y^2): ";
					cin >> expression;
					cout << "Исходное выражение: " << p.ToString() << endl;
					p1 = Polinom(deg, expression);
					p *= p1;
					cout << "Результат: " << p.ToString() << endl;
					system("pause");
					break;
				case 3:
					cin.clear();
					system("cls");
					v = p.GetAllVariables();
					expression = p.ToString();
					v.insert(v.begin(), "Выберите переменную:");
					system("cls");
					p = p.Integration(v[choice_in_menu(v)]);
					cout << "Исходное выражение: " << expression << endl;
					cout << "Результат: " << p.ToString() << endl;
					system("pause");
					break;
				case 4:
					cin.clear();
					system("cls");
					v = p.GetAllVariables();
					expression = p.ToString();
					v.insert(v.begin(), "Выберите переменную:");
					system("cls");
					p = p.Differentiation(v[choice_in_menu(v)]);
					cout << "Исходное выражение: " << expression << endl;
					cout << "Результат: " << p.ToString() << endl;
					system("pause");
					break;
				case 5:
					system("cls");
					v = p.GetAllVariables();
					values.clear();
					for (int i = 0; i < v.size(); i++)
					{
						cout << "ведите значение переменной " << v[i] << ": ";
						cin >> value;
						values.emplace(v[i], value);
					}
					cout << "Исходное выражение: " << p.ToString() << endl;
					cout << "Результат: " << p.Calculation(values) << endl;
					system("pause");
					break;
				default:
					flag = false;
					break;
				}
			}
			catch (const char* message)
			{
				cout << endl << message << endl;
			}
		}
	}
	catch (const char* message)
	{
		cout << endl << message << endl;
		return 0;
	}

	return 0;
}