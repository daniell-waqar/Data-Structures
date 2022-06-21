#include <iostream>

using namespace std;


class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
  
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int val)
    {
        if(front == 0 && rear == size-1 || (rear == front-1% size-1))
        {
            return false;
        }

        else if(front == -1)
        {
            front = rear =0;
        }
        else   rear++;

        arr[rear] = val;
        return true;

    }

    void print()
    {   
        for(int i = front; i<= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }

    int dequque()
    {
          if(front == -1){//to check queue is empty
            cout << "Queue is Empty " << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;
        if(front == rear)
        {
            front = rear = 0;
        }
        else if(front = size-1)
        {
            front = 0;
        }
        else 
            front++;

        return ans;
    }
};

int main()
{
    CircularQueue *n = new CircularQueue(5);
    n->enqueue(3);
     n->enqueue(5);
      n->enqueue(9);
       n->enqueue(1);
    n->print(); 
    cout << endl;
    n->dequque();
  //  n->dequque();
    n->print(); cout << endl;
    
}