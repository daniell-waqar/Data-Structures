#include <iostream>
using namespace std;

int main()
{
//  part a..... 
    int *number;
    cout << number << endl;      //No error found but Pointer does not point to any interger

    
//  part b.....   
    double *realPtr;
    long *integerPtr;
    integerPtr = realPtr;  //we can not assign a double type pointer to long type pointer.
    
    //error can be corrected by declaring realPtr of long type as below:
    long  *realPtr;

//  part c..... 

    int * x, y;    //we can not assign a normal variable to pointer type of varibale but we can assign address of that variable
    x = y;

     //error can be corrected by:
     x = &y;

     

    
//  part d..... 
    char s[] = "this is a character array";
    for (;*s != '\0'; ++s)     //we have to increament poinetr s as ++*s
    cout << *s << ' ';

//  part e..... 

    short *numPtr , result;
    void *genericPtr = numPtr;
    result = *genericPtr + 7;

//  part f....
    double x = 19.34;
    double xPtr = &x;      //only poinetr can hold address of variable, can be corrected as double *xPtr
    cout << xPtr << endl;


}