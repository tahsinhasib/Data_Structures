/*
For deleting array element we will traverse the array elements by +1 starting
from the element that we want to delete and print the all indexes like as usual. 

Deletion refers to removing an existing element from the array and re-organizing all elements of an array.

For example, Arr[5] = {1,2,3,4,5};

here if want to delete element 3, we need to make changes in the index of that
element and that is increasing that index by +1 and store it in Arr[i] = Arr[i+1]
*/

#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int Arr[5] = {1,2,3,4,5};
    int pos;

    cout << "\n--------------------------------------------";
    cout << "\nEnter the number of index you want to delete: ";
    cin >> pos;

    for(int i=pos; i<5; i++){
        Arr[i] = Arr[i+1];
    }

    cout << "\nThe Array after deleting: ";
    for(int i=0; i<4; i++){
        cout << Arr[i] << " ";
    }

    getch();
}
