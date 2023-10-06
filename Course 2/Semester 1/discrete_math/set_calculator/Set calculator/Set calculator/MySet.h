#pragma once
#include <iostream>
#include <vector>
using namespace std;

class MySet {
public:
	MySet();

	int size() { return set.size(); }

	void AddAtBegin(int val);

	void AddAtEnd(int val);

	void Insert(int index, int val);

	bool Find(int val);

	vector<int>::iterator& Get(int val);

	void Print();

	vector<int> set;
};

