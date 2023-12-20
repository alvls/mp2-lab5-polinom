#include <gtest.h>
#include "TList.h"

TEST(TList, CreateList) {
   TList<int> myList;

   EXPECT_EQ(myList.GetSize(), 0);
   EXPECT_TRUE(myList.IsEmpty());
}

TEST(TList, PopFront) {
   TList<int> myList;

   myList.PushBack(42);
   myList.PopFront();

   EXPECT_TRUE(myList.IsEmpty());
   EXPECT_THROW(myList.GetFront(), out_of_range);
}

TEST(TList, Clear) {
   TList<int> myList;
   myList.PushBack(42);
   myList.PushBack(99);

   EXPECT_EQ(myList.GetSize(), 2);

   myList.Clear();

   EXPECT_TRUE(myList.IsEmpty());
   EXPECT_EQ(myList.GetSize(), 0);
}

TEST(TList, PushBack) {
   TList<int> myList;
   myList.PushBack(1);
   myList.PushBack(2);

   EXPECT_EQ(myList.GetSize(), 2);
   EXPECT_EQ(myList.GetValueAtPosition(1), 2);
}

TEST(TList, PushFront) {
   TList<int> myList;
   myList.PushFront(1);
   myList.PushFront(2);

   EXPECT_EQ(myList.GetSize(), 2);
   EXPECT_EQ(myList.GetFront(), 2);
}

TEST(TList, InsertNodeAfter) {
   TList<int> myList;
   myList.PushBack(1);
   myList.PushBack(3);

   myList.InsertNodeAfter(0, 2);

   EXPECT_EQ(myList.GetSize(), 3);
   EXPECT_EQ(myList.GetValueAtPosition(1), 2);

   myList.InsertNodeAfter(2, 4);

   EXPECT_EQ(myList.GetSize(), 4);
   EXPECT_EQ(myList.GetValueAtPosition(3), 4);
}

TEST(TList, RemoveNodeAfter) {
   TList<int> myList;
   myList.PushBack(1);
   myList.PushBack(2);
   myList.PushBack(3);

   myList.RemoveNodeAfter(0);

   EXPECT_EQ(myList.GetSize(), 2);
   EXPECT_EQ(myList.GetValueAtPosition(1), 3);

   myList.RemoveNodeAfter(0);

   EXPECT_EQ(myList.GetSize(), 1);
}

TEST(TList, CopyConstructor) {
   TList<int> originalList;
   originalList.PushBack(1);
   originalList.PushBack(2);
   originalList.PushBack(3);

   TList<int> copiedList(originalList);

   EXPECT_EQ(originalList.GetSize(), copiedList.GetSize());
   EXPECT_EQ(originalList.GetFront(), copiedList.GetFront());

   // Модификация оригинального списка не должна влиять на скопированный
   originalList.PushBack(4);

   EXPECT_NE(originalList.GetSize(), copiedList.GetSize());
}
