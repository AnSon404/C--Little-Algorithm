#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array according 
// to pivot index element
void partition(vector<int> &arr) {
  	int n = arr.size();
  	int pivot = arr[0];
  	int x = 0;
  	
  	int i = -1, j = n;
  	while (true) {
      
      	// find next element larger than pivot 
      	// from the left
      	do {
          	i++;
        } while (arr[i] < pivot);
      	
      	// find next element smaller than pivot 
      	// from the right
      	do {
          	j--;
        } while (arr[j] > pivot);
      	
      	// if left and right crosses each other
      	// no swapping required
      	if (i >= j) break;
      	
      	// swap larger and smaller elements
      	x++;
      	cout << "swap " << arr[i] << " with " << arr[j] << endl;
      	swap(arr[i], arr[j]);
      	
    }
    cout << "Swap time(s): " << x << endl;
}

int main() {
    vector<int> arr = {21, 19};
    
    for (int i = 0; i < arr.size(); i++) 
      	cout << arr[i] << " "; 
  	cout << endl;
  	
  	partition(arr);
  	
  	for (int i = 0; i < arr.size(); i++) 
      	cout << arr[i] << " "; 
    return 0;
}
