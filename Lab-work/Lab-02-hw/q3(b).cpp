#include <iostream>
using namespace std;


 //part b

int mystery2(const char*); // prototype
int main()
{
    char string1[80];  //Array of character of size 80
    cout << "Enter a string: ";
    cin >> string1;          //taking input from user 
    cout << mystery2(string1) << endl;   //call the function by passing array
} // end main

// What does this function do?
int mystery2(const char* s)           //tell the length of string entered by user
{
    int x;
    for (x = 0; *s != '\0'; ++s)          //loop will execute untill the end of string
    ++x;                                    //increment x for each iteration
    return x;                                 //return the lenght of the string
} // end function mystery2