/*

pointers and arrays
passing an array to a function.
pointer arithmetic -> subtracting two pointers

*/

#include<iostream>

using namespace std;

void computeArraySum(int* A, int n) {
	cout << "sizeof(A) = " << sizeof(A) << "B" << endl;

	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += A[i]; // *(A+i) = A[i]
	}
	cout << sum << endl;
}

int main() {

	int A[] = {1, 2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int); 

	cout << "sizeof(A) = " << sizeof(A) << "B" << endl;

	// computeArraySum(A, n);
	// computeArraySum(&A[0], n); // same as above

	// int* aptr = A;
	int* aptr = &A[0];
	computeArraySum(aptr, n);

	return 0;
}