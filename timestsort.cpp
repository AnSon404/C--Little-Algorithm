// This is the Stooge sort program.
// Remember the time taken to sort that array.
// Try different array sizes to sort.
// Observe the time taken as a function of array size (maybe using a graph).

#include <iostream>
#include <ctime>
using namespace std;

void stooge(int arr[], int low, int high) {
    if (arr[low] > arr[high]) { // swap them
       int temp = arr[low];
       arr[low] = arr[high];
       arr[high] = temp;
    }
    if (high-low+1 >= 3) { // at least 3 items
       int oneThird = (high-low+1)/3;
       stooge(arr,low,high-oneThird); // sort first 2/3 of array
       stooge(arr,low+oneThird,high); // sort last 2/3 of array
       stooge(arr,low,high-oneThird); // sort first 2/3 of array again
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
    stooge(myarray,0,length-1);
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
