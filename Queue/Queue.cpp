#include<iostream>
using namespace std;

int Queue[5];
int front=-1;
int rear=-1;

bool isFull(){
    if(rear==4){
        cout << "Queue is full!\n";
        return true;
    }
    else{
        cout << "Queue is not full!\n";
        return false;
    }
}

bool isEmpty(){
    if(front==-1){
        cout << "Queue is empty!\n";
        return true;
    }
    else{
        cout << "Queue is not empty!\n";
        return false;
    }
}

void Enqueue(int value){
    if(rear==4){
        cout << "Queue is full!\n";
    }
    else{
        front=0;
        rear++;
        Queue[rear]=value;
        cout << "Queue enqueued!\n";
    }
}

void Dequeue(){
    if(front==-1){
        "Queue is empty!\n";
    }
    else{
        if(front>=rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
        cout << "Queue dequeued!\n";
    }
}

void FrontValue(){
    if(front==-1){
        cout << "Queue is empty!\n";
    }
    else{
        cout << "\nQueue front: " << front << "\n";
        cout << "Queue rear: " << rear << "\n";
    }
}

void showQueue(){
    if(front==-1){
        cout << "Queue is empty!\n";
    }
    else{
        cout << "\nQueue elements: ";
        for(int i=front; i<=rear; i++){
            cout << Queue[i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cout << "\n";

    isFull();
    isEmpty();

    cout << "\n------------------------------\n";

    Enqueue(5);
    Enqueue(6);
    Enqueue(7);
    Enqueue(8);
    Enqueue(9);

    isFull();
    isEmpty();

    FrontValue();

    showQueue();

    cout << "\n------------------------------\n";

    Dequeue();
    Dequeue();

    FrontValue();

    showQueue();

    isFull();
    isEmpty();
    


    return 0;
}