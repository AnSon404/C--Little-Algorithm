// C++ program to implement radix sort
#include <iostream>
#include <ctime>
using namespace std;

void count_sort(int arr[], int n, int pos, int working[])
{
    // declare count array and initialize it by 0
    int count[10] = { 0 };

    // count frequency of each digit at pos for element in original array
    for (int i = 0; i < n; i++)
        count[(arr[i] / pos) % 10]++;
    // generate prefix sum to avoid need of linked list
    for (int i = 1; i < 10; i++)
        count[i] = count[i] + count[i - 1];
    // store working results - expensive storage for radix sort
    for (int i = n-1; i >= 0; i--)
        working[--count[(arr[i] / pos) % 10]] = arr[i];
    // copy working results back to original array
    for (int i = 0; i < n; i++)
        arr[i] = working[i];
}

void radix_sort(int arr[], int n)
{
    // find max item for number of digits (at most 999999 here)
    int max = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > max) max = arr[i];
    int *working = new int[n]; // create the array
    // pos starts from 1 to 10 to 100 till max
    for (int pos = 1; (max / pos) > 0; pos *= 10)
        count_sort(arr,n,pos,working);
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
    radix_sort(myarray,length);
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
