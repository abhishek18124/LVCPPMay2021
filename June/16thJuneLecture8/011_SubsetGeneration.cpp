/*

Given an array A, generate all the subsets/subsequences of A.

Example:
	Input : A[] = {1, 2, 3}
	Output: {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}}
*/

#include<iostream>

using namespace std;

void generateSubset(int no, int A[]) {
	int bitPos = 0;
	while(no > 0) {
		int lastBit = no&1;
		if(lastBit == 1) {
			// include the element A[bitPos] in my subset
			cout << A[bitPos] << " ";
		}
		bitPos++;
		no >>= 1;
	}
	cout << endl;
}

void generateAllSubsets(int A[], int n) {
	for(int no=0; no < 1<<n; no++) {
		generateSubset(no, A);
	}
	cout << endl;

}

int main() {

	int A[] = {1, 2, 3};
	int n = sizeof(A) / sizeof(int);

	generateAllSubsets(A, n);

	return 0;
}