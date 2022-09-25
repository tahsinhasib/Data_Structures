/*
            Traverse Operation

This operation is to traverse through the elements of an array.

*/



#include<stdio.h>

int main()
{
    int arr[] = {1,3,5,7,8};
    printf("\nThe array elements are : \n");

    int i=0;
    for (int i = 0; i < 5; i++)
    {
        printf("array[%d] = %d\n", i, arr[i]);
    }


}
