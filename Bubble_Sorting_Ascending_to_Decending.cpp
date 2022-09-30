#include<iostream>
#include<conio.h>
using namespace std;

void printArray(int arr[], int size){

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
}

void bubbleSort(int arr[], int size){

    int temp;
    int isSorted=0;                 //initializing isSorted=0;

    for(int i=0; i<size-1; i++){    //number of pass

        cout << "\nWorking on pass no " << i+1;
        isSorted=1;                 //if loop excecutes isSorted is said to be true

        for(int j=0; j<size-1-i; j++){
            
            if(arr[j]>arr[j+1]){    //condition for asc to dec

                temp = arr[j];      //swapping elements
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted=0;

            }
        }

        if(isSorted){
            return;
        }

    }
}

int main()
{
    int arr[] = {11,3,6,8,15,1};
    int size=6;

    cout << "\nPrinting array before sorting: ";
    printArray(arr, size);
    bubbleSort(arr, size);

    cout << "\n\nPrinting array after sorting: ";
    printArray(arr, size);

    getch();
}