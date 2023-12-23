#include <iostream>

using namespace std;


template<typename T> class TSinglyList {

	struct TNode {
		T value;
		TNode* pNext;
	};

	TNode* pFirst;
	size_t sz = 0;

public:
	TSinglyList() : pFirst(nullptr), sz(0) {}

	TSinglyList(const TSinglyList& list) : pFirst(nullptr), sz(list.sz) {

		if (list.pFirst == nullptr) { return; }
	
		TNode* pNew = pFirst = new TNode{ *list.pFirst };

		for (; pNew->pNext != nullptr; pNew = pNew->pNext)
		{
			pNew->pNext = new TNode{ *pNew->pNext };
		}
	}

	TSinglyList(TSinglyList&& list) noexcept {

		pFirst = nullptr;
		swap(*this, list);
	}

	size_t size() const noexcept { return sz; }

	bool isEmpty() const noexcept { return sz == 0; }

	T& front() noexcept { return pFirst->value; }

	void pushFront(const T& val) {

		TNode* node = new TNode{ val, pFirst };
		pFirst = node;
		sz++;
	}

	void popFront() {

		if (sz == 0) { throw out_of_range("List is empty"); }

		TNode* p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		sz--;
	}

	void pushBack(const T& val) {

		TNode* newNode = new TNode{ val, nullptr };

		if (pFirst == nullptr) { pFirst = newNode; }

		else 
		{
			TNode* p = pFirst;
			while (p->pNext != nullptr) 
			{
				p = p->pNext;
			}
			p->pNext = newNode;
		}
		sz++;
	}

	void popBack() {

		if (pFirst == nullptr) { throw out_of_range("List is empty"); }
		
		else if (pFirst->pNext == nullptr) 
		{
			delete pFirst;
			pFirst = nullptr;
		}
		else 
		{
			TNode* p = pFirst;

			while (p->pNext->pNext != nullptr) { p = p->pNext; }

			delete p->pNext;
			p->pNext = nullptr;
		}
		sz--;
	}

	void removeAt(size_t index) {

		if (index >= sz) { throw out_of_range("Index out of bounds"); }

		if (index == 0) { popFront(); }

		else 
		{
			TNode* prevNode = pFirst;
			for (size_t i = 0; i < index - 1; ++i) { prevNode = prevNode->pNext; }

			TNode* nodeToRemove = prevNode->pNext;
			prevNode->pNext = nodeToRemove->pNext;

			delete nodeToRemove;
			--sz;
		}
	}

	TSinglyList& operator=(const TSinglyList& list) {

		if (this != &list)
		{
			TSinglyList tmp(list);
			swap(*this, tmp);
		}
		return *this;
	}

	TSinglyList& operator=(TSinglyList&& list) noexcept {

		swap(*this, list);
		return *this;
	}

	T& operator[](size_t index) {

		if (index >= sz) { throw out_of_range("Index out of bounds"); }

		TNode* p = pFirst;
		for (size_t i = 0; i < index; ++i) { p = p->pNext; }

		return p->value;
	}

	friend void swap(TSinglyList<T>& lhs, TSinglyList<T> rhs)
	{
		swap(lhs.pFirst, rhs.pFirst);
		swap(lhs.sz, rhs.sz);
	}

	friend TSinglyList<T> operator+(const TSinglyList<T>& lhs, const TSinglyList<T>& rhs) {

		TSinglyList<T> result = lhs;

		result += rhs;
		return result;
	}

	friend TSinglyList<T>& operator+=(TSinglyList<T>& lhs, const TSinglyList<T>& rhs) {

		for (const TNode* pNode = rhs.pFirst; pNode != nullptr; pNode = pNode->pNext) 
		{
			lhs.pushBack(pNode->value);
		}
		return lhs;
	}

	friend TSinglyList<T> operator*(TSinglyList<T>& lhs, const TSinglyList<T>& rhs) {

		TSinglyList<T> result;

		for (const TNode* pNode1 = lhs.pFirst; pNode1 != nullptr; pNode1 = pNode1->pNext) 
		{
			for (const TNode* pNode2 = rhs.pFirst; pNode2 != nullptr; pNode2 = pNode2->pNext) 
			{
				result.pushBack(pNode1->value * pNode2->value);
			}
		}
		return result;
	}

	friend ostream& operator<<(ostream& stream, const TSinglyList& list) {

		for (TNode* p = list.pFirst; p != nullptr; p = p->pNext) { stream << p->value; }

		return stream;
	}

	~TSinglyList() {

		TNode* p;
		while (pFirst != nullptr)
		{
			p = pFirst;
			pFirst = pFirst->pNext;
			delete p;
		}
	}
};