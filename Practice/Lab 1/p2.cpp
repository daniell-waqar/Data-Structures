
//pointers

#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter the value :" ;
    cin >> a;

    int *p;

    p = &a;


    cout << "value of variable a = " << *p << endl;
    cout << "Address of variable a " << p << endl;


    

}