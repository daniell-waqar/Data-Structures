
#include<iostream>
using namespace std;

class heap
{
    public:
    int size;
    int arr[100];
    heap()
    {
    
        int size = 0;
    }

    void insert(int val)
    {
        if(size == 100)
        {
            cout << "Array is full";
            return;
        }

        size++;
        int index = size;
        arr[index] = val;

        while(index > 1)
        {
            int parent = index/2;

            if(arr[parent] < arr[index])
            {
                swap(arr[index] , arr[parent]);
                index = parent;
            }
            else 
            return;
        }

    }

    void print()
    {
        for(int i =1; i<=size; i++)
        {
            cout << arr[i]  << " ";
        }
    }

    void remove()
    {
        if(size == 0)
        {
            cout << "Nothing to delete";
            return;
        }

        arr[1] = arr[size];
        size--;
        int i =1;
        while(i <size)
        {
            int leftindex = 2*i;
            int rightindex = 2*i + 1;

            if(arr[i] < arr[leftindex] )
            {
                swap(arr[i] , arr[leftindex]);
                i = leftindex;
            }

            if(arr[i] < arr[rightindex])
            {
                 swap(arr[i] , arr[rightindex]);
                i = rightindex;
            }
               


        }
    }
};

int main()
{
    heap h;
    h.insert(4);
    h.insert(5);
    h.insert(9);
    h.insert(1);
    h.print(); cout << endl;
    h.remove(); 
    h.print();
}