/*

Given an integer matrix 'mat' of dimensions m x n, write a function that prints
the matrix in spiral form.

Example :
	Input : mat[][] = [[1,  2,  3,  4],
					   [5,  6,  7,  8],
					   [9,  10, 11, 12],
					   [13, 14, 15, 16]]

	Output : 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

	Input : mat[][] = [[1,  2,  3,  4],
					   [5,  6,  7,  8],
					   [9,  10, 11, 12]]

	Output : 1 2 3 4 8 12 11 10 9 5 6 7

*/

#include<iostream>

using namespace std;

int main() {
	
	// int mat[10][10] = {{1,  2,  3,  4},
	// 				   {5,  6,  7,  8},
	// 				   {9,  10, 11, 12},
	// 				   {13, 14, 15, 16}};


	// int sr = 0;
	// int sc = 0;
	// int er = 3;
	// int ec = 3;

	int mat[10][10] = {{1,  2,  3,  4},
					   {5,  6,  7,  8},
					   {9,  10, 11, 12}};


	int sr = 0;
	int sc = 0;
	int er = 2;
	int ec = 3;

	while(sr <= er && sc <= ec) {
		// print sr from sc to ec
		for(int col=sc; col<=ec; col++) {
			cout << mat[sr][col] << " ";
		}
		sr++;
		// cout << endl << sr << " " << er << " " << sc << " " << ec << endl << endl;

		// print ec from sr to er
		for(int row=sr; row<=er; row++) {
			cout << mat[row][ec] << " ";
		}
		ec--;
		// cout << endl << sr << " " << er << " " << sc << " " << ec << endl<< endl;

		// print er from ec to sc
		if(!(sr > er)) {
			for(int col=ec; col>=sc; col--) {
				cout << mat[er][col] << " ";
			}
			er--;
		}
		// cout << endl << sr << " " << er << " " << sc << " " << ec << endl<< endl;
		
		// print sc from er to sr
		if(!(sc > ec)) {
			for(int row=er; row>=sr; row--) {
				cout << mat[row][sc] << " ";
			}
			sc++;
		}
		// cout << endl << sr << " " << er << " " << sc << " " << ec << endl<< endl;
	}

	return 0;
}