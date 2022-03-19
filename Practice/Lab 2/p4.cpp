//2D dimensional array with pointer

#include <iostream>
using namespace std;

int main()
{
    int *val, *rows, *cols;

    int maxr, maxc, i, j;
    cout << "Enter the dimension of the array (row col): ";

    cin >> maxr >> maxc;

    val = new int[maxr * maxc];   //syntax for row num and col num in 2D array
    rows = new int[maxr];
    cols = new int[maxc];

    for(int i = 0; i< maxr; i++)
    {
        cout << "\nEnter elements for row " << i+1 << ": ";
        rows[i] = 0;

        for(int j =0; j< maxc; j++)
        {
            cin >> val[i * maxc + j];
            rows[i] = rows[i] + val[i * maxc + j];

        }

    }

    for(int j =0; j< maxc; j++)
    {
        cols[j] = 0;

        for(int i = 0; i< maxr; i++)
        {
            cols[j] = cols[j] + val[i * maxc + j];

        }

    }

    cout << "\nThe given array in 2 dimensional (alongwith rowsum and colsum) is :\n";

    for(int i = 0; i< maxr; i++)
    {
        for(int j =0; j< maxc; j++)
        {
            cout << val[i * maxc + j] << "\t";
        }

      
        cout << rows[i] << "\n";
    }

    for(int j =0; j< maxc; j++)
    {
        cout << cols[j] << "\t";

    }

    cout << endl;
    delete[] val;
    delete[] rows;
    delete[] cols;
    //getch();



}