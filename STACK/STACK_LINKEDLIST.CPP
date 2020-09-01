#include<iostream>
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

//template <typename T>
class stack
{
    public:
    Node *top, *temp;
    int count = 0;

    //constructor
    stack()
    {
        top = NULL;
    }

    // destructor   
//    ~stack()
//    {
//        clear();
//    } 

    // is_empty function 
    bool isEmpty()
    {
        return(top==NULL);
    }

    //push function
    void push()
    {
        temp = new Node();
        cout<<"Enter the data:";
        cin>>temp->data;

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
        cout<<"pushed in the stack\n\n";
        

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
            cout<<"Stack is\n";

            temp = top;
            while(temp!=NULL)
            {
                cout<<temp->data<<"\n";
                temp = temp->next;
            }
        }
        

    }

    //pop function
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty\n";
        }
        else
        {
            int n =top->data;
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
        cout<<"Element pop from stack!";
    }

};

// main function //

int main(void)
{
    stack S2;
    int choice;
    

    do
    {
        cout<<"Select the option to perfome any operation . 0 for Exist\n";

        cout<<"1.Push a element in the stack\n";
        cout<<"2.Pop a element from the stack\n";
        cout<<"3.No of elementin the stack\n";
        cout<<"4.Print the stack\n";
        
        cout<<"\nEnter the option:";
        cin>>choice;

        switch(choice)
        {
            case 0:
                break;
            case 1:
                S2.push();
            break;
            case 2:
                S2.pop();
            break;
            case 3:
                cout<<"No of elemet in the stack is:"<<S2.count<<endl;
                break;
            case 4:
                S2.display();
            break;
        }

    } while (choice!=0);
    
    return 0;
}