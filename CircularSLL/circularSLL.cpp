#include<iostream.h>
#include<conio.h>
class node
{
    public:
    int data;
    node *temp,*tail,*ptr,*prv,*next;
    node()
    {
        data=0;
        temp=NULL;
        tail=NULL;
        ptr=NULL;
        prv=NULL;
        next=NULL;
    }


};
class CircularSinglyLinkedList
{
    public:
    node *head;
    CircularSinglyLinkedList()
    {
        head=tail=NULL;
    }
    ~CircularSinglyLinkedList()
    {
        ptr=head;
        cout<<"deleting memory";
        while(ptr!=NULL)
        {
        temp=ptr->next;
        delete ptr;
        ptr=temp;
        }
    }

     int  count();
     void del_from_end();
     void del_from_begin();
     void del_at_locat();
     void insert_at_begin();
     void insert_at_end();
     void insert_at_locat();
     void display();
     void Search();
     void reverse();

};

void CircularSinglyLinkedList::del_from_end()
{
  if (tail==NULL)
	{
		if (tail->next==tail)
		{
			delete tail;
			tail=NULL;
		}
		else
		{
			ptr=tail;
			do
			{
				ptr=ptr->next;
			} 
            while(ptr->next!=tail);
			ptr->next=tail->next;
			delete tail;
			tail=ptr;
		}
		cout <<"Node deleted from end"<<endl;
	}   
}
void CircularSinglyLinkedList::del_from_begin()
{
    if (tail==NULL)
	{
		temp=tail->next;
		if (tail->next==tail)
		{
			delete temp;
			tail=NULL;
		}
		else
		{
			tail->next=temp->next;
			delete temp;
		}
		cout <<"deleted node from beginning!"<<endl;
	}
}
void CircularSinglyLinkedList::del_at_locat()
{
    int loc;
    cout<<"enter the location of node to be deleted="<<endl;
    cin>>loc;
    ptr=tail->next;
    for(int i=1;i<loc-1;i++)
    {
        ptr=ptr->next;
    }
    if (ptr->next==tail)
    {
        delete tail;
		tail=NULL;
    }
				
			else
			{
				temp=ptr->next;
				ptr->next=temp->next;
				delete temp;
                    
                    cout<<"node is deleted at loc"<<endl;
            }            
}
void CircularSinglyLinkedList::insert_at_begin()
{
    temp=new node;
	cout<<"enter the node data  "<<endl;
	cin>>temp->data;
	if (tail==NULL)
	{
		tail=temp;
		tail->next=tail;
	}
	else
	{
		temp->next=tail->next;
		tail->next=temp;
	}
	cout <<"Node is inseted"<<endl;
}
void CircularSinglyLinkedList::insert_at_end()
{
    temp=new node;
	cout<<"Enter the node data  "<<endl;
	cin>>temp->data;
	if (tail==NULL)
	{
		tail=temp;
		tail->next=tail;
	}
	else
	{
		temp->next=tail->next;
		tail->next=temp;
		tail=temp;
	}
	cout<<"Node is inserted"<<endl;
}
void CircularSinglyLinkedList::insert_at_locat()
{
      int loc;
    temp=new node;
    cout<<"enter the loc to insert data"<<endl;
    cin>>loc;
    cout<<"enter the data of node"<<endl;
    cin>>temp->data;
    ptr=tail->next;
    for(int i=1;i<loc-1;i++)
    {
        ptr=ptr->next;    
    }
    if(tail==NULL)
    {
        tail=temp;
		tail->next=tail       
    }
    else if(ptr==tail)
    {
        temp->next=tail->next;
		tail->next=temp;
		tail=temp;
    }
    else
    {
        cout<<"Enter the node data : ";
		cin>>temp->data;
		temp->next=ptr->next;
		ptr->next=temp;
		cout<<"Node is inserted"<<endl;
    }
    
    
}
int CircularSinglyLinkedList::count()
{
    int count=0;
    ptr=tail;
    do
    {
        ++count;
        ptr=ptr->next;
    }
    while(ptr != tail);
    return count;
}
void CircularSinglyLinkedList::search()
{
    if (tail==NULL)
	{
		int data;
		int loc = 0;
		bool contains=false;
		cout << "Enter the node data to be searched : "<<endl;
		cin >> data;
		ptr=tail;
		do
		{
            ptr=ptr->next;
			++loc;
			if (ptr->data==data)
			{
				contains=true;
				break;
			}
        }
			while(ptr!=tail)

		if (contains==1)
			cout<<"Data found at location "<<loc<<" in the list" <<endl;
		else
			cout<<"Data not found in the list"<<endl;
	}
}
void CircularSinglyLinkedList::reverse()
{
	if ((tail==NULL) && (tail->next!=tail))
	{
	        node *temp1=new node;
		temp1=tail->next;
		ptr=temp1->next;
		tail->next=NULL;
		tail=temp1;
		while (ptr!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
			temp->next=temp1;
			temp1=temp;
		}
		tail->next=temp1;
	}
	cout<<"node  is reversed"<<endl;
}
void CircularSinglyLinkedList::display()
{
	cout<<"\n\t";
	if (tail==NULL)
		cout<<"Linked List is empty";
	else
	{
		ptr=tail;
		do
		{
			ptr=ptr->next;
			cout<< "-->" <<ptr->data;
		} while (ptr!=tail);
		cout<<"-->...";
	}
	cout<<endl;
}
int main()
{
	int Choice;
	char ch;
	CircularSinglyLinkedList c;
	do
	{
		cout << "\n1. Create\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Location\n5. Delete at Beginning\n6. Delete at End\n7. Delete at Location\n8. Count the nodes\n9. Search\n10. Reverse the list\n11. Display\n12. Exit" << endl;
		cout << "Enter your Choice : ";
		cin >>Choice;
		switch (Choice)
		{
		case 1:
			c.create();
			break;
		case 2:
			c.insert_at_begin();
			break;
		case 3:
			c.insert_at_end();
			break;
		case 4:
			c.insert_at_locat();
			break;
		case 5:
			c.del_from_begin();
			break;
		case 6:
			c.del_from_end();
			break;
		case 7:
			c.del_at_locat();
			break;
		case 8:
			c.count();
			break;
		case 9:
			c.search();
			break;
		case 10:
			c.reverse();
			break;
		case 11:
			c.display();
			break;
		case 12:
			exit(0);
		}
		cout<< "\nWant to operate more? (y/n) ";
		cin>>ch;
	} while (ch == 'y');
}
