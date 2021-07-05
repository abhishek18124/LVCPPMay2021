/*

Given a m x n grid, count the number of ways a person can move from (0, 0)to (m-1, n-1) such that 
it can only move a single step either in the right or down direction at a time.

Example 
	Input : m = 2, n = 2
	Output: 2
	
	Input : m = 3, n = 3
	Output: 6
	
	Input : m = 4, n = 4
	Output: 20

*/


#include<iostream>

using namespace std;

int countWays(int m, int n, int i, int j) {

	if(i == m-1 and j == n-1) {
		return 1;
	}

	if(i == m || j == n) {
		return 0;
	}

	// I am standing at the i, jth cell and I have to make a decision

	// go right
	int x1 = countWays(m, n, i, j+1);

	// go down
	int x2 = countWays(m, n, i+1, j);

	return x1 + x2;
}

int main() {
	
	cout << countWays(3, 4, 0, 0) << endl;
	return 0;
}
