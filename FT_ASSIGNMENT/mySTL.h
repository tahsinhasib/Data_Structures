// MD.TAHSIN HASIB 22-46026-1

#include<iostream>
#include<stdlib.h>
using namespace std;

/*
    Template class T is used for singly linked list
    Template class K is used for doubly linked list
    Template class B is used for Binary search tree
    Template class S is used for Stack linked list
    Template class Q is used for Queue linked list

*/


//------------------------------------------------------------------------------------------------
//---------------------------------- Singly Functions --------------------------------------------
//------------------------------------------------------------------------------------------------

//SNode is for singly linked list
template <class T>
class SNode{
    private:
        T data;
        SNode<T>* next;
        template<class U>
        friend class SinglyLinkedList;
    public:
        SNode(){
            this->next = NULL;
        }
};


template <class T>
class SinglyLinkedList{
    private:
        SNode<T> *head;
    public:
        SinglyLinkedList(){
            this->head = NULL;
        }


    //(a) inserting at first
    void insertAtFirst(T item){
        SNode<T>* Snode = new SNode<T>[1];
        Snode->data = item;
        if(head == NULL){
            head = Snode;
            cout << "Element inserted at                    : first!" << "\n";
            return;
        }
        Snode->next = head;
        head = Snode;
        cout << "Element inserted at                    : first!" << "\n";
    }


    //(d) inserting before element
    void insertBeforeElement(int element, T item){
        SNode<T> *Snode = new SNode<T>[1];
        Snode->data = item;
        SNode<T> *temp = head;

        int flag = 1;
        while (temp != NULL){
            if(temp->data == element){
                // break if it's in the first node
                break;
            }
            else{
                temp = temp -> next;
                flag++;
            }
            if(flag==1){
                Snode->next = head;
                head = Snode;
                cout << "Item inserted before the element       : " << element << "\n";
                return;
            }
            else{
                SNode<T> *temp2 = head;
                for(int i=1; i<flag-1; i++){
                    temp2 = temp2->next;
                }
                Snode->next = temp2->next;
                temp2->next = Snode;
                cout << "Item inserted before the element       : " << element << "\n";
                return;
            }
        }
    }




    //(c) for inserting at any position
    void insertAtAnyPos(int index, T item){
        SNode<T> *Snode = new SNode<T>[1];

        Snode->data = item;
        int count = 0;
        SNode<T> *temp = head;

        while(temp != NULL && count < index){
            if(count == index-1){
                if(temp->next != NULL){
                    Snode->next = temp->next;
                }
                temp->next = Snode;
                cout << "Element inserted at index no           : " << index << "!" << "\n";
                break;
            }
            count++;
            temp = temp->next;
        }           
    }
        

    //(b) for inserting at last
    void insertAtLast(T item){
        SNode<T> *Snode = new SNode<T>[1];
        Snode->data = item;

        if(head==NULL){									
		    head = Snode;		
            cout << "Element inserted at                    : last!" << "\n";						
		    return;										
	    }
	    SNode<T> *temp=head;											

	    while(temp->next != NULL){					
		    temp=temp->next;
	    }
        cout << "Element inserted at                    : last!" << "\n";
	    temp->next = Snode;
    }


    //(g) for displaying the linked list
    void displayList(){
        if(head == NULL){
            cout << "The singly linked list is empty! cannot display." << "\n";
            return;
        }
        cout << "Displaying SinglyLinkedList            : ";

        SNode<T> *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

        
    //(f) for deleting from a specific position
    void deleteAtPos(int index){
        if(head == NULL){
            cout<<"Cannot delete! the list is empty !" << "\n";
            return;
        }
            
	    SNode<T> *temp = head;

	    if(index == 1){
		    head = temp->next;
		    delete temp;
            cout << "Element deleted from position          : 1" << "\n";
		    return;
	    }
	    for(int i=1; i<index-1; i++){
		    temp = temp->next;
	    }
	    SNode<T> *temp2 = temp->next;
	    temp->next = temp2->next;
	    delete temp2;

        cout << "Element deleted from position          : " << index << "\n";
	    return;
    }


    //(e) deleting element by value
    void deleteElementByValue(int element){
        SNode<T> *Snode = new SNode<T>[1];
        SNode<T> *temp = head;
        int n = 1;

        // traversing and tracking of the element
        while (temp != NULL){
            if(temp->data == element){
                // encounter results in break
                break;
            }
            else{
                temp = temp->next;
                n++;
            }
        }
        // deleting the element
        if(head == NULL){
            cout << "The singly linked list is empty! can't delete" << "\n";
            return;
        }
        SNode<T> *temp2 = head;
        if(n == 1){
            head = temp2->next;
            delete temp2;
            cout << "Succesfully deleted the element        : " << element << "\n";
            return;
        }
        for(int i=1; i<n-1; i++){
            temp2 = temp2->next;
        }
        SNode<T> *temp3 = temp2->next;
        temp2->next = temp3->next;
        delete temp3;
        cout << "Succesfully deleted the element            : " << element << "\n";
        return;
    }
};




//------------------------------------------------------------------------------------------------
//------------------------------------ Doubly Functions ------------------------------------------
//------------------------------------------------------------------------------------------------


//DNode is for Doubly linked list
template <class K>
class DNode{
    private:
        K data;
        DNode<K> *next;
        DNode<K> *prev;
        template<class V>
        friend class DoublyLinkedList;
    public:
        DNode(){
            this->next = NULL;
            this->prev = NULL;
        }
};


template <class K>
class DoublyLinkedList{
    private:
        DNode<K> *head;
    public:
        DoublyLinkedList(){
            this->head = NULL;
        }


    //(a) inserting at first
    void insertAtFirst(K item){
        DNode<K> *Dnode = new DNode<K>[1];
        Dnode->data = item;
        if(head == NULL){
            head = Dnode;
            cout << "Element inserted at                    : first!" << "\n";
            return;
        }
        head->prev = Dnode;
        Dnode->next = head;
        head = Dnode;
        cout << "Element inserted at                    : first!" << "\n";
    }


    //(c) for inserting at any position
    void insertAtAnyPos(int index, K item){
        DNode<K> *Dnode = new DNode<K>[1];
        Dnode->data = item;
        int count = 0;
        DNode<K> *temp = head;

        while(temp != NULL && count < index){
            if(count == index-1){
                if(temp->next != NULL){
                    Dnode->prev = temp;
                    Dnode->next = temp->next;
                }
                temp->next = Dnode;
                cout << "Element inserted at index no           : " << index << "!" << "\n";
                break;
            }
            count++;
            temp = temp->next;
        }           
    }


    //(d) inserting before element
    void insertBeforeElement(int element, K item){
        DNode<K> *Dnode = new DNode<K>[1];
        Dnode->data = item;
        DNode<K> *temp = head;

        int flag = 1;
        while (temp != NULL){
            if(temp->data == element){
                // break if it's in the first node
                break;
            }
            else{
                temp = temp -> next;
                flag++;
            }
            if(flag==1){
                head->prev = Dnode;
                Dnode->next = head;
                head = Dnode;
                cout << "Item inserted before the element       : " << element << "\n";
                return;
            }
            else{
                DNode<K> *temp2 = head;
                for(int i=1; i<flag-1; i++){
                    temp2 = temp2->next;
                }
                Dnode->prev = temp2;
                Dnode->next = temp2->next;
                temp2->next = Dnode;
                cout << "Item inserted before the element       : " << element << "\n";
                return;
            }
        }
    }



    //(b) for inserting at last
    void insertAtLast(K item){
        DNode<K> *Dnode = new DNode<K>[1];
        Dnode->data = item;

        if(head==NULL){									
		    head=Dnode;	
            cout << "Element inserted at                    : last!" << "\n";							
		    return;										
	    }
	    DNode<K> *temp=head;											

	    while(temp->next != NULL){					
		    temp=temp->next;
	    }
	    temp->next = Dnode;
        Dnode->prev = temp;
        cout << "Element inserted at                    : last!" << "\n";
    }


    //(g) for displaying the linked list
    void displayList(){
        if(head == NULL){
            cout << "The Doubly linked list is empty! Can't display" << "\n";
            return;
        }
        cout << "Displaying DoublyLinkedList            : ";

        DNode<K> *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

        

    //(f) for deleting from a specific position
    void deleteAtPos(int index){
        if(head == NULL){
            cout<<"Cannot delete! the list is empty !" << "\n";
            return;
        }
            
	    DNode<K> *temp = head;

	    if(index == 1){
		    head = temp->next;
            head->prev = NULL;
		    delete temp;
            cout << "Element deleted from position          : 1" << "\n";
		    return;
	    }
	    for(int i=1; i<index-1; i++){
		    temp = temp->next;
	    }
	    DNode<K> *temp2;
        temp2 = temp;
	    temp2 = temp2->next;

        DNode<K> *temp3;
        temp3 = temp2;

        temp2 = temp2->next;
        temp2->prev = temp;
        temp->next = temp2;

	    delete temp3;

        cout << "Element deleted from position          : " << index << "\n";
	    return;
    }

    //(e) deleting element by value
    void deleteElementByValue(int element){
        DNode<K> *Dnode = new DNode<K>[1];
        DNode<K> *temp = head;
        int n = 1;

        // traversing and tracking the element
        while(temp != NULL){
            if(temp->data == element){
                // encounter results in break
                break;
            }
            else{
                temp = temp->next;
                n++;
            }
        }
        // deleting process
        if(head == NULL){
            cout << "The Doubly linked list is empty! can't delete" << "\n";
            return;
        }
        DNode<K> *temp2 = head;
        if(n == 1){
            head = temp2->next;
            delete temp2;
            cout << "Succesfully deleted the element        : " << element << "\n";
            return;
        }
        for(int i=1; i<n-1; i++){
            temp2 = temp2->next;
        }
        DNode<K> *temp3 = temp2->next;
        temp2->next = temp3->next;
        delete temp3;
        cout << "Succesfully deleted the element            : " << element << "\n";
        return;
    }
};





//------------------------------------------------------------------------------------------------
//------------------------------ Binary Search Tree Functions ------------------------------------
//------------------------------------------------------------------------------------------------





template <class B>
class BSTNode{
    B data;
    BSTNode<B> *left;
    BSTNode<B> *right;
    template<class W>
    friend class BinarySearchTree;

    BSTNode(B val){
        data = val;
        left = NULL;
        right = NULL;
    }
};



template <class B>
class BinarySearchTree{
    private:
        BSTNode<B> *root;


    //(a) inserting into Binary Search Tree
    BSTNode<B> *insertIntoBST(B val, BSTNode<B> *temp){
        if(temp == NULL){
            temp = new BSTNode<B>(val);
            cout << "Inserted in the tree!" << "\n";
        }
        else if(val <= temp->data){
            temp->left = insertIntoBST(val, temp->left);
        }
        else{
            temp->right = insertIntoBST(val, temp->right);
        }
        return temp;
    }


    //(c) displaying inorder
    void displayInorder(BSTNode<B> *temp){
        if(temp == NULL){
            return;
        }
        displayInorder(temp->left);
        cout << temp->data << " ";
        displayInorder(temp->right);
    }


    //(d) displaying preorder
    void displayPreorder(BSTNode<B> *temp){
        if(temp == NULL){
            return;
        }
        cout << temp->data << " ";
        displayPreorder(temp->left);
        displayPreorder(temp->right);
    }


    //(e) displaying postorder
    void displayPostorder(BSTNode<B> *temp){
        if(temp == NULL){
            return;
        }
        displayPostorder(temp->left);
        displayPostorder(temp->right);
        cout << temp->data << " ";
    }


    //(b) searching in Binary Search Tree
    void searchInBST(B val, BSTNode<B> *temp){
        if(temp == NULL){
            cout << "The Tree is empty!" << "\n";
            return;
        }
        else if(temp->data = val){
            cout << "Search results             : Search found!" << "\n";
        }
        else if(temp->data > val){
            searchInBST(val, temp->left);
        }
        else if(temp->data < val){
            searchInBST(val, temp->right);
        }
        else{
            cout << "Search results            : Search not found!" << "\n";
        }
    }

    public:
    // methods for calling inside the class with internal roots
    BinarySearchTree(){
        root = NULL;
    }
    void insertIntoBST(B val){
        root = insertIntoBST(val, root);
    }
    void displayInorder(){
        cout << "Inorder Traversal          : ";
        displayInorder(root);
    }
    void displayPreorder(){
        cout << "Preorder Traversal         : ";
        displayPreorder(root);
    }
    void displayPostrder(){
        cout << "Postorder Traversal        : ";
        displayPostorder(root);
    }
    void searchInBST(B val){
        cout << "Element for search         : " << val << "\n"; 
        searchInBST(val, root);
    }

};



//------------------------------------------------------------------------------------------------
//------------------------------ Stack Linked List operations ------------------------------------
//------------------------------------------------------------------------------------------------



template <class S>
class StackNode{
    private:
        S data;
        StackNode<S> *next;
        template<class U>
        friend class StackLinkedList;
    public:
        StackNode(){
            this->next = NULL;
        }
};



template <class S>
class StackLinkedList{
    private:
        StackNode<S> *top;

    public:
        StackLinkedList(){
            this->top = NULL;
        }

    //(a) pushing into stack
    void push(S item){
        StackNode<S>* node = new StackNode<S>[1];
        node->data = item;
        node->next = top;
        top = node;
        cout << "Pushed into the stack!" << "\n";
    }


    //(c) showing top
    void topVal(){
        cout << "Top data                   : " << top->data << "\n";
    }


    //(b) popping items from stack
    void pop(){
        if(top == NULL){
            cout << "The linked list is underflowing" << "\n";
        }
        else{
            cout << "Item popped!" << "\n";
            cout << "The popped element is      : " << top->data << "\n";
            top = top->next;
        }
    }
};





//------------------------------------------------------------------------------------------------
//------------------------------ Queue Linked List operations ------------------------------------
//------------------------------------------------------------------------------------------------





template <class Q>
class QueueNode{
    private:
        Q data;
        QueueNode<Q> *next;
        //QueueNode<Q> *front;
        //QueueNode<Q> *rear;
        //QueueNode<Q> *temp;
        template<class Z>
        friend class QueueLinkedList;
    public:
    
    QueueNode(){
        this->next = NULL;       
    }
};


template <class Q>
class QueueLinkedList{
    private:
        QueueNode<Q> *front = NULL;
        QueueNode<Q> *rear = NULL;
        QueueNode<Q> *temp;

    public:
        
    //(a) for enqueing elements
    void enqueue(Q val){
        if(rear == NULL){
            QueueNode<Q>* node = new QueueNode<Q>[1];
            rear = node;
            rear->next = NULL;
            rear->data = val;
            front = rear;
        }
        else{
            QueueNode<Q>* node = new QueueNode<Q>[1];
            temp = node;
            rear->next = temp;
            temp->data = val;
            temp->next = NULL;
            rear = temp;
        }
        cout << "Element enqueued!" << "\n";
    }


    //(b) for dequeing elements
    void Dequeue(){
        temp = front;

        if(front == NULL){
            cout << "List Underflow" << "\n";
            return;
        }
        else if(temp->next != NULL){
            temp = temp->next;
            cout << "Element dequeued!" << "\n";
            cout <<"Element deleted from queue     : " << front->data << "\n";
            free(front);
            front = temp;
        }
        else{
            cout << "Element dequeued!" << "\n";
            cout << "Element deleted from queue    : " << front->data << "\n";
            free(front);
            front = NULL;
            rear = NULL;
        }
    }


    
    
    void Display(){
        temp = front;

        if((front == NULL) && (rear == NULL)){
            cout << "List is empty" << "\n";
            return;
        }
        cout << "List elements are              : ";
        while(temp != NULL){
            cout << temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
    

    //(c) displaying the front
    void frontVal(){
        cout << "Front value is                 : " << front->data << "\n";
    }


    //(d) displaying the rear
    void rearVal(){
        cout << "Rear value is                  : " << rear->data << "\n";
    }
};