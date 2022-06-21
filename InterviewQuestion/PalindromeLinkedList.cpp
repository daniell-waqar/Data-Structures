#include<iostream>

using namespace std;
class node {
	public:
		int data;
		node *next;
};

node *head1= new node();
node *curr1= new node();
int length=0;

void start() { 
	curr1= head1;
}

void insert(int val) { 
	start();
	node *n= new node();
	while(curr1->next!=NULL)
    {
        curr1= curr1->next;
    }
		
	n->data= val;
	n->next= NULL;
	curr1->next= n;
	length++;
}
node* Reverse(node* head)
{
    if(head==NULL)
    {
        cout << "Nothing for reverse!";
        return head  ;
    }
        
    
    if(head->next==NULL)
    {   
        cout << "Nothing for reverse!";
   		return head ;
    }
    
    node* prev = NULL ;
    node* curr = head ;
    node* next = curr->next ;
    
    while(curr->next!=NULL)
    {
        curr->next = prev ;
        prev = curr ;
        curr = next ;
        next = next->next ;
        
        if(next==NULL)
        {
            curr->next = prev ;
            prev = curr ;
            break ;
        }
    }
    
    head = prev;
    
    return head ;
}

bool Ispalindrome(node *head)

{   
    bool found = true;
    if(head ==NULL || head->next ==NULL)
    {
        cout << "cannot invert!";
        return found;
    }
        
   
    int center = 0 ;

    node* temp1 = head ;

    while(temp1!=NULL)
    {
        center++;
        temp1 = temp1->next ;
    }
    center =center/2 ;
    temp1 = head ;
    while(center--)
    {
        temp1 = temp1 ->next ;
    }
    
   node* head2 =Reverse(temp1) ;
    
    while(head2!=NULL && head!=NULL)
    {
        if(head->data == head2->data )
        {
            head=head->next ;
            head2 = head2->next ;

        }
        else
        {
            found = false;
            return found;
        }
            
        
    }
    
    return found ;
}

void printLinkedlist() {
	start();
	while(curr1!=NULL) {

		cout<<curr1->data<<" ";
		curr1= curr1->next;
	}

}

int main()
{
	
	head1->data=3;
	head1->next=NULL;
	
	insert(5);
	insert(3);
	
	printLinkedlist();
	cout<<endl;
	
	if(Ispalindrome(head1))
	{
		cout<<"Linked list is Palindrome!"<< endl;
	}
	else
	{
		cout<<"Linked list is not Palindrome!"<< endl;
	}
	
	
}
