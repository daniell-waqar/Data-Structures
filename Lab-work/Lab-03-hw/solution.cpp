#include <iostream>
using namespace std;

class Array
{
    private:
    int size, pos, length;
    int *array;
    int * curr;

    public:
    
    Array()
    {
        size = 10;
        array = new int[size];
        length = 0;

        curr = array;
    }

    ~Array()
    {
        delete [] array;
        delete curr;
    }

    void printArray()
    {
        if (length > 0)
        {
            head();
            for(int i = 0; i<length; i++)
            {
                cout << *curr++ << "\t";

            }
        }
        else    
            cout << "Array is Empty " << endl;
    }

    void InsertElement(int val)
    {
        if(!IsFull())
        {
            head();

            curr = curr + length;
            *curr = val;
            length++;
        }
        else{
             cout << "Array is Full " << endl;
        }
    }

    void InsertAtPos(int val, int pos)
    {
        if(!IsFull())
        if(pos <= length && pos>0)
        {
            tail();
            for(int i = length; i>= pos; i--)
            {
                *(curr + 1) = *curr;
                curr = curr - 1;  //back()
            }

            
            next(); //curr++
            *(curr) = val;
            length++;
        }
        else if(pos > length && pos <= size)
        {
            head();
            curr = curr + pos - 1;
            *(curr ) = val;
            length++;
        }
        else
            cout << "Invalid position " << endl;
    }
    void reverseArray()
    {
        int* p1, *pn, temp;
        p1 = array;
        pn = array + length - 1;
        int val = length/2;

        for(int i =0 ; i < val; i++)
        {
            temp = *p1;
            *p1 = *pn;
            *pn = temp;
            p1++;
            pn--;

        }
    }

    bool IsFull()
    {
        if(length == size)
            return true;
        return false;
    }

    bool IsEmpty()
    {
        if(length == 0)
            return true;
        return false;
    }

    void head()
    {
        curr = array;
    }
    void tail()
    {
        curr = array + length - 1;
    }

    void back()
    {
        curr = curr - 1;
    }

    void next()
    {
        curr = curr + 1;
    }
    int Length()
    {
        return length;
    }

    void emptylist()
    {
        head();
        for(int i = 0; i < size; i++)
        {
            *curr++ = 0;
        }
    }
  
    void deleteElementAtPos(int pos)
    { 
        if(!IsEmpty())
        {
            if(pos <= size && pos > 0)
            {
                head();
                curr = curr + pos -1;

                for(int i = 0; i<= length - pos; i++)
                {
                    *(curr ) = *(curr + 1);
                    next();
                }

                length--;
            }
        }
        else
            cout << "Array is Empty , Delete operation failed " << endl;
    }
    


};

int main()
{
    Array *obj = new Array ();
    obj -> emptylist();
    obj -> InsertElement(1);
    obj -> InsertElement(2);
    obj -> InsertElement(3);
    obj -> InsertElement(4);
    obj->printArray();  cout << endl;
    obj->InsertAtPos(99 , 2);
    obj->printArray();  cout << endl;
    obj-> deleteElementAtPos(2);
    obj->reverseArray();
    obj->printArray();  cout << endl;

}