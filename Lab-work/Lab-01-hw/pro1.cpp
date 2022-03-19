#include <iostream>
using namespace std;

int main()
{
    int arr[3];


    cout << "Enter elements into array: " << endl;

    for(int i=0; i<3; i++)
    {
        
        cin >> arr[i];
        
    }

    cout << "Array values are : " << endl;

    for(int i=0; i<3; i++)
    {
       
        {
            cout <<  arr[i] << " ";
        }
        cout << endl;
    }

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

    return 0;
}