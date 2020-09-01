#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;


class Node
{
    public:
    int data;
    Node *next;

    Node()
    {
        data=0;
        next=NULL;
    }

};

template<typename T>
class stack
{
    public:
    Node *top, *temp;
    int count;

    //constructor
    stack()
    {
        count=0;
        top=NULL;
    }

    // is_empty function 
    bool isEmpty()
    {
        return(top==NULL);
    }

     //push function
    void push( T n )
    {
        temp = new Node();
        temp->data = n;

        if (isEmpty())
        {
            temp->next = NULL;
            top = temp;
        }
        else
        {
            temp->next =top;
            top = temp;
        }
        count++;

    }

    //pop function
    T pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty\n";
            return 0;
        }
        else
        {
            T n =top->data;
            if(top->next == NULL)
            {
                delete top;
                top = NULL;
            }
            else
            {
                temp = top;
                top = top->next;
                delete temp;
            }
            count --;
            return n;
        }
        
    }

    //display function
    void display()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty\n";
        }
        else
        {
            temp = top;
            while(temp!=NULL)
            {
                cout<<temp->data;
                temp = temp->next;
            }
        }
        

    }

};

void tostack(string &n, stack<int> &s)
{
	for (int i = 0; i < n.length(); ++i)
	{
		s.push((int)(n[i] - 48));
	}
}

void add(stack<int> &s1, stack<int> &s2, stack<int> &sum)
{
	int n1, n2, carry = 0;
	int itr = (s2.count > s1.count) ? s2.count : s1.count;
	for (int i = 0; i < itr; i++)
	{
		n1 = s1.isEmpty() ? 0 : s1.pop();
		n2 = s2.isEmpty() ? 0 : s2.pop();

		sum.push((n1 + n2 + carry) % 10);
		carry = (n1 + n2 + carry) / 10;
	}
	if (carry > 0)
		sum.push(carry);
}

int main()
{
    
	string n;
	stack<int> s1, s2, s3;
	cout << "Enter 1st number: ";
	cin >> n;
	tostack(n, s1);
	cout << "Enter 2nd number: ";
	cin >> n;
	tostack(n, s2);
	cout << "\nSum: ";
	add(s1, s2, s3);
	s3.display();
	cout << endl;
}
