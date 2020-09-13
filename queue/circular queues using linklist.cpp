#include<iostream>
using namespace std;

//node class
class node
{
    public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next=NULL;
    }

};

//CirQueue class
class cirqueue
{
    public:
    node *front, *rear, *temp;
    
    cirqueue()
    {
    	front = rear = NULL;
	}
	
	//enqueue fun
	void enqueue()
	{
		temp = new node();
		cout<<"Enter the data:";
		cin>>temp->data;
		
		if(rear==NULL)
		{
			front = rear =temp;
			rear->next = front;
		}
		else
		{
			rear->next = temp;
			rear = temp;
			rear->next = front;
		}
		
	}
	
	//dequeue fun
	void dequeue()
	{
		temp = new node();
		temp = front;
		
		if(rear == NULL && front == NULL)
		{
			cout<<"Queue is empty\n";
		}
		else if( front == rear)
		{
			front = rear = 0;
			delete temp;
		}
		else
		{
			front = front->next;
			rear->next = front;
			delete temp;
		}
	}
	
	void display()
	{
		temp = new node();
		temp = front;
		
		if(front == NULL)
		cout<<"Queue is Empty\n";
		
		else
		{
			while(temp->next!=front)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<temp->data;
		}
	}

    

};

// main function 
int main(void)
{
	cirqueue s1;
	 s1.enqueue();
	 s1.enqueue();
	 s1.enqueue();
	 s1.enqueue();
	 s1.dequeue();
	 s1.display();

    return 0;
}