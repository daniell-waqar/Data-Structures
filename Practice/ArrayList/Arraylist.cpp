#include <iostream>
using namespace std;

class Array
{   

    int  *curr, *array;
   
    int size;    //total size of Array
    int length;   //number of elements in Array
    public:

    Array()
    {
        curr = NULL;
        length = 0;        //at the start Array is Empty

        cout << "Enter the size of an array : ";
        cin >> size;

        array = new int[size];
        curr = array;         
    }

    ~Array()
    {
        delete[] array;
    }

    void insertElement(int val)
    {
        start();
        curr = array + length;    //initially length = 0 so array + length = array, it means insert element at the start of array
        *curr = val;               
        length++;                 //increament length whenever you insert element,for next time call insert function curr pointer is pointing to next index of array
        
    }

    void insertElementAtpos(int val, int pos)
    {   
        if(length == size)
        {
            cout << "Array is full cannot add element!"<< endl;
            return;
        }

        if(pos < 0 || pos > length + 1)     //we cannot insert element at negative index,                                 
        {                                     // also if we do not insert element at contigious location it is wrong bcz some garbage values will store!
            cout << "Invalid position!" << endl;
            return;
        }
        
        cout << endl;
        cout << "Inserting "<< val << " at " << pos << " position!";
        tail();    //this function move curr pointer to the last index
        for(int i =length; i>=pos; i--)    
        {
            *(curr+1) = *curr;     //shift element towards right
            curr--;
        }

        *(curr + 1) = val;        //when your curr pointer reach at empty block insert given value at that position 
        //length++;

      
    }

    void remove(int pos)
    {
        if(length == 0)
        {
            cout << "Array is Empty nothing to remove!" << endl;
            return;
        }

        if(pos < 0 || pos > length)     //for reomve element position must be between 1 to length value
        {
            cout << "Invalid position!" << endl;
            return;
        }

        cout << "Removing value from " << pos << " position!"<< endl;
        start();
        for(int i =1; i < length; i++)
        {
            if( i >= pos)             //if i value is greater or equal to [postion] then shift element towards left
                *curr = *(curr + 1);

            curr++;                     //move curr pointer to the next index
        }
        length--;             //when you delete element from array must decreamnet the length
 
        
    }


    int get(int pos)
    {
        if(pos < 1 || pos > length)
        {
            cout << "Invalid position!" << endl;
            return -1;             //return invalid value
        }

        start();
        for(int i =1; i<pos; i++)
        {
            next();
        }
        //cout << *curr << endl;
        return *curr;        //return value at given position
    }

    void update(int val, int pos)
    {
        if(pos < 1 || pos > length)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        cout << "Updating " << val << " at " << pos << " position!" << endl;
        start();
        for(int i =1; i<pos; i++)
        {
            next();
        }
       
        *curr = val;       //update value at given position
    }

    int search(int val)
    {
        
        if(length == 0)
        {
            cout << "Array is Empty!" << endl;
            return -1;      //return invalid value
        }

        start();
        for(int i = 1; i<= length; i++)
        {
            if(*curr == val)   //if value is present in Array return it's position
                return i;

            curr++;
        }
        return -1;      //return invalid value
        

    }

    int Length()
    {
        return length;
    }

    void start()
    {
        curr = array;
    }

    void tail()
    {
       curr = array + length -1;   
    }
    void next()
    {
        curr++;
    }

    void back()
    {
        curr--;
    }

    void print()
    {   
        start();
        for(int i =0; i<=length; i++)
        {
            cout << *curr << " ";
            curr++;
        }
    }
};


int main()
{
   Array a1;
    a1.insertElement(2);    //store dummy values in Array
    a1.insertElement(5);
    a1.insertElement(1);
    a1.insertElement(3);
    a1.insertElement(8);

    a1.print();
    cout << endl;

    a1.insertElementAtpos(9,4);  //insert element at any position
    cout << endl;

    a1.print();
    cout << endl << endl;

    
    a1.remove(3);           //remove element from any position
    a1.print();

    cout << endl;
    
    a1.get(4);             //get value from any position
    cout << endl;
    
    a1.search(3);

    a1.update(4,2);       //update value at any position
    
    a1.print();
    cout << endl;

    a1.Length();


  
}


