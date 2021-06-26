/*

Given an array A of size n, and number t, write a recursive algorithm to find the index of 
	a) first occurrence of t in A
	b) last  occurrence of t in A
	c) all occurrences of t in A

If t is not present in the array return -1

Example 
	Input  : A[] = {1, 2, 3, 2, 4, 2, 5} ; t = 2
	Output : a) first occurrence = 1 
	         b) last  occurrence = 5 
	         c) all  occurrences = 1, 3, 5

*/

#include<iostream>

using namespace std;

int firstOcc(int A[], int n, int t) {
	if(n == 0) {
		return -1;
	}

	if(A[0] == t) {
		return 0;
	}

	int i = firstOcc(A+1, n-1, t);
	return i + 1;
}

int lastOcc(int A[], int n, int t) {
	if(n == 0) {
		return -1;
	}
	
	int i = lastOcc(A+1, n-1, t);
	if(i == -1) {
		if(A[0] == t) {
			return 0;
		} else {
			return -1;
		}
	}

	return i + 1;
}

int firstOccV2(int A[], int n, int t, int i) {
	if(i == n) {
		// t is not present in A[] since you have 
		// scanned all indices from 0 to n-1
		return -1;
	}

	if(A[i] == t) {
		return i;
	}

	return firstOccV2(A, n, t, i+1);

}

void allOcc(int A[], int n, int t, int i) {
	if(i == n) {
		// t is not present in A[] since you have 
		// scanned all indices from 0 to n-1
		return;
	}

	if(A[i] == t) {
		cout << i << " ";
	}

	allOcc(A, n, t, i+1);

}

int lastOccV2(int A[], int n, int t, int i) {
	if(i < 0) {
		// t is not present in A[] since you have 
		// scanned all indices from n-1 to 0
		return -1;
	}

	if(A[i] == t) {
		return i;
	}

	return lastOccV2(A, n, t, i-1);

}



int main() {

	int A[] = {1, 3, 3, 4};
	int n = sizeof(A)/sizeof(int);
	int t = 3;
	// cout << firstOcc(A, n, t) << endl;
	// cout << lastOcc(A, n, t) << endl;
	
	cout << firstOccV2(A, n, t, 0) << endl;
	cout << lastOccV2(A, n, t, n-1) << endl;

	allOcc(A, n, t, 0);
	

	return 0;
}