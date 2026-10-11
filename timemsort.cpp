// This is the merge sort program.
// Remember the time taken to sort that array.
// Try different array sizes to sort.
// Observe the time taken as a function of array size (maybe using a graph).

#include <iostream>
#include <ctime>
using namespace std;

void merge(int A[], int L[], int Lsize, int R[], int Rsize) {
    int size = Lsize+Rsize;
    int i = 0;
    int j = 0;
    for (int k=0; k < size; k++) {
        if ((j==Rsize) or (i<Lsize and L[i]<R[j])) {
           A[k] = L[i]; i++;
        } else {
           A[k] = R[j]; j++;
        }
    }
}

void mergesort(int A[], int work[], int size) {
    if (size <= 1) return;
    int mid = size/2;
    // make a copy of A into temporary work
    for (int i=0; i<size; i++) work[i]=A[i];
    mergesort(work,A,mid); // sort left of work using A as temp
    mergesort(&work[mid],&A[mid],size-mid); // sort right of work using A as temp
    merge(A,work,mid,&work[mid],size-mid); // merge sorted both work back into A
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
    int *workarray = new int[length]; // create the working array
    cout << "Sorting " << length << " items" << endl;
    timespec start;
    timespec_get(&start, TIME_UTC);
    mergesort(myarray,workarray,length);
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
}
