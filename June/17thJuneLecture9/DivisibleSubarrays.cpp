/*

You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.

A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) 
is divisible by N.

Example : 
	Input : A[] = {1, 3, 2, 6, 4}
	Output: 3

	Input : A[] = {1, 1, 1, 1, 1}
	Output: 1

	Input : A[] = {5, 5, 5, 5, 5}
	Output: 5

Constraints :

	1<=n<=10^3

*/

#include<iostream>

using namespace std;

int countGoodSubarrays(int A[], int n) {
	// create a cumulative sum array
	
	int csum[1001];
	csum[0] = 0;
	for(int i=1; i<=n; i++) {
		csum[i] = csum[i-1] + A[i-1];
	}

	for(int i=0; i<=n; i++) {
		cout << csum[i] << " ";
	}

	cout << endl;
	
	int csum_mod_n[1001];
	for(int i=0; i<=n; i++) {
		csum_mod_n[i] = (csum[i]+n)%n;	
	}

	for(int i=0; i<=n; i++) {
		cout << csum_mod_n[i] << " ";
	}

	cout << endl;

	// int freq[1000]={0};
	int freq[1000];
	memset(freq, 0, sizeof(freq));

	// for(int i=0; i<n; i++) {
	// 	freq[i] = 0;
	// }

	for(int i=0; i<=n; i++) {
		freq[csum_mod_n[i]]++;
	}

	for(int i=0; i<n; i++) {
		cout << freq[i] << " ";
	}

	cout << endl;

	int count = 0;
	for(int i=0; i<n; i++) {
		int x = freq[i];
		if(x > 1) {
			// count = count + ((x * (x-1)) / 2);
			count += x * (x-1) / 2;
		}
	}

	return count;

}


int main() {

	int A[] = {1, 2, 3, 6, 4};
	int n = sizeof(A) / sizeof(int);

	cout << countGoodSubarrays(A, n) << endl;

	return 0;
}
