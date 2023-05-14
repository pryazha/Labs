#include <queue>
#include <list>
#include "Money.h"

bool operator <(const Money& m1, const Money& m2) {
	int temp1 = m1.rub * 100 + m1.kop;
	int temp2 = m2.rub * 100 + m2.kop;
	return temp1 < temp2;
}

priority_queue<Money> make_prQ(int n) {
	priority_queue<Money> q;
	Money m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		q.push(m);
	}
	return q;
}

list<Money> copy_prQ_to_list(priority_queue<Money> q) {
	list<Money> l;
	while (!q.empty()) {
		l.push_back(q.top());
		q.pop();
	}
	return l;
}

priority_queue<Money> copy_list(list<Money> l) {
	priority_queue<Money> q;
	while (!l.empty()) {
		q.push(l.back());
		l.pop_back();
	}
	return q;
}

void print_prQ(priority_queue<Money> q) {
	while (!q.empty()) {
		cout << q.top();
		q.pop();
	}
	cout << "\n";
}

priority_queue<Money> insert_key(priority_queue<Money> q, Money key) {
	list<Money> l = copy_prQ_to_list(q);
	for (auto i : l) {
		if (key == i)
			q.push(i);
	}
	return q;
}
priority_queue<Money> delete_key(priority_queue<Money> q, Money key) {
	list<Money> l = copy_prQ_to_list(q);
	priority_queue<Money> temp;
	for (auto i : l) {
		if (!(key == i))
			temp.push(i);
	}
	return temp;
}

int main() {
	int n;
	cout << "Number of elements: ";
	cin >> n;
	priority_queue<Money> q = make_prQ(n);
	print_prQ(q);

	Money m;
	cout << "Key:\n";
	cin >> m;
	q = insert_key(q, m);
	print_prQ(q);

	cout << "Key of del element:\n";
	cin >> m;
	q = delete_key(q, m);
	print_prQ(q);

	return 0;	
}