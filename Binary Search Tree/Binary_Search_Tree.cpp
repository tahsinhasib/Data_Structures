#include<iostream>
using namespace std;

struct BstNode{
	int data;
	BstNode *left;
	BstNode *right;
};

BstNode *root;


BstNode *GetNewNode(int data){
	BstNode *NewNode = new BstNode();
	NewNode->data = data;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;
}


void PreOrder(BstNode *root){
	if(root==NULL){
		return;
	}
	cout << root->data << " ";
	
    PreOrder(root->left); //Recursion
	PreOrder(root->right); //Recursion
}

void InOrder(BstNode *root){

	InOrder(root->left);
    
    	if(root==NULL){
		return;
	}
	cout << root->data << " ";

	InOrder(root->right);
}


void PostOrder(BstNode *root){
	
	PostOrder(root->left);
    	PostOrder(root->right);

    	if(root==NULL){
		return;
	}
	cout << root->data << " ";
}



BstNode *Insert(BstNode *root, int data){
	if(root==NULL){
		root = GetNewNode(data);
	}
	else if(data <= root->data){
		root->left = Insert(root->left, data);
	}
	else{	
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(BstNode *root, int data){
	if(root==NULL){
		cout << "Error: tree is empty" << endl;
		return false;
	}
	else if(root->data == data){
		return true;
	}
	else if(data <= root->data){
		return Search(root->left, data);
	}
	else{
		return Search(root->right, data);
	}
}


int main()
{
	root = NULL;
    
	root = Insert(root, 5);
	root = Insert(root, 6);
	root = Insert(root, 4);
	root = Insert(root, 7);
	root = Insert(root, 3);
	root = Insert(root, 2);

	cout << "please enter your search item: ";

	int s;
	cin >> s;
	cout << "\n";

	if(Search(root, s) == true){
		cout << "found" << endl;
	}
	else{
		cout << "Not found" << endl;
	}

	PreOrder(root);
	
	return 0;
}
