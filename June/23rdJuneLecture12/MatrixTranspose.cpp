/*

Given an integer matrix 'mat' of dimensions m x n, write a program that prints
the transpose of the matrix.

Example :
	Input : mat[][] = [[1,  2,  3,  4],
					   [5,  6,  7,  8],
					   [9,  10, 11, 12],
					   [13, 14, 15, 16]]

	Output: mat[][] = [[1, 5, 9,  13],
					   [2, 6, 10, 14],
					   [3, 7, 11, 15],
					   [4, 8, 12, 16]]

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

	cout << "matrix before transpose = " << endl;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			// if(i < j) {
			// 	swap(mat[i][j], mat[j][i]);
			// }
			if(j > i) {
				swap(mat[i][j], mat[j][i]);
			}
		}
	}

	cout << "matrix after transpose = " << endl;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}