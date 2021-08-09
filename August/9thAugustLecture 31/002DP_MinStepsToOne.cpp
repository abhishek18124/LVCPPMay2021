/*

Given a number n, count the minimum steps to reduce n to 1 such that at each step you may

	reduce n to n/2 if n is divisible by 2
	or reduce n to n/3 if n is divisible by 3
	or reduce n to n-1 by decrementing n by 1

Example :
	Input : n = 10
	Output : 3

	Input : 6
	Output : 2

*/

#include<iostream>
#include<climits>

using namespace std;

int minStepsToOne(int n) {
	// base case 
	if(n == 1) return 0;

	int op1 = INT_MAX;
	if(n%2 == 0) {
		op1 = minStepsToOne(n/2);
	}

	int op2 = INT_MAX;
	if(n%3 == 0) {
		op2 = minStepsToOne(n/3);
	}

	int op3 = minStepsToOne(n-1);

	return 1 + min({op1, op2, op3}); 
}


int minStepsToOneTopDown(int n, int* dp) {
	// base case 
	if(n == 1) return 0;

	// lookup
	if(dp[n] != -1) {
		// you've already solved the sub-problem previously
		return dp[n];
	}

	// you're encountering this sub-problem for the first time

	int op1 = INT_MAX;
	if(n%2 == 0) {
		op1 = minStepsToOneTopDown(n/2, dp);
	}

	int op2 = INT_MAX;
	if(n%3 == 0) {
		op2 = minStepsToOneTopDown(n/3, dp);
	}

	int op3 = minStepsToOneTopDown(n-1, dp);

	return dp[n] = 1 + min({op1, op2, op3}); 
}

int minStepsToOneBottomUp(int n) {
	int* dp = new int[n+1];
	for(int i=0; i<=n; i++) {
		dp[i] = -1;
	}

	dp[1] = 0;

	for(int i=2; i<=n; i++) {
		int op1 = INT_MAX;
		if(i%2 == 0) {
			op1 = dp[i/2];
		}

		int op2 = INT_MAX;
		if(i%3 == 0) {
			op2 = dp[i/3];
		}

		int op3 = dp[i-1];

		dp[i] = 1 + min({op1, op2, op3});
	}

	return dp[n];
}

int main() {

	int n = 10;
	cout << minStepsToOne(n) << endl;

	int* dp = new int[n+1];
	for(int i=0; i<=n; i++) {
		dp[i] = -1;
	}

	cout << minStepsToOneTopDown(n, dp) << endl;
	cout << minStepsToOneBottomUp(n) << endl;

	return 0;
}