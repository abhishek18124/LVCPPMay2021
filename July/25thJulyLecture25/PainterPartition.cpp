/*

https://hack.codingblocks.com/app/contests/2340/1057/problem

*/

#include<iostream>

using namespace std;

int numPaintersRequired(int n, int* len, int timeLimit) {
	int numPainters = 1;
	int time = 0;
	for(int i=0; i<n; i++) {
		// paint the ith board
		time += len[i];
		if(time > timeLimit) {
			// add another painter to the job
			numPainters++;
			// this painter restart painting the ith board
			time = len[i];
		}
	}
	return numPainters;
}

int getMinTime(int k, int n, int* len) {
	int sum = 0;
	int maxLen = 0;
	for(int i=0; i<n; i++) {
		sum += len[i];
		maxLen = max(maxLen, len[i]);
	}
	int s = maxLen;
	int e = sum;
	int ans = e;

	while(s <= e) {
		int m = s + (e-s) / 2;
		// can k painters paint n boards in m amt. of time ?
		if(numPaintersRequired(n, len, m) <= k) {
			// k painters can also paint n boards in m amt. time
			// [s, e] -> [s, m-1]
			ans = m;
			e = m-1;

		} else {
			// k painters cannot paint n boards in m amt. time
			// [s, e] -> [m+1, e]
			s = m+1;
		}
	}

	return ans;
}

int main() {

	int k;
	cin >> k;

	int n;
	cin >> n;

	int* len = new int[n];
	for(int i=0; i<n; i++) {
		cin >> len[i];
	}

	cout << getMinTime(k, n, len) << endl;

	return 0;
}