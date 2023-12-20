#include "Polinom.h"


Polinom::Polinom(const string& polinomStr) {
   regex monomPattern(R"(\s*([-+]?\d*\.?\d*)\s*(x(\^\d+)?)?\s*(y(\^\d+)?)?\s*(z(\^\d+)?)?\s*)");

   sregex_iterator monomIteratorBegin(polinomStr.begin(), polinomStr.end(), monomPattern);
   sregex_iterator monomIteratorEnd;

   for (auto it = monomIteratorBegin; it != monomIteratorEnd; ++it) {
      const smatch& match = *it;

      // Пропускаем моном, если он не содержит информации о коэффициенте и степенях переменных
      if (match[1].str().empty() && !match[2].matched && !match[4].matched && !match[6].matched) {
         continue;
      }

      double monomCoefficient = 1.0;
      int monomXDegree = 0;
      int monomYDegree = 0;
      int monomZDegree = 0;

      // Извлекаем информацию о коэффициенте
      if (!match[1].str().empty()) {
         monomCoefficient = stod(match[1].str());
      }

      // Извлекаем информацию о степени x
      if (!match[3].str().empty()) {
         monomXDegree = stoi(match[3].str().substr(1));
      }
      else if (match[2].matched) {
         monomXDegree = 1;
      }

      // Извлекаем информацию о степени y
      if (!match[5].str().empty()) {
         monomYDegree = stoi(match[5].str().substr(1));
      }
      else if (match[4].matched) {
         monomYDegree = 1;
      }

      // Извлекаем информацию о степени z
      if (!match[7].str().empty()) {
         monomZDegree = stoi(match[7].str().substr(1));
      }
      else if (match[6].matched) {
         monomZDegree = 1;
      }

      unsigned int monomTotalDegree = monomXDegree * 100 + monomYDegree * 10 + monomZDegree;

      AddMonom(Monom(monomCoefficient, monomTotalDegree));
   }

   // Выполняем упрощение полинома после добавления всех мономов
   CombineLikeTerms();
}

Polinom::Polinom(const Polinom& other) {
   for (size_t i = 0; i < other.monoms.GetSize(); ++i) {
      AddMonom(other.monoms.GetValueAtPosition(i));
   }
}

Polinom& Polinom::operator=(const Polinom& other) {
   if (this == &other) {
      return *this;
   }

   // Очищаем текущий полином
   monoms.Clear();

   // Копируем мономы из другого полинома
   for (size_t i = 0; i < other.monoms.GetSize(); ++i) {
      AddMonom(other.monoms.GetValueAtPosition(i));
   }

   return *this;
}

void Polinom::AddMonom(const Monom& monom) {
   if (monom.coef != 0) {
      monoms.PushBack(monom);
   }
}

bool Polinom::isEmpty() {
   return monoms.IsEmpty();
}

void Polinom::CombineLikeTerms() {
   // Переносим мономы во временный вектор для упрощения
   vector<Monom> monomVector;
   while (!monoms.IsEmpty()) {
      monomVector.push_back(monoms.GetFront());
      monoms.PopFront();
   }

   // Сортируем мономы в порядке убывания степеней
   sort(monomVector.begin(), monomVector.end(), [](const Monom& a, const Monom& b) { return a.degree > b.degree; });

   // Производим упрощение мономов
   for (size_t i = 0; i < monomVector.size(); i++) {
      if (i < monomVector.size() - 1 && monomVector[i].degree == monomVector[i + 1].degree) {
         monomVector[i + 1].coef += monomVector[i].coef;
         monomVector[i].coef = 0;
      }
   }

   // Удаляем мономы с нулевым коэффициентом
   monomVector.erase(remove_if(monomVector.begin(), monomVector.end(), [](const Monom& m) { return m.coef == 0; }), monomVector.end());

   // Возвращаем упрощенные мономы обратно
   for (const auto& monom : monomVector) {
      monoms.PushBack(monom);
   }
}

Polinom Polinom::operator-(const Polinom& other) const {
   Polinom res = *this;

   for (size_t i = 0; i < other.monoms.GetSize(); ++i) {
      res.AddMonom(Monom(-other.monoms.GetValueAtPosition(i).coef, other.monoms.GetValueAtPosition(i).degree));
   }

   res.CombineLikeTerms();
   return res;
}

Polinom Polinom::operator+(const Polinom& other) const {
   Polinom res = *this;

   for (size_t i = 0; i < other.monoms.GetSize(); ++i) {
      res.AddMonom(other.monoms.GetValueAtPosition(i));
   }

   res.CombineLikeTerms();
   return res;
}

Polinom Polinom::operator*(const Polinom& other) const {
   Polinom res;

   for (size_t i = 0; i < this->monoms.GetSize(); ++i) {
      for (size_t j = 0; j < other.monoms.GetSize(); ++j) {
         double productCoefficient = this->monoms.GetValueAtPosition(i).coef * other.monoms.GetValueAtPosition(j).coef;
         unsigned int sumDegree = this->monoms.GetValueAtPosition(i).degree + other.monoms.GetValueAtPosition(j).degree;
         res.AddMonom(Monom(productCoefficient, sumDegree));
      }
   }

   res.CombineLikeTerms();
   return res;
}

Polinom Polinom::MultiplyByConst(int constant) const {
   Polinom res;

   for (size_t i = 0; i < monoms.GetSize(); ++i) {
      Monom cur = monoms.GetValueAtPosition(i);
      double newCoef = cur.coef * constant;
      res.AddMonom(Monom(newCoef, cur.degree));
   }

   return res;
}

pair<Polinom, Polinom> Polinom::Divide(const Polinom& div) const {
   if (div.monoms.IsEmpty()) {
      throw runtime_error("Division by zero");
   }

   Polinom resultQuotient, resultRemainder = *this; // Инициализация частного и остатка

   Monom divisorLeadingMonom = div.monoms.GetValueAtPosition(div.monoms.GetSize() - 1); // Получение старшего монома делителя

   while (!resultRemainder.monoms.IsEmpty() && resultRemainder.monoms.GetValueAtPosition(resultRemainder.monoms.GetSize() - 1).degree >= divisorLeadingMonom.degree) {
      Monom remainderLeadingMonom = resultRemainder.monoms.GetValueAtPosition(resultRemainder.monoms.GetSize() - 1); // Получение старшего монома делимого
      Monom currentQuotientMonom = Monom(remainderLeadingMonom.coef / divisorLeadingMonom.coef, remainderLeadingMonom.degree - divisorLeadingMonom.degree); // Вычисление нового монома частного
      resultQuotient.AddMonom(currentQuotientMonom);

      Polinom tmp;
      tmp.AddMonom(currentQuotientMonom);
      resultRemainder = resultRemainder - (tmp * div);

      resultRemainder.CombineLikeTerms();
   }

   return make_pair(resultQuotient, resultRemainder);
}

double Polinom::Сalculation(double x, double y, double z) const {
   double sum = 0.0;
   for (size_t i = 0; i < monoms.GetSize(); ++i) {
      sum += monoms.GetValueAtPosition(i).СalculationMonomial(x, y, z);
   }
   return sum;
}

void Polinom::Display() const {
   for (size_t i = 0; i < monoms.GetSize(); ++i) {
      monoms.GetValueAtPosition(i).PrintMonomial();
      if (i < monoms.GetSize() - 1 && monoms.GetValueAtPosition(i + 1).coef >= 0) {
         cout << "+";
      }
   }
   cout << endl;
}