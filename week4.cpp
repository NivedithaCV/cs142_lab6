//BINARY SEARCH TREE
//library
#include<iostream>
using namespace std;

class Node		//node
{	public:
	int data;	//value
	Node*left;	//pounter to left
	Node*right;	//pointer to right
	Node(int value)	//default constructor
	{
		data=value;
		left=NULL;
		right=NULL;
	}
};

class bst			//defining binary search tree
{	public:
	Node*root;		//head of bst
	bst()
	{
		root=NULL;	
	}
	
	void insert(int value)	//function to insert
	{
	insertHelper(root,value);
	}
	void insertHelper(Node*curr,int value)	//inserting function
	{
	
		if(curr==NULL)		//checks if end
		{
			curr=new Node(value);//insert node
			
			if(root==NULL)	//checks if root is null
			root=curr;	//if assigns
			return;
		}
		else		//if not end
		{
			if(value<curr->data)	//checks the value is less than current nodes data
			{
				if(curr->left==NULL)	//if end new node inserted
				curr->left=new Node(value);
				else 
				insertHelper(curr->left,value);	//else move to left
			}
			else				//checks if greater than or equal to
			{
				if(curr->right==NULL)	//checks if node is leaf
				curr->right=new Node(value);	//inserting node at the leaf
				else
				insertHelper(curr->right,value);	//else moves to right
			}
		}
	}

	void display()		//display function
	{
		display2(root);	//recurtion
		cout<<endl;
	}
	void display2(Node*curr)
	{	
		if(curr==NULL)		//if at the end stop
		return;
		display2(curr->left);	//moving to the left and prints
		cout<<curr->data<<" ";
		display2(curr->right);	//move to the right
		
	}
	void search(int value){
         
	if(search2(root,value)==NULL)	//checks if any node is returned
	cout<<"not found"<<endl;
	else
	cout<<"found"<<endl;
    	}
    	Node*search2(Node *curr, int value)
	{
        // Are you the value? or Are you NULL?  if yes return curr
        if(curr == NULL || curr->data == value ) return curr;
        // else you search in right or left. 
        // Left
        else if(value < curr->data)  search2(curr->left, value);
        // Right
        else   search2(curr->right, value);
    	}

};

int main()		//main function
{
	 bst b1;
	b1.insert(3);
	b1.insert(5);
	b1.insert(6);
	b1.insert(45);
	b1.insert(10);
	b1.insert(8);
	b1.insert(5);
	b1.insert(4);
	b1.display();	//call for the dispaly function
	b1.search(100);	//call for the search function
	return 0;
}
