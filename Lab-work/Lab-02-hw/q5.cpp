#include<iostream>
using namespace std;

int main()
{
   //part a
    char alpha = 'Y';
   const  char* ptr;

    ptr = &alpha;
                        // it will give an error
    *ptr = 'Z';       // we cannot change the value using pointer ‘ptr’ bcz it is pointing to  constant char

    cout << *ptr << endl;

  //part b

    char * const ptr = &alpha;    //a pointer that cannot change the address it holds. 
                       
    char bravo = 'M';
    ptr = &bravo;      // once a constant pointer points to a variable then it cannot point to any other variable.

    cout << *ptr << endl;

  //part c

    const char * const ptr = &alpha;  //a constant pointer to a constant variable cannot change the address and value pointed by it.

    *ptr = 'X';

    ptr = &bravo;

    cout << *ptr << endl;





    





}