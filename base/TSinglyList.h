#ifndef __TSINGLYLIST_H__
#define __TSINGLYLIST_H__

#include <iostream>
#include <utility>
#include <stdexcept>

using namespace std;

template<typename T>
class TSinglyList {
private:
	struct TNode {
		T value;
		TNode* pNext;
	};

	TNode* pFirst;
	size_t sz;

	TNode* ToPos(size_t pos) const {
		if (pos >= sz) {
			throw out_of_range("Index out of range");
		}
		TNode* current = pFirst;
		for (size_t i = 0; i < pos; ++i) {
			current = current->pNext;
		}
		return current;
	}

public:
	TSinglyList() : pFirst(nullptr), sz(0) {}

	~TSinglyList() {
		Clear();
	}

	TSinglyList(const TSinglyList& other) : pFirst(nullptr), sz(0) {
		TNode* current = other.pFirst;
		while (current != nullptr) {
			PushBack(current->value);
			current = current->pNext;
		}
	}

	TSinglyList& operator=(TSinglyList other) {
		swap(pFirst, other.pFirst);
		swap(sz, other.sz);
		return *this;
	}

	void PushFront(const T& val) {
		TNode* node = new TNode{ val, pFirst };
		pFirst = node;
		sz++;
	}

	void PushBack(const T& val) {
		if (pFirst == nullptr) {
			pFirst = new TNode{ val, nullptr };
		}
		else {
			TNode* current = pFirst;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}
			current->pNext = new TNode{ val, nullptr };
		}
		sz++;
	}

	void PopFront() {
		if (pFirst == nullptr) {
			throw out_of_range("List is empty");
		}
		TNode* temp = pFirst;
		pFirst = pFirst->pNext;
		delete temp;
		sz--;
	}

	void InsertAfter(size_t pos, const T& val) {
		TNode* prevNode = ToPos(pos);
		TNode* newNode = new TNode{ val, prevNode->pNext };
		prevNode->pNext = newNode;
		sz++;
	}

	void EraseAfter(size_t pos) {
		if (pos >= sz) {
			throw out_of_range("Index out of range");
		}
		TNode* prevNode = ToPos(pos);
		TNode* deleteNode = prevNode->pNext;
		prevNode->pNext = deleteNode->pNext;
		delete deleteNode;
		sz--;
	}

	size_t Size() const noexcept {
		return sz;
	}

	bool IsEmpty() const noexcept {
		return sz == 0;
	}

	T& Front() noexcept {
		if (pFirst == nullptr) {
			throw out_of_range("List is empty");
		}
		return pFirst->value;
	}

	T& At(size_t pos) {
		return ToPos(pos)->value;
	}

	const T& At(size_t pos) const {
		return ToPos(pos)->value;
	}

	void Clear() {
		while (!IsEmpty()) {
			PopFront();
		}
	}
};


#endif // __TLIST_H__
