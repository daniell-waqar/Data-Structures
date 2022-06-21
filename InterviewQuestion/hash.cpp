#include<iostream>

using namespace std;


class Students{
    public:
    int rollNo;

};
class Hashing
{
	private:
		int *arr;
		int *temp1;
		int *temp2;
		
		int check;
		int h;
		int count;
	public:
		int size;
		Hashing(int s);
		void insert(int num);
		void checking();
		int searchingPrime(int num);
        int search(int);
        int hashin(int);
		void display();
		
};

Hashing::Hashing(int s)
{
	size = s;
	h = s/2;
	arr = new int[size];
	temp1 = NULL;
	count = 0;
	check = 0;
}

void Hashing::insert(int num)
{
	int remainder = num % size;
	if (arr[remainder] == 0)
	{
		arr[remainder] = num;
		count += 1;
		if (check == 0)
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
		count += 1;
		if (check == 0)
		{
			checking();
		}
		
	}
}

void Hashing::checking()
{
	if (count == h)
	{
		check = 1;
		temp1 = arr;
		int newSize = searchingPrime(size*2);
		temp2 = new int[newSize];

		int preSize = size;
		size = newSize;
		h = size /2;
		arr = temp2;
		count = 0;
		for (int i = 0; i < preSize; i++)
		{
			if (temp1[i] != 0)
			{
				insert(temp1[i]);
			}
		}
		check = 0;
	}
}

int Hashing::searchingPrime(int num)
{
	
	int check1 = 0;
	while(1)
	{
		for (int i = 2; i < (num+1)/2; i++)
		{
			if (num % i == 0)
			{	
				check1 = 1;
				break;
			}
		}
		if (check1 == 1)
		{	
			num += 1;
			check1 = 0;
		}
		else
			return num;
	}
}


void Hashing::display()
{
	for (int i = 0; i < size; i++)
	{
		cout<<arr[i]<<endl;
	}
}

// Function for searching but it will give  error that's why commented kindly check Logic


/*int Hashing::search (int key){
    if(count == 0){
        cout<< "empty";
    }
    int hashindex = hashin(key);
    int temp = hashindex;
    while(true){
        if(arr[hashindex] == NULL)
        hashindex = (hashindex +1)%size;
        else if(arr[hashindex]->rollNo != key)
        hashindex = (hashindex +1) %size;
        else
        break;

        if(hashindex == temp){
            temp = -1;
            break;
        }
  }
    if(temp == -1)
    cout<< "element not found";

     else
     cout<<"element found  ["<< arr[hashindex]->rollNo<<"]";

  
}*/

 int Hashing:: hashin(int num){
        return num%size;
    }


int main()
{
	Hashing hash(5);
	hash.insert(15);
	hash.insert(94);
	hash.insert(23);
	hash.insert(44);
	hash.insert(50);
	hash.display();
	return 0;
}