/*

Given an integer matrix 'mat' of dimensions m x n, write a program that prints
the matrix in wave form.

Example :
	Input : mat[][] = [[1, 2, 3],
					   [4, 5, 6],
					   [7, 8, 9]]

	Output : 1 4 7 8 5 2 3 6 9

*/

#include<iostream>

using namespace std;

int main() {
	
	#ifndef IO
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int m, n;
	cin >> m >> n;

	int mat[10][10];
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> mat[i][j];
		}
	}

	// // print the matrix column-wise
	// for(int j=0; j<n; j++) {
	// 	for(int i=0; i<m; i++) {
	// 		cout << mat[i][j] << " ";
	// 	}
	// }
	
	// print the matrix wave column-wise
	for(int j=0; j<n; j++) {
		if(j%2 == 0) {
			// print from top to bottom
			for(int i=0; i<m; i++) {
				cout << mat[i][j] << " ";
			}
		} else {
			// print from bottom to top
			for(int i=m-1; i>=0; i--) {
				cout << mat[i][j] << " ";
			}
		}
		
	}
	
	return 0;
}