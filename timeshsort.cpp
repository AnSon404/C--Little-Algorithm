// This is the Shell sort program.
// Remember the time taken to sort that array.
// Try different array sizes to sort.
// Observe the time taken as a function of array size (maybe using a graph).

#include <iostream>
#include <ctime>
using namespace std;

void shell(int arr [], int n) {
    int gapSeq[] = {701, 301, 132, 57, 23, 10, 4, 1}; // Ciura gap sequence
    int gap, temp, g, i, j;

    for (g = 0; g < sizeof(gapSeq)/sizeof(int); g++) { // for each gap value
    // gapped insertion sort in multiple passes
        gap = gapSeq[g];
        for (i = gap; i < n; i++) {
	    temp = arr[i];
	    // shift up for insertion
            for (j = i; (j >= gap) && (arr[j-gap] > temp); j -= gap)
                arr[j] = arr[j-gap];
            arr[j] = temp;
        }
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
    cout << "Sorting " << length << " items" << endl;
    timespec start;
    timespec_get(&start, TIME_UTC);
    // call C++ library for quicksort (called qsort)
    shell(myarray,length);
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
