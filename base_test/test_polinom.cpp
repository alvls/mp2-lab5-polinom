#include <gtest.h>
#include "Polinom.h"
#include "Polinom.cpp"

TEST(Polinom, DefConstructor) {
   Polinom polinom;

   ASSERT_TRUE(polinom.isEmpty());
}

TEST(Polinom, StrConstructor) {
   Polinom polinom("3x^2y^5z^5+2x^3y^3");

   ASSERT_FALSE(polinom.isEmpty());
}

TEST(Polinom, CopyConstructor) {
   Polinom polinom1("3x^2y^5z^5+2x^3y^3");
   Polinom polinom2 = polinom1;

   ASSERT_EQ(polinom1.Ñalculation(1, 2, 3), polinom2.Ñalculation(1, 2, 3));
}

TEST(Polinom, Assignment) {
   Polinom polinom1("3x^2y^5z^5+2x^3y^3");
   Polinom polinom2;
   polinom2 = polinom1;

   ASSERT_EQ(polinom1.Ñalculation(1, 2, 3), polinom2.Ñalculation(1, 2, 3));
}

TEST(Polinom, Addition) {
   Polinom polinom1("3x^2y^2+2x^3z^2");
   Polinom polinom2("4x^2y^2+3x^3y^2");
   Polinom res = polinom1 + polinom2;

   ASSERT_EQ(res.Ñalculation(1, 1, 1), 12);
}

TEST(Polinom, Subtraction) {
   Polinom polinom1("4x^2y^2+3x^3y^2");
   Polinom polinom2("3x^2y^2+2x^3z^2");
   Polinom res = polinom1 - polinom2;

   ASSERT_EQ(res.Ñalculation(1, 1, 1), 2);
}

TEST(Polinom, Multiplication) {
   Polinom polinom1("2x^3z^2");
   Polinom polinom2("3x^3y^2");
   Polinom res = polinom1 * polinom2;

   ASSERT_EQ(res.Ñalculation(1, 2, 2), 96);
}

TEST(Polinom, MultiplyByConst) {
   Polinom polinom("3x^2y^5z^5+2x^3y^3");
   Polinom res = polinom.MultiplyByConst(5);

   ASSERT_EQ(res.Ñalculation(1, 1, 1), 25);
}

TEST(Polinom, Ñalculation) {
   Polinom polinom("3x^2y^5z^5+2x^3y^3");

   ASSERT_DOUBLE_EQ(polinom.Ñalculation(1, 2, 2), 3088);
}