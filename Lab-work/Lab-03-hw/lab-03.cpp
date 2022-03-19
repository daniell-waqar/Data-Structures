


#include<iostream>
using namespace std;
class ArrayList {
	private:
		int SIZE;
		int length;
		int pos;
		int * Array;
		int * curr;
        int *newList;
	public:
		ArrayList() {
			SIZE=10;
			Array= new int[SIZE];
            newList = new int[SIZE];
			length=0;
			pos=0;
			curr= Array;
		}
		~ArrayList() {
			delete []Array;
			delete curr;
		}
		void printArray() {
			if(length>0) {
				head();
				for(int x=0; x<length; x++)
					cout<<*curr++<<"\t";
			} else cout<<"Array is Empty"<<endl;
		}
		void InsertElement(int val) {
			if(!IsFull()) {
				head();
				curr= curr +length;
				*curr= val;
				length++;
			} else {
				cout<<"Array is Full"<<endl;
			}
		}
		
		void reverseArray() {
			int *ptr, *pn, temp;
			ptr= Array;
			pn= Array+length-1;
			int val= length/2;
			for (int i=0; i<val; i++) {
				temp= *ptr;
				*ptr= *pn;
				*pn= temp;
				ptr++;
				pn--;
			}
		}
	
		bool IsFull() {
			if (length==SIZE)
				return true;
			else return false;
		}
		bool IsEmpty() {
			if (length==0)
				return true;
			else return false;
		}
		void head() {
			curr= Array;
		}
		void tail() {
			curr= Array+length-1;
		}

		void back() {
			curr--;
		}
		void next() {
			curr++;
		}
		int Length() {
			return length;
		}
		void emptylist() {
			head();
			for (int x=0; x<SIZE; x++) {
				*curr = 0;
                curr++;
			}
		}
		void sortArray() {
			int *ptr;
			int *ptr1, *temp;
			cout << "Sorted array in Ascending order : "<< endl;
			for(int i=0; i<SIZE; i++) {
				ptr = Array+i; 
				for(int j=i+1; j<SIZE; j++) {
					ptr1 = Array+j;
					if(*ptr>*ptr1) {
						*temp  =*ptr;
						*ptr=*ptr1;
						*ptr1=*temp;
					}
				}
			
			}

		}

    
    void copy_list()
    {
        cout << "Copied list is : ";
        for(int i=0 ; i<length; i++)
        {
            newList [i]= Array[i];
            cout<<newList[i] << "       ";

          
        } 
        
    
        
    }

    bool compareList(int Array[],int newList[])
    {
         
        for(int i=0 ; i<length; i++)
        {
            if (Array[i] != newList[i])
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }


};

int main () {
	ArrayList *obj= new ArrayList();
	
	obj->emptylist();
	obj->InsertElement(1);
	obj->InsertElement(2);
	obj->InsertElement(3);
	obj->InsertElement(4);
	
	obj->printArray();
	cout<<endl;
	obj->Length();
	//obj->sortArray();
	
	
  

	//obj->printArray();
    obj->copy_list();

//    obj->compareList(Array,newList);
	cout<<endl;
	return 0;
}

