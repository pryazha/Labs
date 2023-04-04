#include <iostream>
using namespace std;

int const SIZE = 10;
int Stack[SIZE];
int top = -1;

bool isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

void push(int value)
{
	if (top == SIZE - 1)
		cout << "Stack is full." << endl;
	else
	{
		top++;
		Stack[top] = value;
	}
}

void displayStack();
void pop()
{
	if (isEmpty())
		cout << "Stack is empty." << endl;
	else
	{
		top--;
		cout << "Element at top is deleted." << endl;
		displayStack();
	}
}

void displayStack()
{
	if (isEmpty())
		cout << "Stack is empty." << endl;
	else
	{
		for (int i = 0; i <= top; i++)
			cout << Stack[i] << " ";
		cout << endl;
	}
}

void showTop()
{
	if (isEmpty())
		cout << "Stack is empty." << endl;
	else
		cout << "Element at top is: " << Stack[top] << endl;
}

int main()
{
	cout << "Enter elements of stack: ";
	for (int i = 0; i < SIZE; i++)
	{
		int value;
		cin >> value;
		push(value);
	}
	
	showTop();

	pop();

	showTop();

	int value;
	cout << "Enter element value: ";
	cin >> value;
	push(value);
	displayStack();

	cout << "Enter element value: ";
	cin >> value;
	push(value);
	displayStack();

	return 0;
}