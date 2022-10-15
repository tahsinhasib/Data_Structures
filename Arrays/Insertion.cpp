#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int arr[50] = {1,2,3,4,5};

    cout << "\n";
    cout << "Printing the original array: ";

    int i;

    for(i=0; i<5; i++){
        cout << arr[i] << " ";
    }

    cout << "\n-----------------------------------\n";
    cout << "Insertion process.....\n";
    
    int position;
    int value;

    cout << "\nEnter the position: ";
    cin >> position;

    cout << "\nEnter the value: ";
    cin >> value;

    for(i=5-1; i>=position-1; i--){
        arr[i+1] = arr[i];
    }

    arr[position-1] = value;

    cout << "Array after inserting value: ";
    for(i=0; i<5+1; i++){
        cout << arr[i] << " ";
    }

    getch();
}