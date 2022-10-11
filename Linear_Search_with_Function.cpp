#include<iostream>
#include<conio.h>
using namespace std;

void LinearSearch(int arr[], int size, int element){
    int i;
    int flag=0;
    for(i=0; i<size; i++){
        if(arr[i]==element){
            flag=1;
            break;
        }
    }
    if(flag==1){
        cout << "Element was found at index no: " << i;
    }
    else{
        cout << "Not found!";
    }
}
int main()
{
    int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};
    int size = sizeof(arr)/sizeof(int);

    int element=0;
    
    LinearSearch(arr, size, element);
    
    getch();
}