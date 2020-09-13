#include<iostream>
using namespace std;

#define size 5

class queue{
	
	public:
		int front, rear;
		
		int arr[size];
		
		queue()
		{
			front = -1;
			rear = -1;
		}
		
		//is empty fun
		bool is_empty()
		{
			if(front == -1 && rear == -1)
			return true;
			else
			return false;
		}
		
		//is full
		bool is_full()
		{
			if(arr[size]==size-1)
			return true;
			else
			return false;
		}
		// enqueue function
		void enqueue(int value)
		{
			if(is_empty())
			{
				front = rear =0;
				arr[rear] = value;
			}
			else if((rear+1)%size == front)
			cout<<"Queue is full\n";
			else
			{
				rear =(rear+1)%size;
				arr[rear] = value;
			}
			
		}
		
		//dequeue function
		int dequeue()
		{
			if(is_empty())
			cout<<"Queue is Empty\n";

			else if(front == rear)
			{
				front = rear = -1;
				return 0;
			}
			else 
			{
				front =(front+1)%size;
			}
			
			
		}
		
		//display the queue
		void display()
		{
			int i = front;
			if(is_empty())
			{
				cout<<"Queue is empty";
	
			}
			else
			{
				cout<<"Queue is : ";
				while(i!=rear)
			{
				cout<<arr[i]<<" ";
				i=(i+1)%size;
			 }
			 cout<<arr[rear]<<" ";
			 } 
		}
		
	
};
int main(void)
{
	queue s1;
	int opt,value;
	do
	{
	cout<<"Select the option . 0 for exit\n";
	cout<<"1.Enqueue\n";
	cout<<"2.Dequeue\n";
	cout<<"3.isEmpty\n";
	cout<<"4.Display the queue\n";
	
	cout<<"Enter the option:";
	cin>>opt;
	
	switch(opt)
	{
		case 0:
			break;
		case 1:
			cout<<"Enter the element :";
			cin>>value;
			s1.enqueue(value);
			break;
		case 2:
			s1.dequeue();
			break;
		case 3:
			s1.is_empty();
			break;
		case 4:
			s1.display();
			break;
			
	}
	}
	while(opt!=0);
	

    return 0;
}