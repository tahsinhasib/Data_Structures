/*
    C++ Implementation of the Quick Sort Algorithm.
*/

#include <iostream>
using namespace std;


int partition(int arr[], int start, int end){

	int pivot = arr[start];
	int count = 0;
    
	for(int i=start+1; i<=end; i++){
		if(arr[i] <= pivot){
            		count++;
        	}
	}
	int pivotIndex = start + count;                 // Giving pivot element its correct position
	swap(arr[pivotIndex], arr[start]);
	int i=start, j=end;                             // Sorting left and right parts of the pivot element

	while(i<pivotIndex && j>pivotIndex){

		while(arr[i] <= pivot){
			i++;
		}
		while(arr[j] > pivot) {
			j--;
		}
		if(i<pivotIndex && j>pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;
}


void quickSort(int arr[], int start, int end){

	if(start >= end){
        return;                                     // base case
    }                               
	int p = partition(arr, start, end);             // partitioning the array
	quickSort(arr, start, p-1);                     // Sorting the left part
	quickSort(arr, p+1, end);                       // Sorting the right part
}


int main()
{
	int arr[] = { 9, 3, 4, 2, 1, 8 };
	int n = 6;

	quickSort(arr, 0, n-1);

	for(int i=0; i<n; i++){                         // printing the sorted array
		cout << arr[i] << " ";
	}

	return 0;
}
