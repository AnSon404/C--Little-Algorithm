// This is the quick sort program with clever but expensive pivot.
// Remember the time taken to sort that array.
// Try different array sizes to sort.
// Observe the time taken as a function of array size (maybe using a graph).

#include <iostream>
#include <ctime>
using namespace std;

// insertion sort
void isort(int A[], int n) {
    for (int i=1; i<n; i++) {
        int j = i;
	while (j > 0 and A[j-1]>A[j]) {
	   int temp = A[j];
	   A[j] = A[j-1];
	   A[j-1] = temp;
	   j--;
	}
    }
}

// forward declaration for mutual recursion
int partition(int A[], int left, int right, int pivot);

// return kth smallest element
int findp(int A[], int left, int right, int k) {
    if (right-left < 5) {
        isort(&A[left],right-left+1);
        return A[left+k];
    }
    // move median of each group of size 5 to the front
    int nomedian = 0;
    for (int i = left; i <= right; i += 5) {
        int aright = min(i+4,right);
        isort(&A[i],aright-i+1);
        int mid = i+(aright-i)/2;
        int temp = A[left+nomedian];
        A[left+nomedian] = A[mid];
	A[mid] = temp;
        nomedian++;
    }
    int pivot = findp(A,left,left+nomedian-1,nomedian/2);
    int pivotloc = partition(A,left,right,pivot);
    int mloc = pivotloc-left;
    if (k == mloc) return A[pivotloc];
    else if (k < mloc) return findp(A,left,pivotloc-1,k);
    else return findp(A,pivotloc+1,right,k-mloc-1);
}

int partition(int A[], int left, int right, int pivot) {
    // find location of pivot and swap it to right to align with Lomuto
    for (int i=left; i<=right-1; i++)
        if (A[i] == pivot) {
	   A[i] = A[right];
	   A[right] = pivot;
	   break;
	}
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
       int pivot = findp(A,left,right,(right-left)/2);
       int p = partition(A,left,right,pivot);
       quicksort(A,left,p-1);
       quicksort(A,p+1,right);
    }
}

// verify that it is indeed sorted
int verify(int A[], int n) {
    for (int i = 1; i < n; i++)
        if (A[i-1] > A[i]) return 0;
    return 1;
}

int main(int argc, char *argv[]) {
    int length;

    cout << "Input number of items" << endl;
    cin >> length;

    int *myarray = new int[length]; // create the array
    // generate many 6 digit numbers in the array
    for (int i = 0; i < length; i++) myarray[i] = rand() % 1000000;

    // disable output
    //cout << "Input array" << endl;
    //for (i = 0; i < length; i++) cout << myarray[i] << " ";
    //cout << endl;

    // test for worst case, sort the input as the new input
    quicksort(myarray,0,length-1);
    if (verify(myarray,length)) printf("Input array is sorted\n");

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
    //cout << "Sorted array" << endl;
    //for (i = 0; i < length; i++) cout << myarray[i] << " ";
    //cout << endl;
    if (verify(myarray,length)) printf("Indeed sorted\n");
}
