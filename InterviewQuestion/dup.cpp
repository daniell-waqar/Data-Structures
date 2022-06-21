
#include <iostream>
using namespace std;

class node
{   
    public:
    int data;
    node *next;

    node()
    {
        next = NULL;
    }

};


class queue
{
    private:
        node * frontt, * rear;
        int lenght;
        int size;
    public:
        void enqueue(int);
        void dequeue();
        void print();
        void duplicate();
        bool isEmpty();
        bool isFull();
        queue();

};


queue ::queue()
{   
   
    size = 6;
    frontt = rear = NULL;
    lenght = 0;


}
void queue::enqueue(int val)
{   
    node *n = new node();
    n->data = val;
     node *temp = frontt;

    if(rear == NULL)
    {
       rear->next = NULL;
       frontt = rear = n;
       lenght++;

    }
    else{
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = n;
        rear = n;
        lenght++;

    }

}

void queue::duplicate()
{
    node *temp = frontt;
  
    while(temp != NULL)

    {   node *temp2 = temp->next;
        node *temp1 = temp;
        for(int i = 1; i<temp->data; i++)
        {
            node *t = new node();
            t->data = temp->data;
            temp1->next = t;
            temp1 = temp1->next;
            t->next = temp2;

            
            
        }
        temp = temp2;
    }
}


void queue::print()
{

    while(frontt != NULL)
    {
        cout<<frontt->data<<" ";
        frontt = frontt->next;
    }

}

bool queue::isEmpty()
{
    if(frontt == NULL && rear == NULL)
    {
        return true;
    }
    else 
        return false;
}

bool queue:: isFull()
{
    if(lenght == size)
        return true;
    else
        return false;



}





int main()
{
    queue q;

   

    q.enqueue(3);

    q.print();

   
}




