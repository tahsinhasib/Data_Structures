#include<iostream>
using namespace std;

struct Node{										
	int data;										
	struct Node *next;								
};

Node *head;

Node *GetNewNode(int x){
	Node *NewNode = new Node();								
	NewNode->data=x;									
	NewNode->next=NULL;								
	return NewNode;									
}

											
void InsertAtHead(int x){							
	Node *NewNode = GetNewNode(x);					
	NewNode->next = head;							  
	head = NewNode;												   						
}



void InserAtTail(int x){
	Node *NewNode = GetNewNode(x);					
	if(head==NULL){									
		head=NewNode;								
		return;										
	}
	Node *temp=head;											

	while(temp->next != NULL){					
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
	for(int i=1; i<n-1; i++){
		temp = temp->next;
	}
	NewNode->next = temp->next;
	temp->next = NewNode;
}


void Delete(int n){
	if(head==NULL){
		cout << "Error: Nothing to delete " << "\n";
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
	cout << "\n";
	head = NULL;

	InsertAtHead(5);
	InsertAtHead(6);
	InsertAtHead(7);
	InsertAtHead(8);

	cout << "Traverse no - 1\n";
	Traverse();

	cout << "\n";

	InserAtTail(9);
	InserAtTail(10);

	cout << "Traverse no - 2\n";
	Traverse();

	cout << "\n";

	InserAtAnyPosition(2, 11);

	cout << "Traverse no - 3\n";
	Traverse();

	cout << "\n";

	cout << "After Deletion - 1\n";
	Delete(5);

	cout << "Traverse no - 4\n";
	Traverse();

	cout << "\n";

	cout << "Search no - 1\n";
	Search(10);
	cout << "Search no - 2\n";
	Search(100);

	cout << "\n";
	cout << "After Deletion - 2\n";
	Delete(1);

	cout << "Traverse no - 5\n";
	Traverse();

	cout << "\n";

	cout << "After Deleting tail\n";
	DeleteTail();

	cout << "Traverse no - 6\n";
	Traverse();

	cout << "\n";
	return 0;
}
