#include "Abiturient.cpp"

struct Node {
	Object* data;
	Node* next;
	Node* prev;

	Node (Object* data, Node* next = nullptr, Node* prev = nullptr) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

class List {
private:
	Node* head;
	Node* tail;
	int size;

public:
	List();
	List(int);
	~List();

	bool isEmpty();
	void clear();
	void Pop_back();
	void Push_back();
	void Push_back(Object*);
	void Show();
	void Average_age();
};