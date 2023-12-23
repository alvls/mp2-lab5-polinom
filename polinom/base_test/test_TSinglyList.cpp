#include "TSinglyList.h"
#include <gtest.h>

TEST(TSinglyList, can_create_list)
{
    ASSERT_NO_THROW(TSinglyList<int> list);
}

TEST(TSinglyList, can_get_size)
{
    TSinglyList<int> list;
    list.pushBack(2);
    EXPECT_EQ(list.size(), 1);
}

TEST(TSinglyList, can_isEmpty)
{
    TSinglyList<int> list;

    EXPECT_TRUE(list.isEmpty());
}

TEST(TSinglyList, can_get_front)
{
    TSinglyList<int> list;
    list.pushBack(2);

    EXPECT_EQ(list.front(), 2);
}

TEST(TSinglyList, can_pushFront)
{
    TSinglyList<int> list;
    ASSERT_NO_THROW(list.pushFront(2));
}

TEST(TSinglyList, can_popFront)
{
    TSinglyList<int> list;
    list.pushBack(2);

    ASSERT_NO_THROW(list.popFront());
}

TEST(TSinglyList, cant_popFront_from_empty)
{
    TSinglyList<int> list;

    ASSERT_ANY_THROW(list.popFront());
}

TEST(TSinglyList, can_pushBack)
{
    TSinglyList<int> list;
    ASSERT_NO_THROW(list.pushBack(2));
}

TEST(TSinglyList, can_popBack)
{
    TSinglyList<int> list;
    list.pushBack(2);

    ASSERT_NO_THROW(list.popBack());
}

TEST(TSinglyList, cant_popBack_from_empty)
{
    TSinglyList<int> list;

    ASSERT_ANY_THROW(list.popBack());
}

TEST(TSinglyList, can_removeAt)
{
    TSinglyList<int> list;
    list.pushBack(2);

    ASSERT_NO_THROW(list.removeAt(0));
}

TEST(TSinglyList, cant_removeAt_from_empty)
{
    TSinglyList<int> list;

    ASSERT_ANY_THROW(list.removeAt(0));
}

TEST(TSinglyList, cant_removeAt_from_incorrect_pos)
{
    TSinglyList<int> list;
    list.pushBack(2);

    ASSERT_ANY_THROW(list.removeAt(1));
}

TEST(TSinglyList, can_equating)
{
    TSinglyList<int> list;
    TSinglyList<int> list2;
    list.pushBack(2);

    list2 = list;

    ASSERT_NO_THROW(list2 = list);
}

TEST(TSinglyList, can_sum)
{
    TSinglyList<int> list;
    TSinglyList<int> list2;
    list.pushBack(2);
    list2.pushBack(5);

    ASSERT_NO_THROW(list2 + list);
}

TEST(TSinglyList, can_mult)
{
    TSinglyList<int> list;
    TSinglyList<int> list2;
    list.pushBack(2);
    list2.pushBack(5);

    ASSERT_NO_THROW(list2 * list);
}