#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdexcept>

using namespace std;

template <class TELEM>
class LinkedList {
	struct Node {                           // ����
		Node* next, * prev;                 // ��������� �� �������� � ��������� ����
		TELEM data;                         // ������ ����
		Node() = delete;                    // ����������� �� ��������� ����������
		Node(TELEM d);                      // �����������-�������������
	};
private:
	Node* front, * back;                    // ��������� �� ������ � ��������� ������� ������
	size_t size = 0;						// ���-�� ��������� � ������
	Node* at(const size_t index) const;		// �������� ���� �� ������� 
public:
	LinkedList();							// ����������� �� ���������
	LinkedList(const LinkedList& l);        // ����������� �����������
	~LinkedList();							// ����������
	bool empty() const;						// �������� �� ������� ������
	void push_front(TELEM el);				// �������� ������� � ������
	void push_back(TELEM el);				// �������� ������� � �����
	void pop_front();						// ������� ������ �������
	void pop_back();						// ������� ������ �������
	void  erase(int index);					// ������� ������� �� �������
	void insert(int index, const TELEM& el);// �������� ������� �� �������
	void insert_in_order(TELEM el);         // �������� �� �������
	TELEM operator[](const size_t index);   // �������� �������� �������� �� �������
	const TELEM operator[](const size_t index) const;

	TELEM& get_front();						// �������
	TELEM& get_back();
	const TELEM& get_front() const;
	const TELEM& get_back() const;
	size_t get_size() const;

	class iterator {

	};
};

template <class TELEM>
inline LinkedList<TELEM>::LinkedList() { front = back = nullptr; }

template <class TELEM>
inline LinkedList<TELEM>::LinkedList(const LinkedList& l) : size(l.size), front(nullptr), back(nullptr) {
	if (!l.front) return;
	Node* pNew = front = new Node{ *l.front };
	for (; pNew->next; pNew = pNew->next) {
		pNew->prev = back;
		pNew->next = new Node{ *pNew->next };
		back = pNew;
	}
}

template <class TELEM>
bool LinkedList<TELEM>::empty() const { return (size == 0); }

template <class TELEM>
size_t LinkedList<TELEM>::get_size() const { return size; }

template <class TELEM>
void LinkedList<TELEM>::push_front(TELEM el) {
	Node* tmp = new Node(el);
	tmp->next = front;
	if (front != nullptr)
		front->prev = tmp;
	if (back == nullptr)
		back = tmp;
	front = tmp;
	size++;
}

template <class TELEM>
void LinkedList<TELEM>::push_back(TELEM el) {
	Node* tmp = new Node(el);
	tmp->prev = back;
	if (back != nullptr)
		back->next = tmp;
	if (front == nullptr)
		front = tmp;
	back = tmp;
	size++;
}

template <class TELEM>
void LinkedList<TELEM>::pop_front() {
	if (empty()) throw out_of_range("List is empty");
	Node* tmp = front->next;
	if (tmp != nullptr)
		tmp->prev = nullptr;
	else
		back = nullptr;
	delete front;
	front = tmp;
	size--;
}

template <class TELEM>
void LinkedList<TELEM>::pop_back() {
	if (empty()) throw out_of_range("List is empty");
	Node* tmp = back->prev;
	if (tmp != nullptr)
		tmp->next = nullptr;
	else
		front = nullptr;
	delete back;
	back = tmp;
	size--;
}

template <class TELEM>
TELEM& LinkedList<TELEM>::get_front() { if (empty()) throw out_of_range("List is empty"); return front->data; }

template <class TELEM>
TELEM& LinkedList<TELEM>::get_back() { if (empty()) throw out_of_range("List is empty"); return back->data; }

template <class TELEM>
void LinkedList<TELEM>::erase(int index) {
	Node* tmp = at(index);
	if (tmp == nullptr) throw out_of_range("List is empty");
	else if (index < 0 || index > size) throw out_of_range("Invalid index");
	if (tmp->prev == nullptr) {
		pop_front();
		return;
	}
	else if (tmp->next == nullptr) {
		pop_back();
		return;
	}
	else {
		Node* left = tmp->prev;
		Node* right = tmp->next;
		left->next = right;
		right->prev = left;
		delete tmp;
		size--;
	}
}

template <class TELEM>
void LinkedList<TELEM>::insert(int index, const TELEM& el) {
	if (index < 1) throw out_of_range("Negative index");
	else if (empty() || index > size) push_back(el);
	else if (size == 1) { index < size ? push_front(el) : push_back(el); }
	else {
		Node* right = at(index);
		Node* left = right->prev;
		Node* tmp = new Node(el);
		tmp->next = right;
		tmp->prev = left;
		left->next = tmp;
		right->prev = tmp;
		size++;
	}
}

template <class TELEM>
void LinkedList<TELEM>::insert_in_order(TELEM el) {
	if (empty()) push_back(el);
	else if (size == 1) { front->data > el ? push_front(el) : push_back(el); }
	else {
		if (front->data > el) {
			push_front(el);
			return;
		}
		Node* left = front;
		Node* right = left->next;
		Node* tmp = new Node(el);
		while (right && right->data <= tmp->data) {
			left = left->next; right = right->next;
		}
		if (!right) {
			push_back(el);
			delete tmp;
		}
		else {
			tmp->next = right;
			tmp->prev = left;
			left->next = tmp;
			right->prev = tmp;
			size++;
		}
	}
}

template <class TELEM>
TELEM LinkedList<TELEM>::operator[](const size_t index) {
	if (index < 0 || index > size) throw out_of_range("Invalid nidex");
	return at(index)->data;
}

template<class TELEM>
inline const TELEM LinkedList<TELEM>::operator[](const size_t index) const{
	if (index < 0 || index > size) throw out_of_range("Invalid nidex");
	return at(index)->data;
}

template <class TELEM>
LinkedList<TELEM>::~LinkedList() { while (!empty()) pop_back(); }

template <class TELEM>
typename LinkedList<TELEM>::Node* LinkedList<TELEM>::at(const size_t index) const {
	Node* tmp = front;
	for (size_t i = 0; i != index; i++) {
		if (tmp == nullptr)
			return tmp;
		tmp = tmp->next;
	}
	return tmp;
}

template <class TELEM>
LinkedList<TELEM>::Node::Node(TELEM d) : data(d) { next = prev = nullptr; }

template<class TELEM>
inline const TELEM& LinkedList<TELEM>::get_front() const { return front; }

template<class TELEM>
inline const TELEM& LinkedList<TELEM>::get_back() const { return back; }
#endif

