/*

Recursive version of the Bubble Sort Algorithm

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


void bubbleSort(int A[], int n) {
	
	// // here you will do one extra pass which is not required
	// if(n == 0) {
	// 	return;
	// }

	if(n == 1) {
		return;
	}
	
	// do one pass yourself
	pushLargest(A, n, 0);

	// recursively do the remaining passes
	bubbleSort(A, n-1);

}

void bubbleSortV2(int A[], int n, int i) {
	
	if(i == n-1) {
		// pass number = i+1
		return;
	}

	// do one pass yourself
	pushLargest(A, n, 0);

	// recursively do the remaining passes
	bubbleSortV2(A, n, i+1);

}

int main() {

	int A[] = {5, 4, 3, 2, 1};
	int n = sizeof(A) / sizeof(int);

	bubbleSortV2(A, n, 0);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;
	return 0;
}