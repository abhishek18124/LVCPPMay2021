/*

Given an array, write a program to find the maximum sub-array sum. 

Example :
	
	Input : A[] = {-3, 4, -2, 1, 5, -3}
	Output: 8

*/

#include<iostream>
#include<climits>

using namespace std;

int main() {

	int A[] = {-3, 4, -2, 1, 5, -3};
	int n = sizeof(A) / sizeof(int);

	int maxSum = INT_MIN;
	int startIndex = -1;
	int endIndex = -1;

	// iterate over all the starting indices of a subarray
	for(int i=0; i<n; i++) {
		// iterate over all the ending indices of a subarray
		int sum = 0;
		for(int j=i; j<n; j++) {
			// calculate the sum for subarray starting at 
			// the ith index and ending at the jth index
			sum += A[j];

			// sum will contain the sum of subarray starting
			// at the ith index and ending at the jth index
			if(sum > maxSum) {
				maxSum = sum;
				startIndex = i;
				endIndex = j;
			}

		}
	}

	for(int i=startIndex; i<=endIndex; i++) {
		cout << A[i] << " ";
	}

	cout << endl;
	
	cout << maxSum << endl;

	return 0;
}