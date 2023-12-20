#include "Polinom.h"
#include "Design.h"
#define SIZE 8

enum KEYS {
   UP = 72, DOWN = 80, ENTER = 13, LEFT = 75
};

enum  Menu {
   show_polynomial = 0, add_polynomials = 1, subtract_polynomials = 2, multiply_polynomials = 3, divide_polynomials = 4, multiply_polynomial_by_constant = 5, calculating_polynomial = 6, EXIT = 7
};

char Menu[8][50] = {
   "Показать полином",
   "Сложить полиномы",
   "Вычесть полиномы",
   "Перемножить полиномы",
   "Разделить полиномы",
   "Перемножить полином с константой",
   "Вычислить полином",
   "Выход"
};
int active_menu = 0;

int main()
{
   setlocale(LC_ALL, "Russian");
   system("chcp 1251");
   system("title Полиномиальный калькулятор");
   SMALL_RECT window;
   COORD buf;
   getwindow(&window, &buf);

   int variable_x;
   char ch;

   int constant = 1;
   double x, y, z = 1.0;
   double c_res = 0.0;
   string polinom;
   Polinom res;
   pair<Polinom, Polinom> resDivision;
   string polinom_2;

   clrscr();
   variable_x = (window.Left + window.Right) / 30;
   textcolor(MAGENTA);
   gotoxy(variable_x + 25, wherey() + 5);
   cout << "Добро пожаловать в программу, которая работает c \"Полиномами\"" << endl;
   gotoxy(variable_x + 5, wherey() + 3);
   cout << "Необходимо ввести полином (Мономы разделяются знаками + или -, пример: 2x^3y^3+3x^2): ";
   cin >> polinom;
   Polinom pFirst(polinom);
   gotoxy(variable_x + 35, wherey() + 2);
   Polinom pSecond;

   textcolor(MAGENTA);
   system("cls");

   while (1) {
      hidecursor();
      system("cls");
      for (int i = 0; i < SIZE; i++) {
         if (i == active_menu)
            textcolor(GREEN);
         else
            textcolor(YELLOW);
         cout << Menu[i] << endl;
      }
      ch = _getch();
      if (ch == -32)
         ch = _getch();

      switch (ch)
      {
      case UP:
         if (active_menu > 0)
            active_menu--;
         break;
      case DOWN:
         if (active_menu < SIZE - 1)
            active_menu++;
         break;
      case ENTER:
         switch (active_menu)
         {
         case show_polynomial:
            system("cls");
            cout << "Активный полином: ";
            pFirst.Display();
            system("pause");
            break;

         case add_polynomials:
            system("cls");
            cout << "Необходимо ввести полином (Мономы разделяются знаками + или -, пример: 2x^3y^3+3x^2): ";
            cin >> polinom_2;
            pSecond = Polinom(polinom_2);
            res = pFirst + pSecond;
            pFirst = res;
            cout << "Ответ: ";
            res.Display();
            system("pause");
            break;

         case subtract_polynomials:
            system("cls");
            cout << "Необходимо ввести полином (Мономы разделяются знаками + или -, пример: 2x^3y^3+3x^2): ";
            cin >> polinom_2;
            pSecond = Polinom(polinom_2);
            res = pFirst - pSecond;
            pFirst = res;
            cout << "Ответ: ";
            res.Display();
            system("pause");
            break;

         case multiply_polynomials:
            system("cls");
            cout << "Необходимо ввести полином (Мономы разделяются знаками + или -, пример: 2x^3y^3+3x^2): ";
            cin >> polinom_2;
            pSecond = Polinom(polinom_2);
            res = pFirst * pSecond;
            pFirst = res;
            cout << "Ответ: ";
            res.Display();
            system("pause");
            break;

         case divide_polynomials:
            system("cls");
            cout << "Необходимо ввести полином (Мономы разделяются знаками + или -, пример: 2x^3y^3+3x^2): ";
            cin >> polinom_2;
            pSecond = Polinom(polinom_2);
            resDivision = pFirst.Divide(pSecond);
            pFirst = resDivision.first;
            cout << "Частное: ";
            resDivision.first.Display();
            cout << "Остаток: ";
            resDivision.second.Display();
            system("pause");
            break;

         case multiply_polynomial_by_constant:
            system("cls");
            cout << "Введите константу(целого типа): ";
            cin >> constant;
            res = pFirst.MultiplyByConst(constant);
            pFirst = res;
            cout << "Ответ: ";
            pFirst.Display();
            system("pause");
            break;

         case calculating_polynomial:
            system("cls");
            cout << "Введите значение x: ";
            cin >> x;
            cout << "Введите значение y: ";
            cin >> y;
            cout << "Введите значение z: ";
            cin >> z;
            c_res = pFirst.Сalculation(x, y, z);
            cout << "Ответ: " << c_res << endl;
            system("pause");
            break;

         case EXIT:
            exit(0);
            break;
         }
      }
   }
   return 0;
}