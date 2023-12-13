#include "Polinom.h"
#include "MenuDesign.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	system("title Полиномиальный калькулятор");
	system("cls");
	string main_func[] = { "\t\t Выберите желаемую функцию:", 
		"> Сложение полиномов", "> Вычитание полиномов", "> Умножение полиномов", 
		"> Деление полиномов ", "> Умножение на константу", "> Показать активный полином","> Выход из программы" };
	string char_choice[] = { "\t\t Переменная интегрирования/дифференцирования:}", "> x", "> y", "> z" };
	int ch_choice;
	string pol;
	Polinom result;
	pair<Polinom, Polinom> divisionResult;
	string pol_s;
	int menu;
	cout << "Введите полином (Пример: 5x^4y^3+3x^2z^3, мономы разделяются знаками +/-): ";
	cin >> pol;
	Polinom pFirst(pol);
	while (1)
	{
		system("cls");
		menu = menu_mode_clear(main_func, 8);
		system("cls");
		switch (menu)
		{
		case 1:
		{
			cout << "Введите полином (Пример: 5x^4y^3+3x^2z^3, мономы разделяются знаками +/-): ";
			cin >> pol_s;
			Polinom pSecond(pol_s);
			result = pFirst + pSecond;
			pFirst = result;
			cout << "Ответ: ";
			result.print();
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Введите полином (Пример: 5x^4y^3+3x^2z^3, мономы разделяются знаками +/-): ";
			cin >> pol_s;
			Polinom pSecond(pol_s);
			result = pFirst - pSecond;
			pFirst = result;
			cout << "Ответ: ";
			pFirst.print();
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Введите полином (Пример: 5x^4y^3+3x^2z^3, мономы разделяются знаками +/-): ";
			cin >> pol_s;
			Polinom pSecond(pol_s);
			result = pFirst * pSecond;
			pFirst = result;
			cout << "Ответ: ";
			pFirst.print();
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Введите полином (Пример: 5x^4y^3+3x^2z^3, мономы разделяются знаками +/-): ";
			cin >> pol_s;
			Polinom pSecond(pol_s);
			divisionResult = pFirst.divide(pSecond);
			pFirst = divisionResult.first;
			cout << "Частное: ";
			divisionResult.first.print();
			cout << "Остаток: ";
			divisionResult.second.print();
			system("pause");
			break;
		}
		case 5:
		{
			cout << "Введите константу (тип int): ";
			cin >> ch_choice;
			result = pFirst.multiplyByConstant(ch_choice);
			pFirst = result;
			cout << "Ответ: ";
			pFirst.print();
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Активный полином: ";
			pFirst.print();
			system("pause");
			break;
		}
		case 7:
		{
			exit_prog();
			break;
		}
		}
	}

	return 0;
}