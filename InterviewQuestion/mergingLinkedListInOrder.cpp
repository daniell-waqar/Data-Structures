#include<iostream>
using namespace std;
class node
 {
	public:
		int data;
		node *next;
};

node *head1= new node();
node *head2= new node();

node *curr1= new node();
node *curr2= new node();

int length =0;
int length1 =0;

void start() { 
	curr1= head1;
}

void start1() { 

	curr2= head2;
}

void insertNode1(int val) { 

	start();

	node *n1= new node();

	while(curr1->next!=NULL)
	{
		curr1= curr1->next;
	}
		
	n1->data= val;
	n1->next= NULL;
	curr1->next= n1;
	length ++;
}

void insertNode2(int val) { 

	start1();

	node *n2= new node();

	while(curr2->next!=NULL)
	{
		curr2= curr2->next;
	}
		
	n2->data= val;
	n2->next= NULL;
	curr2->next= n2;
	length1++;
}

void printLinklist1() {
	start();
	while(curr1!=NULL) {
		cout<<curr1->data<<" ";
		curr1= curr1->next;
	}
}

void printLinklist2() {

	start1();

	while(curr2!=NULL) {
		cout<<curr2->data<<" ";
		curr2= curr2->next;
	}
}

void sortingL1(node *h)
{
	int x;
	node* curr1=head1;
	node* n1;
	
	while(curr1!=NULL)
	{
		n1=curr1->next;
		
		while(n1!=NULL)
		{
			if( n1->data < curr1->data)
			{
				x=curr1->data;
				curr1->data=n1->data;
				n1->data=x;
			}

			n1=n1->next;
	
		}
		curr1=curr1->next;
}
	
	
}

void sortList2(node *h1)
{
	int x;
	node* curr2=head2;
	node* n2;
	
	while(curr2!=NULL)
	{
		n2=curr2->next;
		
		while(n2!=NULL)
		{
			if(  n2->data < curr2->data )
			{
				x=curr2->data;

				curr2->data=n2->data;
				n2->data=x;
			}

			n2=n2->next;
	
		}
		curr2=curr2->next;
}
	
	
}

void merge(node *h, node* h1)
{
	start();
	start1();

	while(curr1->next!=NULL)
	{
		curr1=curr1->next;
	}

	curr1->next=curr2;
	length = length + length1 ;
}

int main()
{
	head1->data=3;
	head1->next=NULL;
	
	insertNode1(2);
	insertNode1(1);

	head2->data=8
	;
	head2->next=NULL;
	insertNode2(7);
	insertNode2(6);

	printLinklist1();

	cout<<endl;

	sortingL1(head1);

	
	printLinklist1();
	cout<<endl;
	cout << "*********************************"<<endl;
	cout<<endl;
	
	printLinklist2();
	sortList2(head2);

	cout<<endl;
	printLinklist2();
	cout<<endl;
	cout << "*********************************"<<endl;
	cout<<endl;
	
	merge(head1,head2);
	printLinklist1();
	cout << endl;
}
