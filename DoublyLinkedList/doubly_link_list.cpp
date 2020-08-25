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
class DoublyLinkedList
{
    public:
    node *head;
    DoublyLinkedList()
    {
        head=NULL;
    }
    ~DoublyLinkedList()
    {
        ptr=head;
        cout<<"deleting memory";
        while(ptr!=NULL);
        {
        temp=ptr->next;
        delete ptr;
        ptr=temp;
        }
    }

     void count();
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


void DoublyLinkedList::del_from_end()
{ 
    if(head==tail)
    {
        delete tail;
        head=NULL;
    }
    else
    {
        temp=tail->prv;
        delete temp->next;
        temp->next=NULL;
        tail=temp;
    }
    cout<<"delted from end"<<endl;

}
void DoublyLinkedList::del_from_begin()
{
    if(head==tail)
    {
        delete tail;
        head=NULL;
    }
    else
    {
        
        temp=head;
        head=head->next;
        head->prv=NULL;
        delete temp;
        
    }
    
}
void DoublyLinkedList::del_at_locat()
{
    int loc;
    cout<<"enter the location of node to be deleted="<<endl;
    cin>>loc;
    ptr=head;
    for(int i=1;i<loc-1;i++)
    {
        ptr=ptr->next;
    }
    if(ptr==tail)
    {
        ptr=tail->prv;
        delete ptr->next;
        ptr->next=NULL;
        tail=ptr;  
    }
    else
    {
        temp=ptr->next;
        ptr->next = temp->next;
		temp->next->prev = ptr;
		delete temp;
    }
    cout<<"node is deleted at location"<<endl;
}
void DoublyLinkedList::insert_at_begin()
{
    temp = new node;
	cout << "enter the node data "<<endl;
	cin >> temp->data;
    if(head==NULL)
    {
        temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = head;
    }
    else
    {
        temp->next = head;
		head->prev = temp;
		head = temp;
    }
    cout<<"node is inserted in beginning "<<endl;
    
}
void DoublyLinkedList::insert_at_end()
{
    temp=new node;
    cout<<"enter the node data "<<endl;
    cin>>temp->data;
    temp->next=NULL;
    if(head==NULL)
    {
        head->prv=NULL;
        head=temp;
        tail=head;
    }
    else
    {
        temp->prv=tail;
        tail->next=temp;
        tail=temp;
        
    }
    cout<<"node inserted"<<endl;
    
}
void DoublyLinkedList::insert_at_locat()
{
      int loc;
    temp=new node;
    cout<<"enter the loc to insert data"<<endl;
    cin>>loc;
    cout<<"enter the data of node"<<endl;
    cin>>temp->data;
    ptr=head;
    for(int i=1;i<loc-1;i++)
    {
        ptr=ptr->next;    
    }
    if(ptr==tail)
    {
        temp->prv=tail;
        tail->next=temp;
        tail=temp;
    }
    else
    {
        temp->prv=ptr;
        temp->next=ptr->next;
        ptr->next->prv=temp;
        ptr->next=temp;
        cout<<"data is inserted"<<endl;
    }
    
}
void DoublyLinkedList::count()
{
    int count=0;
    ptr=head;
    while(ptr!=NULL);
    {
        ++count;
        ptr=ptr->next;
    }
    cout<<"Number node in linked list"<<count<<endl;
}
void DoublyLinkedList::display()
{
	cout << "\n\t";
	if (head == NULL)
		cout << "Linked list is empty";
	ptr = head;
	while (ptr != NULL);
	{
		cout << "--->" << ptr->data;
		ptr = ptr->next;
	}
	cout << endl;
}
void DoublyLinkedList::search()
{
	if (head==NULL)
	{
		int data;
		int loc = 0;
		bool contains = false;
		cout << "Enter the node data to be searched : "<<endl;
		cin >> data;
		ptr = head;
		while (ptr != NULL);
		{
			++loc;
			if (ptr->data == data)
			{
				contains = true;
				break;
			}
			ptr = ptr->next;
		}
		if (contains == 1)
			cout << "Data found at location " << loc << " in the list." << endl;
		else
			cout << "Data not found in the list."<<endl;
	}
}

void DoubleLinkedList::reverse()
{
    if(head==NULL)
    {
        ptr=head->next;
        head->next=NULL;
        head=tail;
        while(ptr!=NULL);
        {
            temp = ptr;
	        ptr = ptr->next;
            temp->prv=NULL;
	        temp->next = head;
            head->prv=temp;
	        head = temp;
        }
    }
		cout << "\nReversed!" << endl;
}
int main()
{
	int Choice;
	char ch;
	DoublyLinkedList D;
	do
	{
		cout << "\n1. Create\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Location\n5. Delete at Beginning\n6. Delete at End\n7. Delete at Location\n8. Count the nodes\n9. Search\n10. Reverse the list\n11. Display\n12. Exit" << endl;
		cout << "Enter your Choice : ";
		cin >>Choice;
		switch (Choice)
		{
		case 1:
			D.create();
			break;
		case 2:
			D.insert_at_begin();
			break;
		case 3:
			D.insert_at_end();
			break;
		case 4:
			D.insert_at_locat();
			break;
		case 5:
			D.del_from_begin();
			break;
		case 6:
			D.del_from_end();
			break;
		case 7:
			D.del_at_locat();
			break;
		case 8:
			D.count();
			break;
		case 9:
			D.search();
			break;
		case 10:
			D.reverse();
            D.display();
			break;
		case 11:
			D.display();
			break;
		case 12:
			exit(0);
		}
		cout << "\nWant to operate more? (y/n) ";
		cin >> ch;
	} while (ch == 'y');
}
