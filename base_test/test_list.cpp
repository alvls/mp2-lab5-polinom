#include <gtest.h>
#include "TSinglyList.h"

TEST(TSinglyListTest, DefaultConstructor) {
	TSinglyList<int> list;
	ASSERT_TRUE(list.IsEmpty());
	ASSERT_EQ(list.Size(), 0);
}

TEST(TSinglyListTest, PushFront) {
	TSinglyList<int> list;
	list.PushFront(1);
	list.PushFront(2);

	ASSERT_EQ(list.Size(), 2);
	ASSERT_EQ(list.Front(), 2);
	ASSERT_EQ(list.At(1), 1);
}

TEST(TSinglyListTest, PushBack) {
	TSinglyList<int> list;
	list.PushBack(1);
	list.PushBack(2);

	ASSERT_EQ(list.Size(), 2);
	ASSERT_EQ(list.At(0), 1);
	ASSERT_EQ(list.At(1), 2);
}

TEST(TSinglyListTest, PopFront) {
	TSinglyList<int> list;
	list.PushFront(1);
	list.PushFront(2);
	list.PopFront();

	ASSERT_EQ(list.Size(), 1);
	ASSERT_EQ(list.Front(), 1);
}

TEST(TSinglyListTest, InsertAfter) {
	TSinglyList<int> list;
	list.PushBack(1);
	list.PushBack(3);
	list.InsertAfter(0, 2);

	ASSERT_EQ(list.Size(), 3);
	ASSERT_EQ(list.At(1), 2);
	ASSERT_EQ(list.At(2), 3);
}

TEST(TSinglyListTest, EraseAfter) {
	TSinglyList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.EraseAfter(0);

	ASSERT_EQ(list.Size(), 2);
	ASSERT_EQ(list.At(1), 3);
}

TEST(TSinglyListTest, Clear) {
	TSinglyList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.Clear();

	ASSERT_TRUE(list.IsEmpty());
}

TEST(TSinglyListTest, CopyConstructor) {
	TSinglyList<int> list;
	list.PushBack(1);
	list.PushBack(2);

	TSinglyList<int> copiedList = list;

	ASSERT_EQ(copiedList.Size(), 2);
	ASSERT_EQ(copiedList.At(0), 1);
	ASSERT_EQ(copiedList.At(1), 2);
}

TEST(TSinglyListTest, AssignmentOperator) {
	TSinglyList<int> list;
	list.PushBack(1);
	list.PushBack(2);

	TSinglyList<int> assignedList;
	assignedList = list;

	ASSERT_EQ(assignedList.Size(), 2);
	ASSERT_EQ(assignedList.At(0), 1);
	ASSERT_EQ(assignedList.At(1), 2);
}
