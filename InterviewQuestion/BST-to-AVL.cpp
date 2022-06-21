#include<iostream>
using namespace std;
class Node{
	public:
		Node *left;
		Node*right;
		int info;
		int height;

		Node(int info)
		{
			this->info=info;
			height=0;
			left=right=NULL;
		}
};

class AVLtree{
	private:

	Node*root;
	void makeEmpty(Node* t);
	Node* insert(int x,Node*t);
	Node* singleleftrotate(Node* &C);
	Node* singlerightrotate(Node*&C);
	
	Node* doubleleftrightrotate(Node* &C);
	Node* doublerightleftrotate(Node* &C);
	
	Node*findmin(Node*t);
	Node*findmax(Node *t);
	Node *remove(int x,Node*t);
	int height(Node*t);
	int getBalance(Node*t);
	void inorder(Node *t);
	
	public:
		AVLtree()
		{
			root=NULL;
		}
		void insert(int x){
			root=insert(x,root);
		}
		void remove(int x)
		{
			root=remove(x,root);
		}
		void display()
		{
			inorder(root);
			cout<<endl;
		}

	
};



Node* AVLtree::singleleftrotate(Node* &A)
{
    Node* newNode = A->right;
    A->right = newNode->left;
    newNode->left = A;
    A->height = max(height(A ->left), height(A ->right)) + 1;
    newNode ->height = max(height(newNode->right), A->height) + 1;
    return newNode;
}

Node* AVLtree::singlerightrotate(Node* &C)
{
    Node* newNode = C->left;
    C->left = newNode->right;
    newNode->right = C;
    C->height = max(height(C ->left), height(C ->right)) + 1;
    newNode ->height = max(height(newNode->left), C->height) + 1;
    return newNode;
}

Node* AVLtree::doubleleftrightrotate(Node*& t)
{
    t->left = singleleftrotate(t->left);
    return singlerightrotate(t);
}

Node* AVLtree::doublerightleftrotate(Node*& t)
{
    t->right = singlerightrotate(t->right);
    return singleleftrotate(t);
}

void AVLtree::inorder(Node *t)
{
	if(t==NULL)
	return;
	inorder(t->left);
	cout<<t->info<<" ->";
	inorder(t->right);
}
int AVLtree::height(Node* t)
{
	return(t==NULL ? -1 : t->height);
}
int AVLtree::getBalance(Node*t)
{
	if(t==NULL)
	return 0;
	else 
	return height(t->left) - height(t->right);
}
	
	
Node *AVLtree::findmin(Node *t)
{
	if(t==NULL)
	return NULL;
	else if(t->left==NULL)
		return  t;
	else 
		return findmin(t->left);
}

Node *AVLtree::findmax(Node *t)
{
	if(t==NULL)
    	return NULL;
	else if(t->right==NULL)
		return  t;
	else 
		return findmax(t->right);
}
void AVLtree::makeEmpty(Node* t) {
        if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
	
Node*  AVLtree::  insert(int x, Node* t)
    {
        if(t == NULL)
        {
            t = new Node (x);
        }
        else if(x < t->info)
        {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->info)
                    t = singlerightrotate(t);
                else
                    t = doubleleftrightrotate(t);
            }
        }
        else if(x > t->info)
        {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->info)
                    t = singleleftrotate(t);
                else
                    t = doublerightleftrotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }
   
    Node* AVLtree::remove(int x, Node* t)
    {
        Node* temp;

        if(t == NULL)
            return NULL;

        // Searching for element
        else if(x < t->info)
            t->left = remove(x, t->left);
        else if(x > t->info)
            t->right = remove(x, t->right);

    
        // With 2 children
        else if(t->left && t->right)
        {
            temp = findmin(t->right);
            t->info = temp->info;
            t->right = remove(t->info, t->right);
        }
        // With one or zero child
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if(t == NULL)
            return t;

        t->height = max(height(t->left), height(t->right))+1;

        // If Node is unbalanced
        // If left Node is deleted, right case
        if(height(t->left) - height(t->right) == 2)
        {
            // right right case
            if(height(t->left->left) - height(t->left->right) == 1)
                return singleleftrotate(t);
            // right left case
            else
                return doublerightleftrotate(t);
        }
        // If right Node is deleted, left case
        else if(height(t->right) - height(t->left) == 2)
        {
            // left left case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singlerightrotate(t);
            // left right case
            else
                return doubleleftrightrotate(t);
        }
        return t;
    }

int main()
{
	AVLtree tree1;
	tree1.insert(3);
	tree1.insert(4);
	tree1.insert(5);
	tree1.insert(6);
	tree1.insert(9);
	tree1.display();
	
}