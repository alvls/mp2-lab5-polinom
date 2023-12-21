#include "gtest.h"
#include "TaskGenerator.cpp"

TEST(Test_TaskGenerator, CanCreateTaskGenerator) {
	ASSERT_NO_THROW(TaskGenerator tmp());
}
TEST(Test_TaskGenerator, CanChangeP) {
	TaskGenerator tmp(0.5);
	tmp.ChangeP(0.1);
	EXPECT_EQ(0.1, tmp.GetP());
}
TEST(Test_TaskGenerator, CanCreateTasks) {
	TaskGenerator tmp(1);
	Queue_task ans;
	ans=tmp.createTask(ans);
	EXPECT_EQ(true, ans.GetSize()>0);
}
TEST(Test_TaskGenerator, TaskdontHaveMoreThenMaxNodes) {
	TaskGenerator tmp(1);
	Queue_task ans;
	int flag = 1;
	ans = tmp.createTask(ans);
	while (ans.GetSize() != 0) {
		if (ans.Pop()->date.number_of_nodes > 15)
			flag = 0;
	}
	EXPECT_EQ(1, flag);
}
TEST(Test_TaskGenerator, TaskdontHaveMoreThenMaxTime) {
	TaskGenerator tmp(1);
	Queue_task ans;
	int flag = 1;
	tmp.createTask(ans);
	while (ans.GetSize() != 0) {
		if (ans.Pop()->date.time > 15)
			flag = 0;
	}
	EXPECT_EQ(1, flag);
}
TEST(Test_TaskGenerator, CanGetSize) {
	TaskGenerator tmp(1);
	Queue_task ans;
	tmp.createTask(ans);
	EXPECT_EQ(10, tmp.getSize());
}
