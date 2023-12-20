#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <algorithm>

template<typename T>
class TLinkedList
{
private:
	struct Node
	{
		T value;
		Node* next = nullptr;
	}
	*first, * last;
	size_t length;

	Node* node_at(size_t pos) const;

public:
	TLinkedList();
	TLinkedList(const TLinkedList& other);

	~TLinkedList();

	size_t size() const noexcept;
	bool empty() const noexcept;

	void push_back(const T& element);
	void remove(size_t pos);

	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

	bool operator==(const TLinkedList& other) const noexcept;
	bool operator!=(const TLinkedList& other) const noexcept;

	TLinkedList& operator=(const TLinkedList& other);

	friend void swap(TLinkedList& lhs, TLinkedList& rhs)
	{
		std::swap(lhs.length, rhs.length);
		std::swap(lhs.first, rhs.first);
		std::swap(lhs.last, rhs.last);
	}

	class Iterator
	{
	private:
		Node* current;

	public:
		Iterator(Node* node) : current(node) {}

		Iterator& operator++()
		{
			current = current->next;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator temp = *this;
			++(*this);
			return temp;
		}

		bool operator==(const Iterator& other) const
		{
			return current == other.current;
		}

		bool operator!=(const Iterator& other) const
		{
			return !(*this == other);
		}

		T& operator*()
		{
			return current->value;
		}
	};

	Iterator begin() const
	{
		return Iterator(first);
	}

	Iterator end() const
	{
		return Iterator(nullptr);
	}
};


template<typename T>
TLinkedList<T>::TLinkedList()
	: length(0), first(nullptr), last(nullptr) {}

template<typename T>
TLinkedList<T>::TLinkedList(const TLinkedList& other)
	: length(other.length), first(nullptr), last(nullptr)
{
	if (!other.first)
	{
		return;
	}

	TLinkedList::Node* pNew = first = new TLinkedList::Node{ *other.first };
	for (; pNew->next != nullptr; pNew = pNew->next)
	{
		pNew->next = new Node{ *pNew->next };
	}
	last = pNew;
}

template<typename T>
TLinkedList<T>::~TLinkedList()
{
	TLinkedList::Node* cur = first, * garbage;

	while (cur)
	{
		garbage = cur;
		cur = garbage->next;
		delete garbage;
	}
}

template<typename T>
typename TLinkedList<T>::Node* TLinkedList<T>::node_at(size_t pos) const
{
	TLinkedList::Node* node = first;
	for (size_t i = 0; i < pos; i++)
	{
		node = node->next;
	}
	return node;
}

template<typename T>
size_t TLinkedList<T>::size() const noexcept
{
	return length;
}

template<typename T>
bool TLinkedList<T>::empty() const noexcept
{
	return length == 0;
}

template<typename T>
void TLinkedList<T>::push_back(const T& element)
{
	TLinkedList::Node* node = new TLinkedList::Node{ element };

	if (first == nullptr)
	{
		first = last = node;
	}
	else
	{
		last->next = node;
		last = node;
	}

	length++;
}

template<typename T>
void TLinkedList<T>::remove(size_t pos)
{
	TLinkedList::Node* node;
	if (pos == 0)
	{
		node = first;
		first = node->next;
	}
	else
	{
		TLinkedList::Node* prev = node_at(pos - 1);
		node = prev->next;
		prev->next = prev->next->next;
	}
	delete node;

	length--;
}

template<typename T>
T& TLinkedList<T>::operator[](size_t idx)
{
	return node_at(idx)->value;
}

template<typename T>
const T& TLinkedList<T>::operator[](size_t idx) const
{
	return node_at(idx)->value;
}

template<typename T>
bool TLinkedList<T>::operator==(const TLinkedList& other) const noexcept
{
	if (this == &other)
		return true;

	if (length != other.length)
		return false;

	TLinkedList::Node* lnode = first, * rnode = other.first;
	while (lnode->next)
	{
		if (lnode->value != rnode->value)
			return false;

		lnode = lnode->next;
		rnode = rnode->next;
	}

	return true;
}

template<typename T>
bool TLinkedList<T>::operator!=(const TLinkedList& other) const noexcept
{
	return !(*this == other);
}

template<typename T>
TLinkedList<T>& TLinkedList<T>::operator=(const TLinkedList& other)
{
	if (*this != other)
	{
		TLinkedList<T> tmp(other);
		swap(*this, tmp);
	}

	return *this;
}

#endif // __LINKEDLIST_H__
