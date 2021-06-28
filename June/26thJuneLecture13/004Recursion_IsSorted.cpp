/*

Given an array of size n, write a recursive algorithm to check if the array is sorted.

Example 
	Input  : A[] = {1, 2, 3, 4, 5}
	Output : true

	Input  : A[] = {3, 0, 7, 9}
	Output : false

*/

#include<iostream>

using namespace std;

bool isSorted(int A[], int n) {
	if(n == 0 || n == 1) return true; // you'll never reach n==0 
	return A[0] < A[1] && isSorted(A+1, n-1);
}

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);

	cout << isSorted(A, n) << endl;

	return 0;
}