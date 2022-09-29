#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int size;
    int i, j, k;

    cout << "\nEnter size: ";
    cin >> size;

    int arr[size];
    cout << "\nEnter the elements: ";
    for(i=0; i<size; i++){
        cin >> arr[i];
    }

    cout << "\nArray you created: ";
    for(i=0; i<size; i++){
        cout << arr[i] << " ";
    }


    //main code
    for(i=0; i<size; i++){
        for(j=i+1; j<size;){
            if(arr[i]==arr[j]){
                for(k=j; k<size-1; k++){
                    arr[k]=arr[k+1];
                    size--;
                }
            }
            else{
                j++;
            }
        }
    }

    cout << "\nArray after eliminating duplicates: ";
    for(i=0; i<size; i++){
        cout << arr[i] << " ";
    }

    getch();
}