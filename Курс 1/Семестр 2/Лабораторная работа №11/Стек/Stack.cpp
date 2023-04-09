#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

struct Stack
{
    Stack() 
    {
        top = NULL;
    }

    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void show_Stack() 
    {
        if (top == NULL) 
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        while (temp != NULL) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void addBefore(int value) 
    {
        Node* temp = top;
        Node* prev = NULL;
        while (temp != NULL && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Value not found" << endl;
            return;
        }

        int NumEl, tempValue;
        cout << "Enter number of elements: ";
        cin >> NumEl;
        cout << "Enter values:\n";
        cin >> tempValue;
        if (prev == NULL)
        {
            Node* newNode = new Node(tempValue);
            newNode->next = top;
            top = newNode;
            for (int i = 1; i < NumEl; i++)
            {
                cin >> tempValue;
                Node* newNode = new Node(tempValue);
                newNode->next = top;
                top = newNode;
            }
        }
        else
        {
            Node* newNode = new Node(tempValue);
            prev->next = newNode;
            newNode->next = temp;
            prev = newNode;
            for (int i = 1; i < NumEl; i++)
            {
                cin >> tempValue;
                Node* newNode = new Node(tempValue);
                prev->next = newNode;
                newNode->next = temp;
                prev = newNode;
            }
        }
    }

    void fill_stack()
    {
        int size;
        cout << "Enter size of Stack: ";
        cin >> size;

        cout << "Enter values of Stack:\n";
        int value;
        for (int i = 0; i < size; i++)
        {
            cin >> value;
            this->push(value);
        }
    }

    void clear_stack()
    {
        Node* temp = top;
        while (temp != NULL)
        {
            temp = temp->next;
            this->pop();
        }
    }

private:
    Node* top;
};

void showMenu()
{
    cout << "\tMenu\n";
    cout << "Enter 0 to end the program\n";
    cout << "Enter 1 to view the Stack\n";
    cout << "Enter 2 to create a Stack\n";
    cout << "Enter 3 to add the item to the top of the Stack\n";
    cout << "Enter 4 to add the items before element with given value\n";
    cout << "Enter 5 to remove top element\n";
    cout << "Enter 6 to clear stack\n";
}

void menu()
{
    int switch_n, value, key;
    Stack s;
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
            s.show_Stack();
            break;
        case 2:
            s.fill_stack();
            break;
        case 3:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;
        case 4:
            cout << "Enter value: ";
            cin >> value;
            s.addBefore(value);
            break;
        case 5:
            s.pop();
            break;
        case 6:
            s.clear_stack();
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