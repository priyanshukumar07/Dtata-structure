#include<iostream.h>
#include<conio.h>
class node
{
 public:
 int data;
 node *next;
 node()
 {
   data=0;
   next=NULL;
   
 }
  Node(int d, node *ptr=0)
  {
	  data=d;
	  next=ptr;
  }
 
};

class SinglyLinkedList
{   
public:
    node *head,*tail,*temp,*ptr;
    SinglyLinkedList()
    {
        head=tail=NULL;
    }
    ~SinglyLinkedList()
    {
        cout<<"Deleting the Memory"<<endl;
        ptr=head;
        while(ptr!=NULL)
        {
           temp=ptr->next;
           delete ptr;
           ptr=temp;
        }
    }
     
     void create();
     void count();
     void del_from_end();
     void del_from_begin();
     void del_at_locat();
     void insert_at_begin();
     void insert_at_end();
     void insert_at_locat();
     void display();
     void Reverse();

};
void SinglyLinkedList::create()
{
    int n;
    char ch='y';
    do
    {
     temp=new node;
     cout<<"enter the node data "<<endl;
     cin>>n;
     if(head==NULL)
     {
        head=temp;
        head->data=n;
        head->next=temp;
        tail=head;

     }
     else
     {
     temp->data=n;
     tail->next=temp;
     tail=temp;
     }
     cout<<"you want to enter more node? (y/n)"<<endl;
     cin>>ch;
    }
    while(ch=='y');
    
}

void SinglyLinkedList::insert_in_begin() 
{
    temp=new node;
    cout<<"enter the data  to inserted at beginning "<<endl;
    cin>>temp->data;
    temp->next=head;
    head=temp;
    cout<<"Inserted"<<endl;

}

void SinglyLinkedList::insert_at_end()
{
    temp=new node;
    cout<<"enter the data to enter at end"<<endl;
    cin>>temp->data;
    temp->next=NULL;
    tail->next=temp;
    tail=temp;
    cout<<"Inserted"<<endl;
} 

void SinglyLinkedList::del_from_end();
{
    ptr=head;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    
    }
    delete ptr->next;
    ptr->next=NULL;
    tail=ptr;
    cout<<"node deleted from end"<<endl;
}
void SinglyLinkedList::del_from_begin()
{
    temp=head;
    head=head->next;
    delete temp;
    cour<<"node deleted from beginning"<<endl;

}
void SinglyLinkedList::del_at_locat()
{
    int loc;
    cout<<"enter the location of the node to be deleted";
    cin>>loc;
    ptr=head;
    for(i=1;i<loc-1;i++)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=ptr->next->next;
    delete temp;
    cout<<"node is deleted at location--"<<loc<<endl;
     
}
void SinglyLinkedList::insert_at_locat()
{
    int loc;
    temp=new node;
    cout<<"enter the loc to insert data"<<endl;
    cin>>loc;
    cout<<"enter the data of node"<<endl;
    cin>>temp->data;
    ptr=head;
    for(i=1;i<loc-1;i++)
    {
        ptr=ptr->next;    
    }
    temp->next=ptr->next;
    ptr->next=temp;
    cout<<"node is inserted at location"<<loc<<endl;
}
void SinglyLinkedList::display()
{
	cout << "\n\t";
	if (head == NULL)
		cout << "Linked list is empty";
	ptr = head;
	while (ptr != NULL)
	{
		cout << "--->" << ptr->data;
		ptr = ptr->next;
	}
	cout << endl;
}
void SinglyLinkedList::count()
{
    int count=0;
    ptr=head;
    while(ptr!=NULL)
    {
        ++count;
        ptr=ptr->next;
    }
    cout<<"Number node in linked list"<<count<<endl;
    
}
void SinglyLinkedList::Reverse()
{
  ptr=head->next;
  head->next=NULL;
  head=tail;	
  while(ptr!=NULL)
  {    temp=ptr;
      ptr=ptr->next;
      temp->next = head;
       head = temp;
  }
	cout<<"node is reversed"<<endl;
  
  
}
int main()
{
	int Option;
	char ch;
	SinglyLinkedList S;
	do
	{
		cout << "\n1. Create\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Location\n5. Delete at Beginning\n6. Delete at End\n7. Delete at Location\n8. Count the nodes\n9. Display\n10. Reverse\n11. Exit" << endl;
		cout << "Enter your Option : ";
		cin >>Option;
		switch (Option)
		{
		case 1:
			S.create();
			break;
		case 2:
			S.insert_at_begin();
			break;
		case 3:
			S.insert_at_end();
			break;
		case 4:
			S.insert_at_loc();
			break;
		case 5:
			S.del_at_begin();
			break;
		case 6:
			S.del_at_end();
			break;
		case 7:
			S.del_at_loc();
			break;
		case 8:
			S.count();
			break;
		case 9:
			S.display();
			break;
		case 10:
			s.Reverse();
			break;	
		case 11:
			exit(0);
		}
		cout << "\nWant to operate more? (y/n) ";
		cin >> ch;
	} while (ch == 'y');
}
