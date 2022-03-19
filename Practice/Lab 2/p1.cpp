// Dynamic memory allocation (DMA)

#include <iostream>
using namespace std;

int main()
{
    int *p = NULL;
    p = new (nothrow) int;    //If memory is availabile , initialize p with NULL
    if(!p)
        cout << "Allocation of memory failed \n";
    else
    {
        *p = 29;
        cout << "Value of p : " << *p << endl;
    } 



    float *r = new float(75.23);
    cout << "Value of r : " << *r << endl;

    int n;
    cout << "Enter the size of an array: ";
    cin>> n;
    
    int *q = new (nothrow) int[n];
    if(!q)
        cout << "Allocation of memory failed \n";
    else
    {
        for(int i =0; i<n; i++)
            q[i] = i + 1;
    }

    cout << "Value store in block of memory using index: ";
    for(int i =0; i<n; i++)
        cout << q[i] << " ";
    cout << "\nValue store in block of memory using ptr: ";

      for(int i =0; i<n; i++)
      {
           cout << *q<< " ";
           q++;
           
      }
       
    cout << endl;


    
    // delete p;
    // delete r;

    // delete [] q;
    return 0;




}


