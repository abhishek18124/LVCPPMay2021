/*

Given a m x n chess board, count the number of ways a chess elephant can move from (0, 0)
to (m-1, n-1) such that it can only move in either the right or down direction at a time.

Example 
	Input : m = 2, n = 2
	Output: 2
	
	Input : m = 3, n = 3
	Output: 14
	
	Input : m = 4, n = 4
	Output: 106

*/

#include<iostream>

using namespace std;

int chessElephants(int m, int n, int i, int j) {
	if(i == m-1 && j == n-1) {
		return 1;
	}

	// if(i > m || j > n) {
	// 	return 0;
	// }
	
	int count = 0;
	for(int k=1; k<n; k++) {
		if(j+k < n) {
			count += chessElephants(m, n, i, j+k);
		}
	}

	for(int k=1; k<m; k++) {
		if(i+k < m) {
			count += chessElephants(m, n, i+k, j);
		}
	}	

	return count;


}

int main() {

	cout << chessElephants(4, 4, 0, 0) << endl;
	return 0;
}