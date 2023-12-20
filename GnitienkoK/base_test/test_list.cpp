#include "myList.h"
#include <gtest.h>

TEST(myList, can_create_list) {
	ASSERT_NO_THROW(myList<int> list);
}

TEST(myList, can_create_list_from_other_list) {
	myList<int> list;
	list.addNode(1);
	list.addNode(12);
	ASSERT_NO_THROW(myList<int> list2(list));
}

TEST(myList, can_push_front_elem) {
	myList<int> list;
	list.addNode(1);
	list.pushFront(2);
	EXPECT_EQ(2, list.Front());
}

TEST(myList, can_get_elem_from_ind) {
	myList<int> list;
	list.addNode(1);
	list.addNode(12);
	list.addNode(123);
	EXPECT_EQ(123, list[2]);
}

TEST(myList, throw_when_ind_greater_than_size) {
	myList<int> list;
	list.addNode(1);
	list.addNode(12);
	list.addNode(123);
	ASSERT_ANY_THROW(list[3]);
}

TEST(myList, can_pop_elem) {
	myList<int> list;
	list.addNode(1);
	list.addNode(12);
	list.addNode(123);
	list.popFront();
	EXPECT_EQ(12, list.Front());
}

TEST(myList, can_push_after_pos) {
	myList<int> list;
	list.addNode(1);
	list.addNode(123);
	list.pushAfter(0, 12);
	EXPECT_EQ(12, list[1]);
}

TEST(myList, throw_when_pop_from_empty_list) {
	myList<int> list;
	ASSERT_ANY_THROW(list.popFront());
}

TEST(myList, can_assign_other_list) {
	myList<int> list;
	list.addNode(1);
	list.addNode(12);
	myList<int> list2 = list;
	EXPECT_EQ(list2.Front(), 1);
}

TEST(myList, can_erase_elem) {
	myList<int> list;
	list.addNode(1);
	list.addNode(12);
	ASSERT_NO_THROW(list.eraseAfter(0));
}

TEST(myList, throw_when_erase_from_empty_list) {
	myList<int> list;
	ASSERT_ANY_THROW(list.eraseAfter(0));
}