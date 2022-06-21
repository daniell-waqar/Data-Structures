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

		int index = length / 2;
		
		if (length % 2 != 0)
			index++;
			
		for (int i = 1; i < index; i++)
		{
			temp = temp->next;
		}

		sublst = temp->next;
		sublst->prev = NULL;
		temp->next = NULL;
		

			while (sublst->next != NULL)
			{
				cout << sublst->data << " ";
				sublst = sublst->next;
			}

			cout << "After splitting List:" << endl;
			cout << sublst->data;
			cout << endl;
			return sublst;
		}


	void print()
	{
		node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
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
