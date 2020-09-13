#include<iostream>
using namespace std;

class node
{
	public:
		int data;
	node *next;
	
	node()
	{
		data = 0;
		next = NULL;
	}	
	
};

//queue class
class queue{
	public:
		node *front, *rear,*temp;
	
	queue()
	{
		front = rear = NULL;
		
	}
	
	//check queue is empty
	bool is_empty()
	{
		if(front==NULL)
		return true;
		else
		return false;
	}
	
	// enqueue function
	void enqueue()
	{
		temp = new node();
		cout<<"Enter the data :";
		cin>>temp->data;
		
		if(rear==NULL)
		{
			front = rear = temp;
			return;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
//		cout<<"A element is enqueue in stack \n";
	}
	
	//dequeue function
	void dequeue()
	{
		if(is_empty())
		{
			cout<<"Queue is Empty\n";
			return;
		}
		temp = front;
		front = front->next;
		
		if(front==NULL)
		{
			rear = NULL;
		}
		delete temp;
//		cout<<"A element is dequeue form stack \n";	
	}
	
	//display the queue
	void display()
	{
		temp = front;
		if(is_empty())
		{
			cout<<"Queue is empty\n";
			return ;
		}
		while( temp != NULL)
		{
			cout<<"-->"<<temp->data;
			temp = temp->next;
		}
		
	}
	
	//count function
	int count()
	{
		int count=1;
		if(is_empty())
		cout<<"Stack is empty\n";
		else
		{
			temp=front;
			while(temp->next!=NULL)
			{
				count++;
				temp=temp->next;
			}
		}
		return count;
	}
	
    //	peek function
    int peek()
    {
    	if(is_empty())
    	cout<<"Stack is empty\n";
    	else
    	return(front->data);
	}
	
	//clear the queue
	void clear()
	{
		if(is_empty())
	    {
	    	cout<<"queue is empty\n";
	    	return ;
		}
		else
		{
			int n=0;
			while(n<=count())
			{
				dequeue();
				n++;
			}
			cout<<"Queue is clear now.\n";
		}
		
	}

};

//main fucntion
int main(void)
{
	queue s1;
	int opt,value;
	do
	{
		cout<<"\nSelect the option to perfom operation ? 0 for exit\n";
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
	    		s1.enqueue();
	    		break;
	    	case 2:
	    		s1.dequeue();
	    		break;
	    	case 3:
	    		s1.clear();
	    		break;
	    	case 4:
	    		cout<<"No of element in the queue :"<<s1.count()<<endl;
	    		break;
	    	case 5:
	    		cout<<"peek element is :"<<s1.peek()<<endl;
	    		break;
	    	case 6:
	    		s1.display();
	    		break;
	    				
		}
		
	}
	while(opt!=0);
	

	return 0;
}