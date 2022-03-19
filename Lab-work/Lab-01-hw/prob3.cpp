#include <iostream>
using namespace std;
 
int CommonElem(int* arr1, int* arr2)
{
 
    int arr3[5];
   for(int i = 0; i < 5;i++)
   {
       for(int j = 0; j < 5 ;j++)
       {
            if(arr1[i] == arr2[j])      //compare elements of both arr1 and arr2
            {
                int x = 0;

                arr3[x] = arr1[i];
                cout << arr3[x] << " " << endl;
                x++;

        
            }

       }

   }


} 
 
int main() 
{

   int arr1[5] = {2,3,4,5,6};
   int arr2[5] = {4,6,7,1,8};

   CommonElem(arr1,arr2);

  


   return 0;
}