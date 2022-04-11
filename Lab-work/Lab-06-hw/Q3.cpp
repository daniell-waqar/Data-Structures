#include <iostream>
using namespace std;

class node
{   
    public:
    node *next;
    node *prev;
    int data;

    public:

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;

    }
};



class Doubly_Link_list
{
    private:
    node *head;
    int length;
        

    public:
        void insertAtHead(int);
        void insert(int,int);
        void Reverse();
        void print();
     
        Doubly_Link_list();

};
Doubly_Link_list:: Doubly_Link_list()
{
    head = NULL;
    length = 0;

}


void Doubly_Link_list ::insertAtHead(int val)
{
    node *n = new node(val);
  
    head = n;
    length++;

}



void Doubly_Link_list ::insert (int val , int pos)
{   
     node *n = new node(val);
     node *curr = head;
    if(pos < 1 || pos > (length+1))
    {
        cout << "Invalid position cannot insert!";
        return;
    }

    
    if(pos == 1)
    {   
        n->next = head;
        head->prev = n;
        head = n;
        length++;
    
    }

    else
    {
        for(int i =1; i< pos-1; i++)
        {
            curr = curr->next;
        }

        n->next = curr->next;
        n->prev = curr;
        if(curr->next != NULL)
            curr->next->prev = n;
        curr->next = n;

        length++;
    }

}

void  Doubly_Link_list ::Reverse()
{
    node *curr = head;
    node *temp = NULL;
  
    while(curr!= NULL)
    {

        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;            
        curr = curr->prev;
          
        if(temp != NULL )
            head = temp->prev;
    }
   

}



void Doubly_Link_list :: print()
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


int main()
{

    Doubly_Link_list l;
    l.insertAtHead(2);
    l.insert(3,2);
    l.insert(6,3);

    l.print();

    cout << endl;
    l.Reverse();

    cout << "After Reversing Integres..." << endl;
    l.print();
    cout << endl;
}