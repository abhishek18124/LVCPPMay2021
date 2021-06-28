/*

Binary Search Algorithm 

Return -1 if the key is not present in the array.

*/

#include<iostream>

using namespace std;

// int ans = -1;

int binarySearch(int A[], int s, int e, int k) {
	
	if(s > e) {
		// search space has become empty
		return -1;
		// return;
	}

	// int m = (s+e) / 2; // it can lead to integer overflow when s and e are very large
	int m = s + (e-s) / 2;
	if(A[m] == k) {
		return m;
		// ans = m;
		// cout << "found " << k << " at " << ans << endl;
		// binarySearch(A, s, m-1, k);
		// binarySearch(A, m+1, e, k);
	} else if(A[m] > k) {
		// search space reduces from [s, e] to [s, m-1]
		return binarySearch(A, s, m-1, k);
	} else {
		// search space reduces from [s, e] to [m+1, e]
		return binarySearch(A, m+1, e, k);
	}
} 

int main() {

	int A[] = {1, 3, 3, 3, 4};
	int n = sizeof(A) / sizeof(int);
	int k = 3;
	
	cout << binarySearch(A, 0, n-1, k) << endl;

	// cout << ans << endl;

	return 0;
}