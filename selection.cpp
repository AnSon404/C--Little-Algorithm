#include <iostream>
using namespace std;

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

    cout << "Input number of items" << endl;
    cin >> length;
    int *myarray = new int[length]; // create the array
    cout << "Please input your data" << endl;
    for (i = 0; i < length; i++)
        cin >> myarray[i];
    cout << "Input array" << endl;
    for (i = 0; i < length; i++)
        cout << myarray[i] << " ";
    cout << endl;
    SelectionSort( myarray, length );
    cout << "Sorted array" << endl;
    for (i = 0; i < length; i++)
        cout << myarray[i] << " ";
    cout << endl;
}
