//pointer to pointer

#include <iostream>
using namespace std;

int main()
{
    int a;
    int *b;
    int **c;

    a = 5;
    b = &a;
    c = &b;

    cout << "Address of var a : " << b << endl;
    cout << "Address of var b : " << c << endl;
}