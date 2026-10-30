// This is the quick sort program using middle of 3 random values as pivot.
// Remember the time taken to sort that array.
// Try different array sizes to sort.
// Observe the time taken as a function of array size (maybe using a graph).

#include <iostream>
#include <ctime>
using namespace std;

// verify that it is indeed sorted
int verify(int A[], int n) {
    for (int i = 1; i < n; i++)
        if (A[i-1] > A[i]) return 0;
    return 1;
}

int partition(int A[], int left, int right) {
    int pivotloc;

    int r1 = rand() % (right-left+1) + left;
    int r2 = rand() % (right-left+1) + left;
    int r3 = rand() % (right-left+1) + left;
    if (A[r1] <= A[r2]) {
       if (A[r2] <= A[r3]) pivotloc = r2; // r2 is pivot
       else if (A[r1] <= A[r3]) pivotloc = r1; // r1 is pivot
       else pivotloc = r3; // r3 is pivot
    } else {
       if (A[r2] >= A[r3]) pivotloc = r2; // r2 is pivot
       else if (A[r1] >= A[r3]) pivotloc = r3; // r3 is pivot
       else pivotloc = r1; // r1 is pivot
    }
    // swap pivot to right to align with Lomuto
    int pivot = A[pivotloc];
    A[pivotloc] = A[right];
    A[right] = pivot;
    int i = left-1;
    for (int j=left; j<=right-1; j++)
        if (A[j] <= pivot) {
           i++;
           int temp = A[i];
           A[i] = A[j];
           A[j] = temp;
        }
    int temp = A[i+1];
    A[i+1] = A[right];
    A[right] = temp;
    return i+1;
}

void quicksort(int A[], int left, int right) {
    if (left < right) {
       int p = partition(A,left,right);
       quicksort(A,left,p-1);
       quicksort(A,p+1,right);
    }
}

int main(int argc, char *argv[]) {
    int i, length;

    cout << "Input number of items" << endl;
    cin >> length;
    int *myarray = new int[length]; // create the array
    // generate many 6 digit numbers in the array
    for (i = 0; i < length; i++) myarray[i] = rand() % 1000000;
    // disable output
    // cout << "Input array" << endl;
    // for (i = 0; i < length; i++) cout << myarray[i] << " ";
    // cout << endl;

    // test for worst case, sort the input as the new input
    //quicksort(myarray,0,length-1);
    //if (verify(myarray,length)) printf("Input array is sorted\n");

    cout << "Sorting " << length << " items" << endl;
    timespec start;
    timespec_get(&start, TIME_UTC);
    quicksort(myarray,0,length-1);
    timespec end;
    timespec_get(&end, TIME_UTC);
    int sec = end.tv_sec - start.tv_sec;
    int nsec = end.tv_nsec - start.tv_nsec;
    if (nsec < 0) { nsec = nsec+1000000000; sec--; }
    printf("Time to sort %d items is %d.%09d seconds\n",length,sec,nsec);
    // disable output
    // cout << "Sorted array" << endl;
    // for (i = 0; i < length; i++) cout << myarray[i] << " ";
    // cout << endl;
    if (verify(myarray,length)) printf("Indeed sorted\n");
}
