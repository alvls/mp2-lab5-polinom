#ifndef __SORTED_LIST__
#define __SORTED_LIST__

#include "linked_list.h"

template <class TELEM>
class SortedList : public LinkedList<TELEM> {
public:
	void insert_in_order(TELEM el);
};

template <class TELEM>
void SortedList<TELEM>::insert_in_order(TELEM el) {
	if (this->size == 0) {
		this->push_back(el);
		return;
	}
	if (this->size == 1) {
		if (this->front->data > el) {
			this->push_front(el);
		}
		else {
			this->push_back(el);
		}
		return;
	}
	if (this->front->data > el) {
		this->push_front(el);
		return;
	}
	typename LinkedList<TELEM>::Node* left = this->front;
	typename LinkedList<TELEM>::Node* right = left->next;
	while (right && right->data <= el) {
		left = left->next; 
		right = right->next;
	}
	if (!right) {
		this->push_back(el);
		return;
	}
	typename LinkedList<TELEM>::Node* tmp = new typename LinkedList<TELEM>::Node{ el };
	tmp->next = right;
	tmp->prev = left;
	left->next = tmp;
	right->prev = tmp;
	this->size++;
}
#endif