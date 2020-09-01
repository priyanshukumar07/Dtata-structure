#include <iostream>
#include <conio.h>
using namespace std;

class Stack
{
private:
    int top;
    int arr[5];

public:
	// constructor //
    Stack()
    {
        top = -1;

        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    // isEmpty function //
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    // isfull function //
    bool isFull()
    {
        if (top == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    // push function //
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow." << endl;
        }
        else
        {
            top++; //top=0
            arr[top] = value;
        }
    }
    
    // pop  function //
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow." << endl;
            return 0;
        }
        else
        {
            int popvalue = top;
            arr[top] = 0;
            top--;
            return popvalue;
        }
    }

    // count function //
    int count()
    {
        return (top + 1);
    }
     
     // peek function //
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << "Stack Underflow." << endl;
        }
        else
        {
            return arr[pos];
        }
    }

    // change a value at any location //
    void change(int pos, int value)
    {
        arr[pos] = value;
        cout << "Value is change at location " << pos << endl;
    }

    // print the stack //
    void Display()
    {
        cout << "All value of Stack are:" << endl;
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{

    Stack S1;
    int choice, value, position;

    do
    {
        cout<< "What operation do you perform? Selct the no. Enter 0 for exit." << endl;
        cout<< "1.Push()"<<endl;
        cout<< "2.Pop()"<<endl;
        cout<< "3.isEmpty()"<<endl;
        cout<< "4.isFull()"<<endl;
        cout<< "5.peek()"<<endl;
        cout<< "6.count()"<<endl;
        cout<< "7.change()"<<endl;
        cout<< "8.Display()"<<endl;
        cout<< "9.Clear Screen()"<< endl;

        cin>>choice;
        switch(choice)
        {

        case 0:
            break;

        case 1:
            cout << "Enter the value:";
            cin >> value;
            S1.push(value);
            break;

        case 2:
            cout << "Pop a value from the stack:" << S1.pop() << endl;
            break;

        case 3:
            if (S1.isEmpty())
            {
                cout<<"Stack is Empty." << endl;
            }
            else
                cout<<"Stack is not Empty." << endl;
            break;

        case 4:
            if (S1.isFull())
            {
                cout << "Stack is Full." << endl;
            }
            else
                cout << "Stack is not Full." << endl;
            break;

        case 5:
            cout << "Enter the position to peek the value:";
            cin >> position;
            cout << "The value is :" << S1.peek(position);
            break;

        case 6:
            cout << "Number of items in the stack is: " << S1.count() << endl;
            break;

        case 7:
            cout << "Enter the position to change the value:";
            cin >> position;
            cout << "Enter the value:";
            cin >> value;
            cout << endl;
            S1.change(position, value);
            break;

        case 8:
            cout << "Values in stack" << endl;
            S1.Display();
            break;

        case 9:
            system("cls");
            break;

        default:
            cout << "Enter proper number.";
        }

    } while (choice != 0);

    return 0;
}