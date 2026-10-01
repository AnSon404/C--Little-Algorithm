#include <stdio.h>
#include <stdlib.h>

void SelectionSort (int* A, int n) {
    int i, j, k, temp;

    for ( i=0; i<n-1; i++ ) {
        k = i;
        for ( j=i+1; j<n; j++ )
            if  ( A[k] > A[j] ) k = j;
        temp = A[i];
        A[i] = A[k];
        A[k] = temp;
    }
}

int main() {
    int i, length;

    printf("Input number of items\n");
    scanf("%d",&length);
    int *myarray = (int*)malloc(sizeof(int)*length); // create the array
    printf("Please input your data\n");
    for (i = 0; i < length; i++)
        scanf("%d",&myarray[i]);
    printf("Input array\n");
    for (i = 0; i < length; i++)
        printf("%d ",myarray[i]);
    printf("\n");
    SelectionSort( myarray, length );
    printf("Sorted array\n");
    for (i = 0; i < length; i++)
        printf("%d ",myarray[i]);
    printf("\n");
}
