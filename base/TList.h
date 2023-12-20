#ifndef __TLIST_H__
#define __TLIST_H__

#include <stdexcept>
#include <iostream>
#include <utility>

using namespace std;

template<typename T>
class TList {
private:
   struct TNode {
      T value;
      TNode* pNext;
   };

   size_t size;
   TNode* pFirst;

   TNode* GetNodeAtPosition(size_t position) const {
      if (position >= size) {
         throw out_of_range("Index out of range");
      }

      auto cur = pFirst;
      for (size_t i = 0; i < position; ++i) {
         if (cur == nullptr) {
            throw out_of_range("Invalid position");
         }
         cur = cur->pNext;
      }

      return cur;
   }


public:
   TList() : pFirst(nullptr), size(0) {}

   TList(const TList& other) : pFirst(nullptr), size(0) {
      TNode* cur = other.pFirst;
      while (cur != nullptr) {
         PushBack(cur->value);
         cur = cur->pNext;
      }
   }

   TList& operator=(TList other) {
      swap(pFirst, other.pFirst);
      swap(size, other.size);
      return *this;
   }

   size_t GetSize() const { return size; }

   bool IsEmpty() const { return size == 0; }

   void PushBack(const T& _value) {
      if (pFirst == nullptr) {
         pFirst = new TNode{ _value, nullptr };
      }
      else {
         TNode* cur = pFirst;
         while (cur->pNext != nullptr) {
            cur = cur->pNext;
         }
         cur->pNext = new TNode{ _value, nullptr };
      }
      size++;
   }

   void PushFront(const T& _value) {
      TNode* node = new TNode{ _value, pFirst };
      pFirst = node;
      size++;
   }

   void PopFront() {
      if (pFirst == nullptr) {
         throw out_of_range("List is empty");
      }
      TNode* temp = pFirst;
      pFirst = pFirst->pNext;
      delete temp;
      size--;
   }

   void InsertNodeAfter(size_t position, const T& _value) {
      TNode* currentNode = GetNodeAtPosition(position);
      TNode* newNode = new TNode{ _value, currentNode->pNext };
      currentNode->pNext = newNode;
      size++;
   }

   void RemoveNodeAfter(size_t position) {
      if (position >= size) {
         throw out_of_range("Invalid position");
      }
      if (position == 0) {
         PopFront();
      }
      else {
         TNode* currentNode = GetNodeAtPosition(position);
         TNode* deletedNode = currentNode->pNext;
         currentNode->pNext = deletedNode->pNext;
         delete deletedNode;
         size--;
      }
   }


   T& GetFront() {
      if (pFirst == nullptr) {
         throw out_of_range("List is empty");
      }
      return pFirst->value;
   }

   const T& GetValueAtPosition(size_t position) const {
      return GetNodeAtPosition(position)->value;
   }

   void Clear() {
      while (pFirst != nullptr) {
         TNode* temp = pFirst;
         pFirst = pFirst->pNext;
         delete temp;
      }
      size = 0;
   }

   ~TList() {
      Clear();
   }
};
#endif