/*

Given an array of n integers, design a O(n) algorirthm to build a min heap.

*/

#include<iostream>

using namespace std;

void heapify(int* arr, int n, int i) {
	
	int m = i;
	int l = 2*i;
	int r = 2*i + 1;

	// uncomment lines [19-21] and comment lines [23-25] for max heap

	// if(l < n && arr[l] > arr[m]) { 
	// 	m = l;
	// }

	if(l < n && arr[l] < arr[m]) { 
		m = l;
	}

	// uncomment lines [29-31] and comment lines [33-35] for max heap

	// if(r < n && arr[r] > arr[m]) {
	// 	m = r;
	// }
 	
	if(r < n && arr[r] < arr[m]) {
		m = r;
	}
 	
 	// m == i serves as the base case, so we do not need to provide an explicit base case
	if(m != i) { 
		swap(arr[i], arr[m]);
		heapify(arr, n, m);
	}

}

int main() {
	
	int arr[] = {-1, 5, 7, 4, 0, 6, 1, 2, 3}; // don't forget, 0th index is reserved
	int n = sizeof(arr) / sizeof(int);

	for(int i=n/2; i>=1; i--) { // 1st non-left node is present at the (n/2)th index
		heapify(arr, n, i);
	}

	for(int i=1; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}