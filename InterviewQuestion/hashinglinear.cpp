#include<iostream>
#include<string>

using namespace std;

class Students{
    public:
int rollNo;
// string name;

Students(){

}

};

class Hashtable {
Students **arr;
int size;
int count;
public:

Hashtable(int s){
size = s;
count = 0;
arr = new Students*[size];

for(int i =0 ; i<size ; i++)
arr[i] = NULL;
}

int hashin(int n){
 return n%size;
}


void insert(int key){  /// ,string value
    if(count == size){
    cout<<"hash is full";
    return;
    }

    int hashindex = hashin(key);
    while(arr[hashindex] != NULL){
        hashindex = (hashindex +1) %size;
    }
    arr[hashindex] = new  Students();
    arr[hashindex]->rollNo = key;
    // arr[hashindex]->name = value;
    count++;
}

int search (int key){
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

  
}

void deleteitem(int key){

    if(count == 0){
    cout<<"hash is empty";
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
    cout<<"not found";

    else{
        delete arr[hashindex];
        arr[hashindex] = NULL;
    }

}

void displayitem(){

    for(int i = 0 ; i<size ; i++){
        if(arr[i]!= NULL)
        cout<<"Hash table ["<<i<<"] : key  "<<arr[i]->rollNo<<endl; // arr[i]->name
    }
}



// ~Hashtable(){

//     for(int i = 0 ; i<size ; i++){
//         if(arr[i]!= NULL){
//             cout<<"deleting key"<<arr[i]->rollNo<<"value"<<arr[i]->name<<endl;
//             delete arr[i];
//             arr[i] = NULL;
//         }
//     }
// }


};

int main(){

    Hashtable mt(25);

mt.insert(652 );
mt.insert(65402 );
mt.insert(65405 );
mt.insert(65403 );
mt.displayitem();
mt.getitem(6542);

return 0;
}