// constructor and destructor

#include <iostream>
using namespace std;

class Box
{
    public:

      Box()
      {
          cout << "Constructor called! " << endl;
      }

      ~Box()
      {
          cout << "Destructor called! " << endl;
      }

};

int main()
{
    Box* myBoxArray  = new Box[4];   //here four objects will be created for each objects constructor & destructor called
    delete[] myBoxArray;   //delete array
}