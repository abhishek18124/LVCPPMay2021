/*

Given an array of n integers, design a recursive algorithm to push the largest
element in the array to the end of the array like the bubble sort algorithm in
its each pass.

Example :
	Input : A[] = {5, 4, 3, 2, 1}
	Output: A[] = {4, 3, 2, 1, 5}

*/

#include<iostream>

using namespace std;

void pushLargest(int A[], int n, int j) {

	if(j == n-1) {
		// push the largest element from A[n-1...n-1] to the last index
		// and because it contains only one element, it is already
		// at the last index
		return;
	}

	if(A[j] > A[j+1]) {
		swap(A[j], A[j+1]);
	}

	pushLargest(A, n, j+1);
}

int main() {

	int A[] = {1, 2, 5, 4, 3};
	int n = sizeof(A) / sizeof(int);

	pushLargest(A, n, 0);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	return 0;
}
