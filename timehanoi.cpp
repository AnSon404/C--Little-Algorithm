// This is the Tower of Hanoi program.
// Remember the time taken to move different number of disks
// Observe the time taken as a function of number of disks (maybe using a graph).

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// function for n disks, move from src to dest via temp
void hanoi(int n, string src, string dest, string temp) {
  if (n == 1) // base case
     // disable output
     // cout << "Move disk from " << src << " to " << dest << endl;
     int work = 0; // do some dummy work
  else { // recursive case
     hanoi(n-1,src,temp,dest); // move n-1 from source to temp
     // disable output
     // cout << "Move disk from " << src << " to " << dest << endl; // bottom
     int work = 0; // do some dummy work
     hanoi(n-1,temp,dest,src); // move n-1 from temp to dest
  }
}

int main(int argc, char *argv[]) {
    int ndisk;

    cout << "Input number of disks" << endl;
    cin >> ndisk;
    cout << "Solution for " << ndisk << " disks" << endl;
    timespec start;
    timespec_get(&start, TIME_UTC);
    hanoi(ndisk,"left","right","middle");
    timespec end;
    timespec_get(&end, TIME_UTC);
    int sec = end.tv_sec - start.tv_sec;
    int nsec = end.tv_nsec - start.tv_nsec;
    if (nsec < 0) { nsec = nsec+1000000000; sec--; }
    printf("Time to solve %d disks is %d.%09d seconds\n",ndisk,sec,nsec);
}
