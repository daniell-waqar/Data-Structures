

#include <iostream>
using namespace std;

void pp(char * );

int main()
{
    char st[] = "pakistan";
    pp(st);   //always pass by ref


}


void  pp (char *ss)
{
    while(*ss != '\0')
    {
        cout << *ss << endl;
        *ss++;
    }
}