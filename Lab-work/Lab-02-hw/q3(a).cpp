#include <iostream>
using namespace std;


//part a

void mystery1(char*, const char*); // prototype
int main()
{
    char string1[80];    //Array of character of size 80
    char string2[80];
    cout << "Enter two strings: ";
    cin >> string1 >> string2;      //taking input from user
    mystery1(string1, string2);      //call the function by passing arrays of character type
    cout << string1 << endl;
} // end main


// What does this function do?
void mystery1(char* s1, const char* s2)  //this function take two strings by refrence and concatenate them
{
while (*s1 != '\0')    //loop will execute untill the end of string
++s1;
for (; *s1 = *s2; ++s1, ++s2)  
; // empty statement
} // end



