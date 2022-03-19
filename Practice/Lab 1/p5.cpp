//pointers with functions

#include <iostream>
using namespace std;

void temp(int * , int *);

int main()
{
    int a, b;
    a = 10;
    b = 20;

    temp(&a , &b);

    cout << "Value of a = " << a << endl;
    cout << "Value of b = " << b << endl;

     return 0;

}

void temp(int *x , int *y)
{
    *x = *x + 10;
    *y = *y + 100;


}

