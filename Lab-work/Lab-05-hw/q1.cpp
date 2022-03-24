#include<iostream>
using namespace std;
class node
 {
	public:
		char data;
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


void concatinate(node *h, node* h1)
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
	head1->data='A';
	head1->next=NULL;
	
	insertNode1('B');
	insertNode1('C');

	head2->data='D';
	
	head2->next=NULL;
	insertNode2('E');
	insertNode2('F');

	printLinklist1();

	cout<<endl;
	
	printLinklist2();
	
	cout<<endl;
	
	concatinate(head1,head2);
    cout << "Concatinated list: ";
	printLinklist1();
	cout << endl;
}