//pointers with functions

#include <iostream>
using namespace std;

void swap(int * , int *);

int main()
{
    int a, b;
    a = 10;
    b = 20;

    swap(&a , &b);

    cout << "Values after exchange : " << endl;

    cout << "Value of a = " << a << endl;
    cout << "Value of b = " << b << endl;

    return 0;

}

void swap(int *x , int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;

}