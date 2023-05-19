#include <iostream>
#include <map>
using namespace std;
typedef map<int, double> TMap;
typedef TMap::iterator it;

TMap make_map(int n) {
	TMap m;
	int temp;
	for (int i = 0; i < n; i++) {
		cout << "Element " << i + 1 << ": ";
		cin >> temp;
		m.insert(make_pair(i, temp));
	}
	return m;
}
void print_map(TMap m) {
	for (int i = 0; i < m.size(); i++)
		cout << i << " : " << m[i] << "\n";
}

// 1
void insert_key(TMap& m, const int key) {
	int i;
	for (i = 0; i < m.size(); i++)
		if (key == i)
			break;
	if (i == m.size()) {
		cout << "Element doesn't exist\n";
		return;
	}
	m.insert(make_pair(m.size(), m[i]));
}
// 2
TMap delete_key(TMap m, const int key) {
	TMap temp;
	int newPosition = 0;
	for (int i = 0; i < m.size(); i++) {
		if (key != i) {
			temp.insert(make_pair(newPosition, m[i]));
			newPosition++;
		}
	}
	return temp;
}
// 3
TMap decrease_elements(TMap m) {
	double max = m[0];
	double min = m[0];

	for (int i = 1; i < m.size(); i++) {
			if (m[i] > max)
				max = m[i];
			if (m[i] < min)
				min = m[i];
	}

	cout << "Max: " << max << "\nMin: " << min << "\n";
	double decrease = max - min;
	TMap temp;
	for (int i = 0; i < m.size(); i++) {
		temp.insert(make_pair(i, m[i] - decrease));
	}

	return temp;
}

int main() {
	int n;
	cout << "Number of elements: ";
	cin >> n;
	TMap m = make_map(n);
	print_map(m);

	double key;
	cout << "Key: ";
	cin >> key;
	insert_key(m, key);
	print_map(m);

	cout << "Key of delete element: ";
	cin >> key;
	m = delete_key(m, key);
	print_map(m);

	cout << "Map after decrease:\n";
	m = decrease_elements(m);
	print_map(m);

	system("pause");
	return 0;
}