#include <gtest.h>
#include "pyl.h"
#include "Polynom.cpp"

TEST(PolinomTest, DefaultConstructor) 
{
    Polinom p;
    ASSERT_TRUE(p.isEmpty());
}
TEST(PolinomTest, SubtractionWithEmptyPolinom) 
{
    Polinom p1("5xyz");
    Polinom p2;
    Polinom result = p1 - p2;
    ASSERT_EQ(result.evaluate(1, 2, 1), 10);
}
TEST(PolinomTest, StringConstructor) 
{
    Polinom p("3x^2yz+2xyz+4x^3y^2z");
    ASSERT_FALSE(p.isEmpty());
}
