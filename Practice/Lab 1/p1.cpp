//pointers

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int *x, *y;
    a = 33;
    b = 66;

    x = &a;
    y = &b;


    cout << "Memory address of var a " << x << endl;
    cout << "Memory address of var b " << y << endl;

    return 0;

}