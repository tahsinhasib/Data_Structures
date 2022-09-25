#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int arr[100];
    int n;

    cout << "-----------------------------------";
    cout << "\nEnter the number of elements: ";
    cin >> n;

    cout << "\nEnter elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int position;
    int value;

    cout << "\nEnter the position: ";
    cin >> position;

    cout << "\nEnter the value: ";
    cin >> value;

    for(int i=n-1; i>=position-1; i--){
        arr[i+1] = arr[i];
    }
    
    arr[position-1] = value;

    cout << "\nValue after: ";
    for(int i=0; i<=n; i++){
        cout << arr[i] << " ";
    }

    getch();
}
