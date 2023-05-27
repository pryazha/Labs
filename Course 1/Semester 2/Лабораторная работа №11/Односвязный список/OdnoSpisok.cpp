#include <iostream>
#include <string>

using namespace std;

struct Node
{
	string value;
	Node* next;

	Node(string val)
	{
		value = val;
		next = nullptr;
	}	
};

struct list
{
	Node* first;
	Node* last;

	list()
	{
		first = nullptr;
		last = nullptr;
	}

	bool is_empty()
	{
		return first == nullptr;
	}

	void push_front(string val)
	{
		Node* p = new Node(val);
		if (is_empty())
		{
			first = p;
			last = p;
			return;
		}
		p->next = first;
		first = p;
	}

	void push_back(string val)
	{
		Node* p = new Node(val);
		if (is_empty())
		{
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	void push_before(string val)
	{
		if (is_empty())
			return;
		Node* left = first;	
		Node* right = first->next;
		while (right && right->value != val)
		{
			left = left->next;
			right = right->next;
		} 
		if (!right)
		{
			cout << "This element does not exist" << endl;
			return;
		}

		int number_items;
		cout << "Enter number of items: ";
		cin >> number_items;
		
		cout << "Enter value you want to insert: \n";
		cin.ignore();
		string str;
		getline(cin, str);
		Node* node = new Node(str);
		left->next = node;
		node->next = right;
		left = node;
		for (int i = 1; i < number_items; i++)
		{
			getline(cin, str);
			node = new Node(str);
			left->next = node;
			node->next = right;
			left = node;
		}
	}

	void print()
	{
		if (is_empty())
		{
			cout << "List is empty\n";
			return;
		}

		Node* p = first;
		cout << "List data: ";
		while (p)
		{
			cout << p->value << " ";
			p = p->next;
		}
		cout << endl;
	}

	void remove_first()
	{
		if (is_empty())
			return;
		Node* p = first;
		first = p->next;
		delete p;
	}

	void remove_last()
	{
		if (is_empty())
			return;
		if (first == last)
		{
			remove_first();
			return;
		}
		Node* p = first;
		while (p->next != last)
			p = p->next;
		p->next = nullptr;
		delete last;
		last = p;
	}

	void remove(string val)
	{
		if (is_empty())
			return;
		if (first->value == val)
		{
			remove_first();
			return;
		}
		else if (last->value == val)
		{
			remove_last();
			return;
		}
		Node* slow = first;
		Node* fast = first->next;
		while (fast && fast->value != val)
		{
			fast = fast->next;
			slow = slow->next;
		}
		if (!fast)
		{
			cout << "This element does not exist\n";
			return;
		}
		slow->next = fast->next;
		delete fast;
	}

	void remove_list()
	{
		if (is_empty())
			return;
		Node* p = first;
		while (p)
		{
			remove_first();
			p = p->next;
		}
	}
};

void showMenu()
{
	cout << "\tMenu\n";
	cout << "Enter 0 to end the program\n";
	cout << "Enter 1 to view the list\n";
	cout << "Enter 2 to create a list\n";
	cout << "Enter 3 to add the item to the top of the list\n";
	cout << "Enter 4 to add an item to the end of the list\n";
	cout << "Enter 5 to add multiple elements before the element with the given number\n";
	cout << "Enter 6 to remove an element with given value\n";
	cout << "Enter 7 to delete the list\n";
}

void menu()
{
	int switch_n, size_list;
	string str;
	list l;
	do {
		system("pause");
		system("cls");
		showMenu();
		cin >> switch_n;
		switch(switch_n)
		{
		case 0:
			cout << "The program has ended";
			break;
		case 1:
			l.print();
			break;
		case 2:
			cout << "Enter list size: ";
			cin >> size_list;
			cin.ignore();
			for (int i = 0; i < size_list; i++)
			{
				getline(cin, str);
				l.push_back(str);
			}
			break;
		case 3:
			cout << "Enter value: ";
			cin.ignore();
			getline(cin, str);
			l.push_front(str);
			break;
		case 4:
			cout << "Enter value: ";
			cin.ignore();
			getline(cin, str);
			l.push_back(str);
			break;
		case 5:
			cout << "Enter value: ";
			cin.ignore();
			getline(cin, str);
			l.push_before(str);
			break;
		case 6:
			cout << "Enter value: ";
			cin.ignore();
			getline(cin, str);
			l.remove(str);
			break;
		case 7:
			l.remove_list();
			break;
		}
	}
	while (switch_n != 0);
}

int main()
{
	menu();
	return 0;
}