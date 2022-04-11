#include <iostream>
using namespace std;

class stack
{
    private:
    int size;
    int top;
    int *arr;
    
    

    public:

    stack( )
    {
        
       
        size = 5;
        arr = new int [size];
        top = -1;

    }

    void push(int val)
    {   
        if(top == size-1)
            cout << "Stack overflow!";
        else
        {
            top++;
            arr[top] = val;
        }
    }
    

    int pop()
    {   
        if(top == -1)
            cout << "Stack underflow!";
        else{
        int val = arr[top];
        top--;
        return val;
        }

    }

    bool isEmpty()
    {
        if(top == -1)
            return true;
        return false; 
    }

    void display()
    {   
        if(isEmpty())
        {
            return;
        }
        else
        {

            for(int i = top; i>=0; i--)
            {
                cout <<arr[i]<< " ";
                
            }
        }
       
    }

    int peek()
    {
        return arr[top];
    }
};

int main()
{
    stack s ;
    s.push(4);
    s.push(3);
    s.push(1);
    s.display();
    s.pop();
    cout << endl;
    s.display();
    cout << endl;
   }

