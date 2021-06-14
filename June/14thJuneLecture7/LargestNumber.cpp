/*

Write a program to find the maximum number in an array.

Example :

	Input : A[] = {-2, 0, 1, 7, 3, 2}
	Output: 7

*/

#include<iostream>
#include<climits>

using namespace std;

int main() {

	int A[] = {-2, 0, 1, 7, 3, 2};
	int n = sizeof(A) / sizeof(int);

	int maxValue = INT_MIN; // -2^31 or negative inf.
	int minValue = INT_MAX; // 2^31 - 1  or positive inf.
	for(int i=0; i<n; i++) {
		if(A[i] > maxValue) {
			maxValue = A[i];
		}

		if(A[i] < minValue) {
			minValue = A[i];
		}
	}

	cout << maxValue << endl;
	cout << minValue << endl;

	return 0;
}