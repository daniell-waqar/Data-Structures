#include <iostream>
using namespace std;

void sort(int *arr)
{   
    int max = arr[0];
    int min = arr[0];

    for(int i=0; i<3; i++)
    {
    
          if(arr[i] > max)
            {
                max = arr[i];
            }

            if(arr[i] < min)
            {
                min = arr[i];
            }
        
    }

     cout << "Maximum number is = " << max << endl;
    cout << "Minimum number is = " << min << endl;
}


int main()
{
    int arr[3] = {3,4,5};

    sort(arr);
 


   



}