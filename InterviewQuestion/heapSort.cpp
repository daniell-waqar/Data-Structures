
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

    void heapify( int i)
    {
        int largest = i;

        int left = 2*i;
        int right = 2*i+1;

        if(left<= size && arr[left] > arr[largest])
        {
           
            largest = left;

        }

        if(left<= size && arr[right] > arr[largest])
        {
           
            largest = right;

        }

        if(largest != i)
        {
            swap(arr[largest] , arr[i]);
            heapify(largest);
        }
        
    }

    void heapSort(int arr[] , int n)
    {
        arr[n] = arr[1];
        size--;

        heapify(1);
    }

    void buildHeap(int arr[] , int n)
    {
        for(int i = 1 ; i<n/2; i++)
        {
            heapify(i);
        }
    }
};

int main()
{
    heap h;
    
    cout<<"------------------------------"<<endl;
    int arr[] = {0, 4 , 5 , 9, 1};
    int n = sizeof(arr) / sizeof(int);

    h.insert(4);
    h.insert(5);
    h.insert(9);
    h.insert(1);
    h.print(); cout << endl;
    
    h.buildHeap(arr, n);
    h.heapSort(arr , n);

    h.print();
  

   
}