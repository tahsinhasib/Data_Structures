#include<iostream>
using namespace std;

/*
	A linked list is a linear data structure, in which the elements are not stored at 
	contiguous memory locations. 
*/

struct Node{										// a linked list node
	int data;										// a sturcture variable (can be any)
	struct Node *next;								//
};

Node *head;

/*
	To access members of a structure, use the dot operator. 
	To access members of a structure through a pointer, use the arrow operator.
*/



Node *GetNewNode(int x){
	Node *NewNode = new Node();						// dinamically space allocation
	NewNode->data=x;								// to access structure through a pointer
	NewNode->next=NULL;								// a pointer which points at the next node
	return NewNode;									// returns NewNode
}

void InsertAtHead(int x){							// at first
	Node *NewNode = GetNewNode(x);					// GetNewNode is called for creating a new node
	NewNode->next = head;
	head = NewNode;
}

void InserAtTail(int x){
	Node *NewNode = GetNewNode(x);
	if (head==NULL){								// if head is not full then it is the tail
		head=NewNode;
		return;
	}

	Node *temp=head;								// stores the created node(head) temporary

	while (temp->next != NULL){
		temp=temp->next;
	}
	temp->next = NewNode;
}

void InserAtAnyPosition(int n, int x){
	Node *NewNode = GetNewNode(x);
	if(n==1){
		NewNode->next = head;
		head = NewNode;
		return;
	}

	Node *temp = head;
	for (int i=1; i<n-1; i++){
		temp = temp->next;
	}
	NewNode->next = temp->next;
	temp->next = NewNode;
}

void Delete(int n){
	if (head==NULL){
		cout << "Error: Nothing to delete " << endl;
		return;
	}
	Node *temp = head;

	if(n==1){
		head = temp->next;
		delete temp;
		return;
	}

	for(int i=1; i<n-1; i++){
		temp = temp->next;
	}
	Node *temp2 = temp->next;
	temp->next = temp2->next;

	delete temp2;

	return;
}

void DeleteTail(){
	Node *temp=head;
	Node *temp2=temp;

	int i=0;

	while(temp->next != NULL){
		if(i>0){
			temp2 = temp2->next;
		}
		temp = temp->next;
		++i;
	}

	temp2->next = NULL;
	delete temp;
}

void Traverse(){
	Node *temp=head;
	cout << "List is: ";

	while(temp!=NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void Search(int x){
	Node *temp=head;

	while(temp!=NULL){
		if(temp->data==x){
			cout << "Found" << "\n";
			return;
		}
		temp=temp->next;
	}
	cout << "Not found" << "\n";
}

int main()
{
	head = NULL;

	InsertAtHead(5);
	InsertAtHead(6);
	InsertAtHead(7);
	InsertAtHead(8);

	Traverse();

	InserAtTail(9);
	InserAtTail(10);

	Traverse();

	InserAtAnyPosition(2, 11);

	Traverse();

	Delete(5);

	Traverse();

	Search(10);
	Search(100);

	Delete(1);

	Traverse();

	DeleteTail();

	Traverse();
}

