#include <gtest.h>
#include "linkedlist.h"

TEST(TLinkedListTest, can_create_list)
{
    ASSERT_NO_THROW(TLinkedList<int> list);
}

TEST(TLinkedListTest, can_create_default_list)
{
    TLinkedList<int> list;
    EXPECT_EQ(list.size(), 0);
    EXPECT_TRUE(list.empty());
}

TEST(TLinkedListTest, can_copy_list)
{
    TLinkedList<int> original;
    original.push_back(1);
    original.push_back(2);
    original.push_back(3);

    TLinkedList<int> copy(original);

    EXPECT_EQ(original.size(), copy.size());
    EXPECT_EQ(original, copy);
}

TEST(TLinkedListTest, copied_list_is_independent) 
{
    TLinkedList<int> original;
    original.push_back(1);
    original.push_back(2);
    original.push_back(3);

    TLinkedList<int> copy = original;
    copy[0] = 99;

    EXPECT_NE(original[0], copy[0]);
}

TEST(TLinkedListTest, can_assign_list_to_another) 
{
    TLinkedList<int> original;
    original.push_back(1);
    original.push_back(2);
    original.push_back(3);

    TLinkedList<int> copy;
    copy = original;

    EXPECT_EQ(original.size(), copy.size());
    EXPECT_EQ(original, copy);
}

TEST(TLinkedListTest, can_assign_list_to_itself) {
    TLinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    ASSERT_NO_THROW(list1 = list1);
    TLinkedList<int> list2(list1);
    list1 = list1;

    EXPECT_EQ(list1, list2);
}

TEST(TLinkedListTest, can_size_method) {
    TLinkedList<int> list;
    EXPECT_EQ(list.size(), 0);

    list.push_back(1);
    list.push_back(2);
    EXPECT_EQ(list.size(), 2);

    list.push_back(3);
    EXPECT_EQ(list.size(), 3);
}

TEST(TLinkedListTest, cen_empty_method) {
    TLinkedList<int> list;
    EXPECT_TRUE(list.empty());

    list.push_back(1);
    EXPECT_FALSE(list.empty());

    list.remove(0);
    EXPECT_TRUE(list.empty());
}

TEST(TLinkedListTest, test_index_operator) {
    TLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);

    list[1] = 10;
    EXPECT_EQ(list[1], 10);

    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[2], 3);
}

TEST(TLinkedListTest, can_push_back) {
    TLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
}


TEST(TLinkedListTest, can_remove) 
{
    TLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.remove(1);

    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 3);
}

TEST(TLinkedListTest, equal_operator_returns_true_for_equal_lists) {
    TLinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    TLinkedList<int> list2;
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);

    ASSERT_TRUE(list1==list2);
    ASSERT_FALSE(list1!=list2);
}

TEST(TLinkedListTest, equal_operator_returns_false_for_unequal_lists) {
    TLinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    TLinkedList<int> list2;
    list2.push_back(5);
    list2.push_back(6);
    list2.push_back(7);

    ASSERT_TRUE(list1 != list2);
    ASSERT_FALSE(list1 == list2);
}


TEST(TLinkedListTest, test_iterator) {
    TLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    int sum = 0;
    for (const auto& value : list) {
        sum += value;
    }

    EXPECT_EQ(sum, 6);
}