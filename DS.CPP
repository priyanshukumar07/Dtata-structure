#include<iostream.h>
#include<conio.h>

class Node{
public:
int data;
Node* next;
Node()
{
data=0;
next=NULL;
}
Node(int d)
{
data=d;
}
class SinglyLinkedList{
public:
Node* head;
SinglyLinkedList()
{
head=NULL;
}
SinglyLinkedList(Node *n)
{
head=n;
}
void appendNode(Node *n)
{
if(head==NULL)
{
head=n;
cout<<"Node Appended"<<endl;
}
else
{
Node* ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=n;
cout<<"Node Appended"<<endl;
}

}
void printList()
{
if(head==NULL)
{
cout<<"No Node in singly linked list";
}
else
{
cout<<endl<<"Singly Linked List values";
Node* temp=head;
while(temp!=NULL)
{
cout<<"("<<temp->key<<","<<temp->data") -->";
temp=temp->next;
}
}
}
}
};
int main()
{
SinglyLinkedList s;
int option;
int data1;
do
{
cout<<"what option you whant to perform? select option number"<<endl;
cout<<"1.appenNode()"<<endl;
cout<<"2.print"<<endl;
cin>>option;
Node*n1=new Node();
switch(option)
{
case 0:
break;
case 1:
cout<<"Append Node Opration \n enter key &data of data to be Appended"<<endl;
cin>>data1;
n1->data1=data1;
s.appendNode(n1);
break;
case 2:
s.printList();
break;
}
}while(option!=0)
return 0;
}