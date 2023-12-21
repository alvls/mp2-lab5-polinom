#include "gtest.h"
#include "Polinom.cpp"
TEST(Test_Polinom, CanCreatePolinom) {
	ASSERT_NO_THROW(Polinom tmp("2x1y1z1"));
}
TEST(Test_Polinom, CanCreatePolinomwithNegativeMonom) {
	ASSERT_NO_THROW(Polinom tmp("-2x1y1z1"));
}
TEST(Test_Polinom, CanPrintPolinom) {
	Polinom tmp("2x1y1z1");
	EXPECT_EQ("2x1y1z1", tmp.prPolinom());
}
TEST(Test_Polinom, CanPrintPolinomWithNegativeMonom) {
	Polinom tmp("2x1y1z1-4x2y2z2");
	EXPECT_EQ("2x1y1z1-4x2y2z2", tmp.prPolinom());
}
TEST(Test_Polinom, CanCalculate) {
	Polinom tmp("2x1y1z1");
	int x = 2, y = 2, z = 2;
	EXPECT_EQ(16, tmp.Calculate(x, y, z));
}
TEST(Test_Polinom, CanCalculateWithnegativeCoef) {
	Polinom tmp("-2x1y1z1");
	int x = 2, y = 2, z = 2;
	EXPECT_EQ(-16, tmp.Calculate(x, y, z));
}
TEST(Test_Polinom, CanBringSimular) {
	Polinom tmp("2x1y1z1+4x1y1z1");
	tmp.BringSimular();
	EXPECT_EQ("6x1y1z1", tmp.prPolinom());
}
TEST(Test_Polinom, CanAditional) {
	Polinom tmp("2x1y1z1+4x2y1z1");
	tmp.aditional(Polinom("3x1y1z1+3x2y2z1"));
	EXPECT_EQ("5x1y1z1+4x2y1z1+3x2y2z1", tmp.prPolinom());
}
TEST(Test_Polinom, CanMultiplicate) {
	Polinom tmp("2x1y1z1");
	tmp.Multiplication(Polinom("3x1y1z1+3x2y2z1"));
	EXPECT_EQ("6x2y2z2+6x3y3z2", tmp.prPolinom());
}