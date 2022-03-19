// Explain the prefix and postfix pointers with proper and reasonable comments on each statement about
// the working of pointers.
#include<iostream>
using namespace std;

int main()
{
    int a = 5, b = 10;
    int c;
    int* p1, * p2;
    p1 = &a;
    p2 = &b;
    c = *p1;
    cout << "*(p1++) =" << *(p1++) << endl;    //increment pointer, dereference not-incremented address
    cout << "value of p1 " << p1 << endl;
    cout << "*(++p1) =" << *(++p1) << endl;   //increment pointer,  dereference incremented address
                                            

    cout << "value of p1 " << p1 << endl;
    cout << "(*p1)++ =" << (*p1)++ << endl;    // dereference pointer, post-increment the value
    cout << "value of p1 " << p1 << endl;
    cout << "++(*p1) =" << ++(*p1) << endl;    //dereference pointer,pre-increment the value
    cout << "value of p1 " << p1 << endl;
    return 0;
}