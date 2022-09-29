/* MD.TAHSIN HASIB 22-46026-1

    Write a C++ program to create an integer array of size 12. Print the
    number of time each element occurs in that array. You must take the
    elements of the array from the user.

    *** There's an issue of repetiting one element more than once in this code

*/

#include<iostream>
#include<conio.h>
using namespace std;

void process(int array[], int size, int count, int i, int j){
    for(i=0; i<size; i++){
        if(array[i]==array[j]){
            count++;
        }
    }
    cout << array[j] << " occurs = " << count << " times\n";
    count=0;

    j++;

    if(j<size){
        process(array, size, count, i, j);
    }
}


int main()
{
    cout << "\n---------------------------------------";
    int size = 12;
    int array[size];
    int i=0;
    int count=0;
    int j=0;
    int next_i=0;

    cout << "\nArray_1 = ";
    for(i=0; i<size; i++){
        cin >> array[i];
    }

    cout << "\n---------------------------------------";
    cout << "\nOutput: \n";
    process(array, size, count, i, j);

    getch();
}
