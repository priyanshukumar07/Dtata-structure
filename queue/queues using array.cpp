#include<iostream>
using namespace std;


class queue
{
    public:
    int front,rear;
    int arr[5];

    // constructor
    queue()
    {
    	front = rear =-1;
    }
    
    //  empty fun
    bool is_empty()
    {
    	if(front == -1 && rear == -1)
    	return true;
    	else
    	return false;
}
	//	equeue is full?
	bool is_full()
	{
		if(rear == 4)
		return true;
		else
		return false;
			
	}
	
	//  enqueue fun
    void enqueue( int value)
    {
    	if(is_full())
    	{
    		cout<<"Queue overflow!\n";
    		return;
		}
		else if(is_empty())
		{
			front = rear = 0;
		}
		else
		{
			rear++;
		}
		arr[rear] = value;
	}
	
	//  dequeue fun
	int dequeue()
	{
		int n ;
		if(is_empty())
		{
			cout<<"Queue is underflow\n";
			return 0;
		}
		else if(front == rear)
		{
			n = arr[front];
			front = rear =-1;
		}
		else
		{
			n =arr[front];
			front++;
		}
		cout<<"Element is dequeue\n";
		return n;
	}
	
	//count fun
	int count()
	{
		return ((rear - front)+1);
	}
	
	//print the queue
	void display()
	{
		if(is_empty())
		{
			cout<<"Queue is Empty\n";
		}
		else
		{
			for (int i = front; i <= rear; i++)
		{
			cout<<arr[i]<<"\t";
			
		}
		cout<<endl;
		}
		
	}
	
	//peek fun
	int peek()
	{
		if(is_empty())
		{
			cout<<"Stack is Empty.\n";
		}
		else
		{
			return(arr[front]);
		}
	}
	 
	//clear the queue
	void  clear()
	{
		while(!is_empty())
		{
			dequeue();
		}
		cout<<"Queue is clear now\n";
	}
	 
};

int main(void)
{
	queue q1;
	int opt,value;
	do
	{
		cout<<"Select the option to perfom operation ? 0 for exit\n";
		cout<<"1.Enqueue\n";
		cout<<"2.Dequeue\n";
		cout<<"3.clear the queue\n";
		cout<<"4.Count\n";
		cout<<"5.peek\n";
		cout<<"6.Display the queue\n";
	    
	    cout<<"\tEnter the option :";
	    cin>>opt;
	    
	    switch(opt)
	    {
	    	case 0:
	    		break;
	    	case 1:
	    		cout<<"Enter the element.";
	    		cin>>value;
	    		q1.enqueue(value);
	    		break;
	    	case 2:
	    		q1.dequeue();
	    		break;
	    	case 3:
	    		q1.clear();
	    		break;
	    	case 4:
	    		cout<<"No of element in the queue :"<<q1.count()<<endl;
	    		break;
	    	case 5:
	    		cout<<"peek element is :"<<q1.peek()<<endl;
	    		break;
	    	case 6:
	    		q1.display();
	    		break;
	    				
		}
		
	}
	while(opt!=0);
	
	

    return 0;
}
