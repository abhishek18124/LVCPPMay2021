/*

Write a function to compute the array sum.

Example:
	Input : A[] = {1, 2, 3, 4, 5}
	Output: 15

*/

#include<iostream>

using namespace std;

void sumOfArray(int B[], int n) {
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += B[i];
	}
	cout << sum << endl;
	B[0] = 100;

}

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A)/sizeof(int);

	sumOfArray(A, n); // function call

	cout << A[0] << endl;

	return 0;
}