#ifndef MONOM_LIST_H
#define MONOM_LIST_H

#include "monom.h" 
#include <vector>
#include <iostream>
#include <utility>
#include <stdexcept>
using namespace std;

template<typename T>
class monomlist
{
private:
	struct Node
	{
		monom MONOM;
		Node* pNext;
	};
	Node* pFirst;
	size_t size;
	Node* ToPos(size_t pos) const
	{
		if (pos >= size)
		{
			throw out_of_range("Index out of range");
		}
		Node* current = pFirst;
		for (size_t i = 0; i < pos; ++i)
		{
			current = current->pNext;
		}
		return current;
	}
public:
	monomlist() : pFirst(nullptr), size(0) {}
	~monomlist()
	{
		clear();
	}
	void clear() 
	{
		while (!isEmpty()) 
		{
			popFront();
		}
	}
	monomlist(const monomlist& other) : pFirst(nullptr), size(0) 
	{
		Node* current = other.pFirst;
		while (current != nullptr) 
		{
			PushBack(current->value);
			current = current->pNext;
		}
	}
	monomlist& operator=(monomlist other)
	{
		swap(pFirst, other.pFirst);
		swap(size, other.size);
		return *this;
	}
	void pushFront(const monom& monom)
	{
		Node* newNode = new Node{ monom, pFirst };
		pFirst = newNode;
		size++;
	}
	void pushBack(const monom& monom)
	{
		if (pFirst == nullptr)
		{
			pFirst = new Node{ monom, nullptr };
		}
		else {
			Node* current = pFirst;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node{ monom, nullptr };
		}
		size++;
	}
	void popFront() 
	{
		if (isEmpty())
		{
			throw std::out_of_range("List is empty");
		}
		Node* temp = pFirst;
		pFirst = pFirst->pNext;
		delete temp;
		size--;
	}
	void InsertAfter(size_t pos, const monom& val)
	{
		Node* prevNode = ToPos(pos);
		Node* newNode = new Node{ val, prevNode->pNext };
		prevNode->pNext = newNode;
		size++;
	}
	void EraseAfter(size_t pos)
	{
		if (pos >= size) 
		{
			throw out_of_range("Index out of range");
		}
		Node* prevNode = ToPos(pos);
		Node* deleteNode = prevNode->pNext;
		prevNode->pNext = deleteNode->pNext;
		delete deleteNode;
		size--;
	}
	size_t getSize() const 
	{
		return size;
	}
	bool isEmpty() const 
	{
		return size == 0;
	}
	monom& Front() noexcept 
	{
		if (pFirst == nullptr) 
		{
			throw out_of_range("List is empty");
		}
		return pFirst->MONOM;
	}
	const monom& At(size_t pos) const 
	{
		return ToPos(pos)->MONOM;
	}
};
#endif
