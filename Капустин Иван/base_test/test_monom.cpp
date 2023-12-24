#include <gtest.h>

#include "Monom.h"
#include "Monom.cpp"

TEST(MonomTest, EqualityOperator) 
{
    monom m1(2, 212);
    monom m2(2, 212);
    ASSERT_TRUE(m1 == m2);
}
TEST(MonomTest, CreateMonomWithZeroCoefficient)
{
    monom m(0, 112);
    ASSERT_EQ(m.coef, 0);
    ASSERT_EQ(m.sumdeg, 112);
}
TEST(MonomTest, EvaluateMonomWithZeroCoefficient)
{
    monom m(0, 211);
    ASSERT_DOUBLE_EQ(m.evaluate(2, 3, 4), 0);
}
TEST(MonomTest, calc_monom) 
{
    monom m(2, 111);
    ASSERT_DOUBLE_EQ(m.evaluate(2, 3, 4), 2 * pow(2, 1) * pow(3, 1) * pow(4, 1));
}
TEST(MonomTest, CreateMonomWithNegativeCoefficient) 
{
    monom m(-5, 212);
    ASSERT_EQ(m.coef, -5);
    ASSERT_EQ(m.sumdeg, 212);
}
TEST(MonomTest, EvaluateMonomWithNegativeCoefficient) 
{
    monom m(-2, 111);
    ASSERT_DOUBLE_EQ(m.evaluate(2, 3, 4), -2 * pow(2, 1) * pow(3, 1) * pow(4, 1));
}
TEST(MonomTest, LessThanOperatorWithNegativeCoefficient) 
{
    monom m1(-1, 212);
    monom m2(-1, 213);
    ASSERT_TRUE(m1 < m2);
}
TEST(MonomTest, EqualityOperatorWithNegativeCoefficient) 
{
    monom m1(-2, 212);
    monom m2(-2, 212);
    ASSERT_TRUE(m1 == m2);
}
TEST(MonomTest, EvaluateMonomWithZeroDegree) 
{
    monom m(3, 0);
    ASSERT_DOUBLE_EQ(m.evaluate(2, 3, 4), 3);
}
TEST(MonomTest, CreateMonomWithZeroDegree) 
{
    monom m(6, 0);
    ASSERT_EQ(m.coef, 6);
    ASSERT_EQ(m.sumdeg, 0);
}