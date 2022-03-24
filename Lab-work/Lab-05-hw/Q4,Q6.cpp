#include <iostream>
using namespace std;

class node
{
    public:

    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;

    }

    
};

class list
{
    private:
    node *head;
    int length;

  public:
    list();    
    void insert(int , int);  
    void print();
    void RemoveDuplicate();
    void lastTofirst();

};


list::list()
{
    head = NULL;
    length = 0;
}


void list::insert(int val , int pos)
{
    node *n1 = new node(val);

    if(pos < 1 || pos > length + 1)
    {
        cout << "Invalid position You can not add elements!" << endl;
        return;
    }

    if(pos == 1)
    {
        n1->next = head;
        head = n1;

    }

    else
    {
        node *curr = head;
        for(int i = 1; i<(pos - 1); i++)
        {
            curr = curr->next;  
        
        }

        n1->next = curr->next;
        curr->next = n1;
    }
    length++;

}



void list::print()
{
    node *curr = head;
    
    if(head == NULL)
    {
        cout<<"Link list is empty!"<< endl;
        return;

    }

    while(curr != NULL)
    {

        cout<<curr->data<<" ";
        curr = curr->next;

    }


}

void list::RemoveDuplicate()
{   
     
    if(head == NULL)
    {
        cout<<"Link list is empty!"<< endl;
        return;

    }
    node *curr = head;
    node *nextNode = NULL;
    while(curr != NULL && curr->next != NULL)
    {
        if(curr->data == curr->next->data)
        {
            nextNode = curr->next->next;
            delete curr->next;
            curr->next = nextNode;
        }
        else
            curr = curr->next;
    }
}


void list::lastTofirst()
{
    node *curr = head;
    node *nextt = NULL;
    while(curr->next != NULL)
    {   
        nextt = curr;
        curr = curr->next;
    
    }

    nextt->next = NULL;
    curr->next = head;
    head = curr;
}

int main()
{



    list l;
  
    l.insert(3,1);
    l.insert(3,2);
    l.insert(4,3);
    l.insert(9,4);
    l.insert(9,5);
    l.print();

    cout << endl;
    l.RemoveDuplicate();
    cout << "Removing duplicate from original list!" << endl;
    l.print();
    cout << endl;

    l.lastTofirst();
    cout << "moving last to first from original list!" << endl;
    l.print();

}