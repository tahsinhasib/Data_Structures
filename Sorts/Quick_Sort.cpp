#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot){
            i++;
        }
        while (arr[j] > pivot){
            j--;
        }
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    /* recursion */
    if (left < j){
        quickSort(arr, left, j);
    }
    if (i < right){
        quickSort(arr, i, right);
    }
}

int main() {

    cout << "\n";
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "The unsorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
    quickSort(arr, 0, n-1);

    cout << "The sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
    return 0;
}
