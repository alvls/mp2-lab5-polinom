struct Monom {
	int coef;
	size_t  deg;
};
struct Node {
	Monom date;
	Node* pNext;
	Node* pLast;
	Node(Monom _val) : date(_val), pNext(nullptr), pLast(nullptr) {}
};
class MyList {
	Node* pFirst = nullptr;
	Node* pLast = nullptr;
	size_t size = 0;
public:
	size_t GetSize() { return size; }
	Node* GetpFirst() { return pFirst; }
	Node* GetpLast() { return pLast; }
	void Push(Monom new_monom) {
		Node* tmp1 = new Node(new_monom);
		size++;
		if (pFirst == nullptr) {
			pFirst = tmp1;
			pLast = tmp1;
			return;
		}
		pLast->pNext = tmp1;
		tmp1->pLast = pLast;
		pLast = tmp1;
	}
};