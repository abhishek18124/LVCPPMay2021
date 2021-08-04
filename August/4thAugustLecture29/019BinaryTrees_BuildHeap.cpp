/*

Given an array of n integers, design a O(n) algorirthm to build a max heap.

*/

#include<iostream>

using namespace std;

int main() {
	
	int arr[] = {-1, 5, 4, 0, 1, 2, 3}; // 0th index is reserved
	int n = sizeof(arr) / sizeof(int);

	for(int i=n/2; i>=1; i--) {
		heapify(arr, n, i); // do it yourself
	}

	return 0;
}