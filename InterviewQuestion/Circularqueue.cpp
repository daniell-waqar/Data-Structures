
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

   
    bool enqueue(int value){
        
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ) {
           
            return false;
        }
        else if(front == -1) //first element to push
        {
			front = rear = 0;
            
        }
        else if(rear == size-1 && front != 0) {
            rear = 0; 
        }
        else
        {
            rear++;
        }
       
        arr[rear] = value;
        
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front == -1){//to check queue is empty
            cout << "Queue is Empty " << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }

    bool isEmpty() {
    if(front == rear) {
        return true;
    }
    else
    {
        return false;

    }
    }

    void Display()
    {
        
        if(front == rear){
            cout << "\nQueue is Empty\n";
            return;
        }
 
        // traverse front to rear and print elements
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        return;
    }
       
};

int main()
{
    CircularQueue *q = new CircularQueue(6);
    q->enqueue(3);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(2);
    q->Display();

    cout << endl;
    q->dequeue();
    q->Display();

    cout << endl;
   
}
