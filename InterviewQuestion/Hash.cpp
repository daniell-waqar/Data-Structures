#include<iostream>
#include<string>

using namespace std;

class Students{
    public:
    int rollNo;
    //string name;

};

class Hashtable {
public:
    Students **arr;
    int size;
    int counter;
    int **temp;
	int **temp2;
		// int size;
	int flag;
    int percent;

public:
    void insert(int);
    void checking();
		int searchingPrime(int num);

    Hashtable(int s){
        size = s;
        counter = 0;
        arr = new Students*[size];

        for(int i =0 ; i<size ; i++)
            arr[i] = NULL;
    }
};


void Hashtable::insert(int num)
{
	int remainder = num % size;
	if (arr[remainder] == 0)
	{
		arr[remainder] = num;
		counter += 1;
		if (flag == 0)
		{
			checking();
		}
		
	}
	else
	{
		while(arr[remainder] != 0)
		{
			remainder += 1;
		}
		arr[remainder] = num;
		counter += 1;
		if (flag == 0)
		{
			checking();
		}
		
	}
}

void Hashtable::checking()
{
	if (counter == percent)
	{
		flag = 1;
		temp = arr;
		int newSize = searchingPrime(size*2);
		temp2 = new int*[newSize];

		int preSize = size;
		size = newSize;
		percent = size /2;
		arr = temp2;
		counter = 0;
		for (int i = 0; i < preSize; i++)
		{
			if (temp[i] != 0)
			{
				insert(temp[i]);
			}
		}
		flag = 0;
	}
}

int Hashtable::searchingPrime(int num)
{
	
	int flag1 = 0;
	while(1)
	{
		for (int i = 2; i < (num+1)/2; i++)
		{
			if (num % i == 0)
			{	
				flag1 = 1;
				break;
			}
		}
		if (flag1 == 1)
		{	
			num += 1;
			flag1 = 0;
		}
		else
			return num;
	}
}