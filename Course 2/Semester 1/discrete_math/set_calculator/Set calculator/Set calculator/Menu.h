#pragma once
#include "SetCalculator.h"

class Menu
{
public:
	void MenuEnter();

	void Print();

	void PrintSetArray(MySet setArr[], int size);

	int SelectSet(string message);
};

