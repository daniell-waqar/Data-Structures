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

class linked_list
{
    private:
    node *head;
    int length;

  public:

    
linked_list()
{
    head = NULL;
    length = 0;
}

void insert(int val , int pos)
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
        node *temp = head;
        for(int i = 1; i<(pos - 1); i++)
        {
            temp = temp->next;  
        
        }

        n1->next = temp->next;
        temp->next = n1;
    }
    length++;

}

void print()
{
    node *temp = head;
    
    if(head == NULL)
    {
        cout<<"Link linked_list is empty from print function "<< endl;
        return;

    }

    while(temp != NULL)
    {

        cout<<temp->data<<" ";
        temp = temp->next;

    }


}

void make_circular()
{
    if(head == NULL)
    {
        cout << "Linked list is Empty!"<< endl;
        return;

    }

    node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    if(temp == head)
    {
        cout << "Already Circular...";
        return;
    }
    temp->next = head;
}

bool isCircular()
{
    if (head == NULL)
    {
        cout << "Linked list is Empty!"<< endl;
        return false;
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            
            temp = temp->next;
            if (temp == head)
            {
                return true;
            }
        }
       
        return false;
    }
}
   

   
};




int main()
{



    linked_list l;
  
    l.insert(3,1);
    l.insert(4,2);  
    l.insert(5,3);
    l.insert(6,4);

    l.print();

    cout << endl;

    l.make_circular();

    bool x = l.isCircular();

    if(x)
    {
        cout <<"Circular" << endl;
    }

    else
    {
        cout << "Not Circular" << endl;
    }


    cout << endl;
}