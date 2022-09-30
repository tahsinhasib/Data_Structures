#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;

    int i, j;
    int temp;

    int arr[size];
    cout << "\nEnter elements: ";
    for(i=0; i<size; i++){          //for array elements input
        cin >> arr[i];
    }

    cout << "\nYour array: ";
    for(i=0; i<size; i++){          //printing my array (unsorted)
        cout << arr[i] << " ";
    }

    for(i=0; i<size-1; i++){
        for(j=0; j<size-1-i; j++){
            if(arr[j]<arr[j+1]){    //Decending order
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "\nAscending array: ";
    for(i=0; i<size; i++){          //printing the array (sorted)
        cout << arr[i] << " ";
    }

    getch();
}