// pointer with array
#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int*p;
    int i;

    p = arr;

    cout << "Enter values into array : " << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];


    }

    cout << "\nValues from array using pointers :" << endl;

    // for (int i = 0; i < 5; i++)
    // {
    //     cout <<  *p++ << "\t";

    // }


    int *x = p;
    while( *x != NULL)
    {
        cout << *x++ << endl;
    }


}