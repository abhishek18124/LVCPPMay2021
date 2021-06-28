/*

Given an array of size n, write a recursive algorithm to compute the sum of array
elements.

Example 
	Input  : A[] = {1, 2, 3, 4, 5}
	Output : 15

	Input  : A[] = {3, 5, 7, 9}
	Output : 24

*/

#include<iostream>

using namespace std;

int arraySumV2(int A[], int n) {
	// if(n  == 1) {
	// 	return A[0]; 
	// }

	if(n  == 0) {
		return 0; 
	}

	return A[0] + arraySumV2(A+1, n-1);
}

int arraySumV1(int A[], int n) {
	if(n  == 1) {
		return A[0]; 
	}

	int S1 = arraySumV1(A, n/2);
	int S2 = arraySumV1(A+n/2, n-n/2);

	return S1 + S2;
}

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);

	cout << arraySumV1(A, n) << endl;
	cout << arraySumV2(A, n) << endl;

	return 0;
}