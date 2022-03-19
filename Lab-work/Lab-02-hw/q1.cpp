
#include <iostream>
using namespace std;

int main()
{   

    int siz;
    int elements;
    int *current;
    int pos ;
    int *p = new int[5];
    current = p;        // by doing this "current" will point to the 0th index of an array
    cout << "Enter Size : ";
    cin>> siz;
    cout<<"Size of an array is :"<<siz<<endl<<"How many elements you want to assign to an array: ";
    cin>>elements;
   
    if(elements > siz)
    {
        cout<<"Size of an array is "<<siz<<" you can't add "<<elements<<" elements"<<endl;

    }
   

    else
    {

        for(int i=0; i<elements;i++)
        {
            cout<<"Enter the "<<i+1<<" element: ";
            cin>>*current;
            current++;
            

        }

    
    cout<<endl;
    cout << "If you enter negative value : " << endl;
    cin >> pos;
   
    if(pos < 0)
    {
        cout << "Invalid position " << endl;
    }

  }
}


 
 
