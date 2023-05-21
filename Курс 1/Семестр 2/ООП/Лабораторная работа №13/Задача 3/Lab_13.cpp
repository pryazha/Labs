#include "Money.h"
#include <map>
#include <list>
#include <algorithm>

typedef list<Money> TList;
typedef multimap<int, Money> tmap;
Money s;

TList make_list(int numberOfElements) {
	Money temp;
	TList newList;
	for (int i = 0; i < numberOfElements; i++) {
		cin >> temp;
		newList.push_back(temp);
	}
	return newList;
}
tmap make_map(int n) {
	tmap Map;
	Money m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		Map.insert(make_pair(i, m));
	}
	return Map;
}
void print_map(tmap Map) {
	for (auto i : Map)
		cout << i.first << " : " << i.second;
}
void print_list(TList List) {
	for (auto it = List.begin(); it != List.end(); it++)
		cout << *it;
	cout << "\n";
}
struct Greater_s {
	bool operator() (Money m) {
		if (m > s)
			return true;
		else
			return false;
	}
};
struct Comp_less {
	bool operator() (Money m1, Money m2) {
		if (m1 > m2)
			return true;
		else
			return false;
	}
};
struct Equal_s {
	bool operator() (Money m) {
		return m == s;
	}
};

// 3
TList insert_key(TList List, Money key) {
	TList::iterator it;
	for (auto it = List.begin(); it != List.end(); it++)
		if (*(it) == key)
			break;
	if (it == List.end()) {
		cout << "No such element\n";
		return List;
	}	
	int newNumber;
	cout << "Enter number of element: ";
	cin >> newNumber;

	it = List.begin();
	for (int tempCount = 1; tempCount <= newNumber; tempCount++, it++);
	List.insert(it, key);

	return List;
}

// 4
TList delete_key(TList List) {
	TList::iterator it;
	
	cout << "Enter key of delete element:\n";
	cin >> s;

	it = find_if(List.begin(), List.end(), Equal_s());
	if (it == List.end()) {
		cout << "No such element!\n";
		return List;
	}

	List.erase(it);

	return List;
}

// 5
TList decrase_elements(TList List) {
	Money max = *(List.begin());
	Money min = *(List.begin());

	for (auto it = List.begin(); it != List.end(); it++) {
		if (max < *(it))
			max = *(it);
		if (min > *(it))
			min = *(it);
	}

	cout << "max:\n" << max << "\nmin:\n" << min << "\n";

	Money decreaseValue = max - min;

	for (auto it = List.begin(); it != List.end(); it++)
		*(it) = *(it) - decreaseValue;

	return List;
}

int main() {
	int n;
	cout << "Number of elements: ";
	cin >> n;
	TList List;
	List = make_list(n);
	print_list(List);
    
    // 3
	Money m;
	cout << "Enter insert element:\n";
	cin >> m;
	List = insert_key(List, m);
	print_list(List);

	// 4
	List = delete_key(List);
	print_list(List);

	// 5
	List = decrase_elements(List);
	print_list(List);

	return 0;
}