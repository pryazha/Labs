#pragma once
#include "MySet.h"
#include <algorithm>
#include <ctime>
#include <random>
#include <string>
#include <stack>

class SetCalculator {
public:
	void manualInput(MySet& set);

	void randomFilling(MySet& set);

	void conditionFilling(MySet& set);

	void FillSet(MySet& set);

	MySet Union(MySet& set1, MySet& set2);
	 
	MySet Intersection(MySet& set1, MySet& set2);

	MySet AbsComplement(MySet& set);

	MySet Diff(MySet& set1, MySet& set2);

	MySet SymDiff(MySet& set1, MySet& set2);

	void SetUniversum();

	bool inUniversum(int val);

	string ExpressionInput();

	MySet EvaluateExpr(string tokens, MySet setArr[]);

	int Precedence(char op);

	MySet ApplyOp(MySet& a, MySet& b, char op);

private:
	int minU;
	int maxU;
};

