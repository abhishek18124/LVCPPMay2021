/*

Write a program to print an array in reverse.

Example :

	Input : A[] = {1, 2, 3, 4, 5}
	Output: A[] = {5, 4, 3, 2, 1}

*/

#include<iostream>

using namespace std;

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);

	for(int i=n-1; i>=0; i--) {
		cout << A[i] << " ";
	}

	return 0;
}