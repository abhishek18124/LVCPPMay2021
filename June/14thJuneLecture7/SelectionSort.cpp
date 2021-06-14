/*

Write a program to sort an array using the selection sort algorithm.

	Example :

	Input : A[] = {-1, 0, -2, 1, 3, 2}
	Output: A[] = {-2, -1, 0, 1, 2, 3}

*/

#include<iostream>

using namespace std;

int main() {

	int A[] = {4, 3, 1, 2};
	int n = sizeof(A) / sizeof(int);

	for(int i=0; i<n-1; i++) {
		int min_idx = i;
		for(int j=i; j<n; j++) {
			if(A[j] < A[min_idx]) {
				min_idx = j;
			}
		}
		swap(A[i], A[min_idx]);
	}

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;


	return 0;
}