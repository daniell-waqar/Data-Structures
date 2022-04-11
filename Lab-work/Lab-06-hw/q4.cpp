#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *prev;
	node *next;

public:
	node(int val)
	{
		data = val;
		prev = NULL;
		next = NULL;
	}
};

class Dounly_linked_list
{
private:
	node *head;
	int length;

public:
	Dounly_linked_list()
	{
		head = NULL;
		length = 0;
	}

	void insertAtHead(int val)
	{
		node *n = new node(val);
		head = n;
		length++;
	}

	void insert(int val, int pos)
	{
		node *n = new node(val);
		node *temp = head;
		if (pos < 1 || pos > (length + 1))
		{
			cout << "Invalid position cannot insert!";
			return;
		}

		if (pos == 1)
		{
			n->next = head;
			head->prev = n;
			head = n;
			length++;
		}

		else
		{
			for (int i = 1; i < pos - 1; i++)
			{
				temp = temp->next;
			}

			n->next = temp->next;
			n->prev = temp;
			if (temp->next != NULL)
				temp->next->prev = n;
			temp->next = n;

			length++;
		}
	}

	node *split()
	{
		if (length < 2)
		{
			cout << "cannot split!" << endl;
		}

		
		node *temp = head;
		node *sublst;
		
		if ((length/2) % 2 != 0)
			length=(length/2)+1;
		int i=1;
		while(i<(length/2))
		{
			temp = temp->next;
			i++;
		}

		sublst = temp->next;
		sublst->prev = NULL;
		temp->next = NULL;
		node*j;
			cout << "After splitting List:" << endl;
			for(node*j=sublst;j!= NULL;j = j->next)
			{
				cout << j->data << " ";
			}
			cout << endl;
			return j;
		}


	void print()
	{
		node *temp = head;
		for(node*j=temp;j!= NULL;j = j->next)
		{
			cout <<j->data << " ";
		}
		cout << endl;
		cout << endl;
	}
};

int main()
{
	Dounly_linked_list l1;
	Dounly_linked_list l2;
	l1.insertAtHead(10);
	l1.insert(8, 2);
	l1.insert(2, 3);
	l1.insert(5, 4);
	l1.insert(9, 5);
	l1.insert(1, 6);
	

	cout << "\nBefore splitting List:" << endl;
	l1.print();
	
	cout << endl;
	l1.split();
	
	l1.print();
	cout << endl;
}
