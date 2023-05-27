#include "List.h"

List::List() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}
List::~List() {
	clear();
}
void List::clear() {
	while (!isEmpty())
		Pop_back();
}
void List::Pop_back() {
	if (isEmpty())
		throw runtime_error("List is empty");
	Object* data = tail->data;
	Node* temp = tail;
	tail = tail->prev;
	delete temp;
	if (tail == nullptr)
		head = nullptr;
	else
		tail->next = nullptr;
	size--;
}

List::List(int size) {
	if (size < 0)
		throw invalid_argument("Size cannot be negative");
	head = nullptr;
	tail = nullptr;
	this->size = 0;
	for (int i = 0; i < size; i++)
		Push_back();
}
void List::Push_back() {
	Object *p;
	cout << "1.Person" << endl;
	cout << "2.Abiturient" << endl;
	int y;
	cin >> y;
	if (y == 1) {
		Person* a = new Person;
		a->Input();
		p = a;

		Node* newNode = new Node(p);
		if (isEmpty()) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	else {
		if (y == 2) {
			Abiturient* b = new Abiturient;
			b->Input();
			p = b;

			Node* newNode = new Node(p);
			if (isEmpty()) {
				head = newNode;
				tail = newNode;
			}
			else {
				newNode->prev = tail;
				tail->next = newNode;
				tail = newNode;
			}
			size++;
		}
		else
			return;
	}
}
void List::Push_back(Object* p) {
	Node* newNode = new Node(p);
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}
bool List::isEmpty() {
	return size == 0;
}

void List::Show() {
	Node* current = head;
	cout << "List:\n";
	while (current != nullptr) {
		Object* p = current->data;
		p->Show();
		cout << endl;
		current = current->next;
	}
	cout << "\n";
}