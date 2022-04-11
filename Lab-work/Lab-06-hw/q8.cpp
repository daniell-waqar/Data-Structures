
#include <iostream>
using namespace std;

class node
{
	public: 
    int data;
	node *next;
	node *prev;

	node(int val)
	{
		data = val;
		next = NULL;
		prev = NULL;
	}
};
class DoublyLinkedList
{
	public: 

    node *head;
    int lenght = 0;

	DoublyLinkedList()
	{
		head = NULL;
	}


    void insertAtHead(int val)
    {
        node *n = new node(val);
    
        head = n;
        lenght++;

    }

	// Insert new node at end position
	void insert(int val)
	{
		// Create a node
		node *n = new node(val);
		
		node *curr = head;
		
		while (curr->next != NULL)
			curr = curr->next;
		
		
		curr->next = n;
		n->prev = curr;
        lenght++;
	}
	

    void print()
    {   
        node *curr = head;
        if(head == NULL)
        {
            cout<<"Link list is Empty!!"<<endl;
        }

        
        while(curr!=NULL)
        {

            cout<<curr->data<<",";
            curr = curr->next;
        }


    }

	void mergeTwoList(DoublyLinkedList *sec)
	{
    
        node *obj1 = head;
        node *obj2 = sec->head;
        node *rev = NULL;
        if (obj1->data > obj2->data)
        {
            
            head = obj2;
        }
        while (obj1 != NULL && obj2 != NULL)
        {
            if (obj1->data >= obj2->data)
            {
               
                if (rev != NULL)
                {
                    rev->next = obj2;
                    
                    obj2->prev = rev;
                }
             
                rev = obj2;
                obj2 = obj2->next;
            }
            else
            {
              
                if (rev != NULL)
                {
                    rev->next = obj1;
                    obj1->prev = rev;
                }
               
                rev = obj1;
                obj1 = obj1->next;
            }
        }
        
        if (obj1 != NULL)
        {
            rev->next = obj1;
            obj1->prev = rev;
        }
        if (obj2 != NULL)
        {
            rev->next = obj2;
            obj2->prev = rev;
        }
       
        sec->head = NULL;
    }
	
};
int main()
{
	DoublyLinkedList *l1 = new DoublyLinkedList();
	DoublyLinkedList *l2 = new DoublyLinkedList();

    l1->insertAtHead(1);
	l1->insert(3);
	l1->insert(5);
	l1->insert(7);
	l1->insert(17);
	cout << "First Linked List:" << endl;
    l1->print();

    cout << endl << endl;

    l2->insertAtHead(2);
	l2->insert(6);
	l2->insert(4);
	l2->insert(64);
	l2->insert(82);

    cout << "Second Linked List:" << endl;
    l2->print();
	
	cout << "\n\nAfter Merged..."<< endl;
	l1->mergeTwoList(l2);

	
	l1->print();
    cout << endl;
	
	return 0;
}