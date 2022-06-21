#include <iostream>
using namespace std;

void bubbleSort(int arr[5] , int size)
{
    for(int i =0; i<size-1; i++)
    {
        for(int j =1; j<size-i; j++)
        {
            if(arr[j-1] > arr[j])
            {
                swap(arr[j-1] , arr[j]);
            }
        }
    }
}


void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout<<arr[i]<<"\t";

    cout<<endl;
}
int main()
{
    cout<<"Bubble Sort"<<endl;
    int arr2[] = {4,1,5,2,3};
    printArr(arr2, 5);
    bubbleSort(arr2, 5);
    printArr(arr2, 5);
}
