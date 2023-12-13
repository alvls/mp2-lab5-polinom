#include <gtest.h>
#include "Polinom.h"
#include "Polinom.cpp"

TEST(PolinomTest, DefaultConstructor) {
    Polinom p;
    ASSERT_TRUE(p.isEmpty());
}

TEST(PolinomTest, StringConstructor) {
    Polinom p("3x^2yz+2xyz+4x^3y^2z");
    ASSERT_FALSE(p.isEmpty());
}

TEST(PolinomTest, CopyConstructor) {
    Polinom p1("x^2yz+4x^3yz");
    Polinom p2 = p1;
    ASSERT_EQ(p1.evaluate(2, 0, 0), p2.evaluate(2, 0, 0));
}

TEST(PolinomTest, AssignmentOperator) {
    Polinom p1("x^2yz+4x^3yz");
    Polinom p2;
    p2 = p1;
    ASSERT_EQ(p1.evaluate(1, 1, 1), p2.evaluate(1, 1, 1));
}

TEST(PolinomTest, Addition) {
    Polinom p1("xyz+1x^3yz");
    Polinom p2("x^2yz+1x^3yz");
    Polinom result = p1 + p2;
    ASSERT_EQ(result.evaluate(1, 1, 0), 0);
}

TEST(PolinomTest, Subtraction) {
    Polinom p1("5xyz");
    Polinom p2("4xyz");
    Polinom result = p1 - p2;
    ASSERT_EQ(result.evaluate(1, 2, 1), 2);
}

TEST(PolinomTest, Multiplication) {
    Polinom p1("xyz");
    Polinom p2("xyz");
    Polinom result = p1 * p2;
    ASSERT_EQ(result.evaluate(2, 2, 2), 64); //x*x*y*y*z*z
}

TEST(PolinomTest, MultiplyByConstant) {
    Polinom p("1xyz + 1xyz");
    Polinom result = p.multiplyByConstant(2);
    ASSERT_EQ(result.evaluate(2, 1, 1), 8);
}

TEST(PolinomTest, Evaluate) {
    Polinom p("x^2y^2z^2+3xyz");
    ASSERT_DOUBLE_EQ(p.evaluate(1, 1, 3), 18);
}