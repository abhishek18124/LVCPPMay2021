/*

Merge Sort Algorithm

	Step 1 : Divide the input array into two subarrays of roughly equal size.
	Step 2 : Recursively mergesort each of the subarrays.
	Step 3 : Merge the newly-sorted subarrays into a single sorted array.

*/

#include<iostream>

using namespace std;

void merge(int A[], int s, int m, int e) {
	int i = s;
	int j = m+1;
	int k = s;

	int B[100];

	while(i <= m  && j <= e) {
		if(A[i] < A[j]) {
			B[k++] = A[i++];
		} else {
			B[k++] = A[j++];
		}
	}

	while(i <= m) {
		// you have exhaused j
		B[k++] = A[i++];
	}

	while(j <= e) {
		// you have exhausted i
		B[k++] = A[j++];
	}

	// copy content from temporary array B back to A
	for(int k=s; k<=e; k++) {
		A[k] = B[k];
	}

}

void mergeSort(int A[], int s, int e) {
	if(s >= e) {
		return;
	}
	
	int m = s + (e-s)/2; // (s+e)/2
	mergeSort(A, s, m);
	mergeSort(A, m+1, e);
	merge(A, s, m, e);
}

int main() {

	int A[] = {5, 4, 3, 2, 1};
	int n = sizeof(A) / sizeof(int);

	mergeSort(A, 0, n-1);

	for(int i=0; i<n; i++) {
		cout << A[i] << " "; 
	}	

	cout << endl;
	
	return 0;
}

