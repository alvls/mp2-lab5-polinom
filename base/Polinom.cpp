#include "Polinom.h"


Polinom::Polinom(const string& polinomStr) {
   regex monomPattern(R"(\s*([-+]?\d*\.?\d*)\s*(x(\^\d+)?)?\s*(y(\^\d+)?)?\s*(z(\^\d+)?)?\s*)");

   sregex_iterator monomIteratorBegin(polinomStr.begin(), polinomStr.end(), monomPattern);
   sregex_iterator monomIteratorEnd;

   for (auto it = monomIteratorBegin; it != monomIteratorEnd; ++it) {
      const smatch& match = *it;

      // ���������� �����, ���� �� �� �������� ���������� � ������������ � �������� ����������
      if (match[1].str().empty() && !match[2].matched && !match[4].matched && !match[6].matched) {
         continue;
      }

      double monomCoefficient = 1.0;
      int monomXDegree = 0;
      int monomYDegree = 0;
      int monomZDegree = 0;

      // ��������� ���������� � ������������
      if (!match[1].str().empty()) {
         monomCoefficient = stod(match[1].str());
      }

      // ��������� ���������� � ������� x
      if (!match[3].str().empty()) {
         monomXDegree = stoi(match[3].str().substr(1));
      }
      else if (match[2].matched) {
         monomXDegree = 1;
      }

      // ��������� ���������� � ������� y
      if (!match[5].str().empty()) {
         monomYDegree = stoi(match[5].str().substr(1));
      }
      else if (match[4].matched) {
         monomYDegree = 1;
      }

      // ��������� ���������� � ������� z
      if (!match[7].str().empty()) {
         monomZDegree = stoi(match[7].str().substr(1));
      }
      else if (match[6].matched) {
         monomZDegree = 1;
      }

      unsigned int monomTotalDegree = monomXDegree * 100 + monomYDegree * 10 + monomZDegree;

      AddMonom(Monom(monomCoefficient, monomTotalDegree));
   }

   // ��������� ��������� �������� ����� ���������� ���� �������
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

   // ������� ������� �������
   monoms.Clear();

   // �������� ������ �� ������� ��������
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
   // ��������� ������ �� ��������� ������ ��� ���������
   vector<Monom> monomVector;
   while (!monoms.IsEmpty()) {
      monomVector.push_back(monoms.GetFront());
      monoms.PopFront();
   }

   // ��������� ������ � ������� �������� ��������
   sort(monomVector.begin(), monomVector.end(), [](const Monom& a, const Monom& b) { return a.degree > b.degree; });

   // ���������� ��������� �������
   for (size_t i = 0; i < monomVector.size(); i++) {
      if (i < monomVector.size() - 1 && monomVector[i].degree == monomVector[i + 1].degree) {
         monomVector[i + 1].coef += monomVector[i].coef;
         monomVector[i].coef = 0;
      }
   }

   // ������� ������ � ������� �������������
   monomVector.erase(remove_if(monomVector.begin(), monomVector.end(), [](const Monom& m) { return m.coef == 0; }), monomVector.end());

   // ���������� ���������� ������ �������
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

   Polinom resultQuotient, resultRemainder = *this; // ������������� �������� � �������

   Monom divisorLeadingMonom = div.monoms.GetValueAtPosition(div.monoms.GetSize() - 1); // ��������� �������� ������ ��������

   while (!resultRemainder.monoms.IsEmpty() && resultRemainder.monoms.GetValueAtPosition(resultRemainder.monoms.GetSize() - 1).degree >= divisorLeadingMonom.degree) {
      Monom remainderLeadingMonom = resultRemainder.monoms.GetValueAtPosition(resultRemainder.monoms.GetSize() - 1); // ��������� �������� ������ ��������
      Monom currentQuotientMonom = Monom(remainderLeadingMonom.coef / divisorLeadingMonom.coef, remainderLeadingMonom.degree - divisorLeadingMonom.degree); // ���������� ������ ������ ��������
      resultQuotient.AddMonom(currentQuotientMonom);

      Polinom tmp;
      tmp.AddMonom(currentQuotientMonom);
      resultRemainder = resultRemainder - (tmp * div);

      resultRemainder.CombineLikeTerms();
   }

   return make_pair(resultQuotient, resultRemainder);
}

double Polinom::�alculation(double x, double y, double z) const {
   double sum = 0.0;
   for (size_t i = 0; i < monoms.GetSize(); ++i) {
      sum += monoms.GetValueAtPosition(i).�alculationMonomial(x, y, z);
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