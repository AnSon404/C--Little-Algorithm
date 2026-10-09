#include <iostream>
#include <vector>
using namespace std;

void partition(vector<int> &arr) {
  	int n = arr.size();
  	int pivot = arr[n - 1];
  	int x = 0;
  	
  	// i acts as boundary between smaller and 
  	// larger element compared to pivot
  	int i = -1;
  	for (int j = 0; j < n; j++) {
      
      	// If smaller element is found expand the 
      	// boundary and swapping it with boundary element.
      	if (arr[j] < pivot) {
      	    x++;
          	i++;
          	cout << "swap " << arr[i] << " with " << arr[j] << endl;
          	swap(arr[i], arr[j]);
        }
    }
  	
  	// place the pivot at its correct position
  	x++;
    cout << "swap at last, swap " << arr[i + 1] << " with " << arr[n - 1] << endl;
  	swap(arr[i + 1], arr[n - 1]);
    cout << "Swap time(s): " << x << endl;
}

int main() {
    vector<int> arr = {58, 61};
    
    for (int i = 0; i < arr.size(); i++) 
      	cout << arr[i] << " "; 
    cout << endl;
    
  	partition(arr);
  	
  	for (int i = 0; i < arr.size(); i++) 
      	cout << arr[i] << " "; 
    return 0;
}
