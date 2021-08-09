/*

Given a number n, find the nth fibonacci no.

Example :
	Input : n = 7
	Output : 13

*/

#include<iostream>

using namespace std;

int fibo(int n) {
	// base case
	if(n == 0 || n == 1) return n;

	// recursive case
	return fibo(n-1) + fibo(n-2);
}

int fiboTopDown(int n, int* dp) {
	// base case
	if(n == 0 || n == 1) return dp[n] = n;

	// Lookup
	if(dp[n] != -1) {
		// you've already solved f(n), so reuse the previous result
		return dp[n];
	}

	// you've not yet solved f(n)
	return dp[n] = fiboTopDown(n-1, dp) + fiboTopDown(n-2, dp);

}

int fiboBottomUp(int n) {

	if(n == 0 || n == 1) return n;

	int* dp = new int[n+1];
	for(int i=0; i<=n; i++) {
		dp[i] = -1;
	}


	dp[0] = 0;
	dp[1] = 1;

	for(int i=2; i<=n; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int fiboBottomUpSpaceOptimised(int n) {

	if(n == 0 || n == 1) return n;

	int a = 0;
	int b = 1;
	int c;

	for(int i=2; i<=n; i++) {
		c = b + a;
		a = b;
		b = c;
	}

	return c;
}

int main() {

	int n = 7;

	cout << fibo(n) << endl;

	int* dp = new int[n+1];
	for(int i=0; i<=n; i++) {
		dp[i] = -1;
	}

	cout << fiboTopDown(n, dp) << endl;
	cout << fiboBottomUp(n) << endl;
	cout << fiboBottomUpSpaceOptimised(n) << endl;

	return 0;
}