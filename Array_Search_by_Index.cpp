/*
    A C++ program to search an the index of the specific element of an array
*/

#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};
    int n, i;

    cout << "Enter the element which's index you want to search: ";
    cin >> n;

    for(i=0; i<5; i++){
        if(n==arr[i]){
            break;
        }
    }

    cout << n << " Was found at index no " << i << endl;

}
