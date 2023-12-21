#include "gtest.h"
#include "MyList.cpp"

TEST(Test_MyList, CanCreateMyList) {
	ASSERT_NO_THROW(MyList tmp());
}
TEST(Test_MyList, CanGetSize) {
	MyList tmp;
	Monom m;
	m.coef = 1;
	m.deg = 111;
	tmp.Push(m);
	EXPECT_EQ(1, tmp.GetSize());
}
TEST(Test_MyList, CreateWithZeroSize) {
	MyList tmp;
	EXPECT_EQ(0, tmp.GetSize());
}
TEST(Test_MyList, CanPush) {
	MyList tmp;
	Monom m;
	m.coef = 1;
	m.deg = 111;
	ASSERT_NO_THROW(tmp.Push(m));
}
TEST(Test_MyList, WhenCreatepFirstsetnullptr) {
	MyList tmp;
	EXPECT_EQ(nullptr, tmp.GetpFirst());
}
TEST(Test_MyList, WhenCreatepLastsetnullptr) {
	MyList tmp;
	EXPECT_EQ(nullptr, tmp.GetpLast());
}
TEST(Test_MyList, PushChangepLast) {
	MyList tmp;
	Monom m;
	m.coef = 1;
	m.deg = 111;
	tmp.Push(m);
	EXPECT_EQ(true, nullptr != tmp.GetpLast());
}