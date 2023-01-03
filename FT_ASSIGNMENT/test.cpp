// MD.TAHSIN HASIB 22-46026-1

#include<iostream>
#include<stdlib.h>
#include "mySTL.h"
using namespace std;


int main()
{
    cout << "************************************************************" << "\n";
    cout << "************** Singly Linked List operations ***************" << "\n";
    cout << "************************************************************" << "\n";

    // here we're passing integer type in singly linked list
    SinglyLinkedList<int> SList;            

    SList.insertAtFirst(8);
    SList.insertAtFirst(9);
    SList.insertAtFirst(12);
    SList.insertAtAnyPos(2, 7);
    SList.displayList();
    cout << "\n";
    SList.deleteAtPos(3);
    SList.displayList();
    cout << "\n";
    SList.insertAtLast(69);
    SList.displayList();
    cout << "\n";
    SList.insertBeforeElement(9, 88);
    SList.displayList();
    cout << "\n";
    SList.deleteElementByValue(12);
    SList.displayList();
    cout << "\n\n";


    cout << "************************************************************" << "\n";
    cout << "************** Doubly Linked List operations ***************" << "\n";
    cout << "************************************************************" << "\n";

    // here we're passing integer type in doubly linked list
    DoublyLinkedList<int> DList;            

    DList.insertAtFirst(5);
    DList.insertAtFirst(8);
    DList.insertAtFirst(9);
    DList.insertAtAnyPos(3, 70);
    DList.displayList();
    cout << "\n";
    DList.insertAtLast(100);
    DList.displayList();
    cout << "\n";
    DList.deleteAtPos(4);
    DList.displayList();
    cout << "\n";
    DList.insertBeforeElement(8, 35);
    DList.displayList();
    cout << "\n";
    DList.deleteElementByValue(9);
    DList.displayList();
    cout << "\n\n";


    cout << "************************************************************" << "\n";
    cout << "************** Binary Search Tree operations ***************" << "\n";
    cout << "************************************************************" << "\n";

    // here we're passing integer type in Binary Search Tree
    BinarySearchTree<int> bst;

    bst.insertIntoBST(5);
    bst.insertIntoBST(3);
    bst.insertIntoBST(2);
    bst.insertIntoBST(4);
    bst.insertIntoBST(7);
    bst.insertIntoBST(6);
    bst.insertIntoBST(8);

    cout << "\n";
    bst.displayInorder();
    cout << "\n";
    bst.displayPreorder();
    cout << "\n";
    bst.displayPostrder();
    cout << "\n";
    bst.searchInBST(5);
    cout << "\n\n";


    cout << "************************************************************" << "\n";
    cout << "*************** Stack Linked List operations ***************" << "\n";
    cout << "************************************************************" << "\n";

    // here we're passing integer type in Stack Linked List
    StackLinkedList<int> stk;
    
    stk.push(1);
    stk.push(3);
    stk.push(9);
    stk.push(15);
    stk.push(5);
    stk.push(2);
    stk.topVal();
    stk.pop();
    stk.topVal();
    cout << "\n\n";


    cout << "************************************************************" << "\n";
    cout << "*************** Queue Linked List operations ***************" << "\n";
    cout << "************************************************************" << "\n";


    // here we're passing integer type in Queue Linked List
    QueueLinkedList<int> que;

    que.enqueue(5);
    que.enqueue(7);
    que.enqueue(9);
    que.enqueue(1);
    que.enqueue(3);
    que.Display();
    que.Dequeue();
    que.Display();
    que.frontVal();
    que.rearVal();
    cout << "\n\n";


    cout << "\n";
    return 0;
}