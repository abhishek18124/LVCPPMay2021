/*

Given an integer matrix 'mat' of dimensions m x n and an integer 't', write a program 
to search for 't' in 'mat'. 

If 't' is present in the matrix print its coordinates otherwise print (-1, -1).

Example :
	Input : mat[][] = [[1,  2,  3,  4],
					   [5,  6,  7,  8],
					   [9,  10, 11, 12],
					   [13, 14, 15, 16]]

			t = 10

	Output: (2, 1)

*/

#include<iostream>

using namespace std;

pair<int, int> matrixSearch(int mat[][10], int m, int n, int t) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(mat[i][j] == t) {
				return {i, j}; // or make_pair(i, j)
			}
		}
	}
	return make_pair(-1, -1); // or {-1, -1}
}

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

	int t;
	cin >> t;

	// int i;
	// // bool flag = false; // t is not yet found
	// for(i=0; i<m; i++) {
	// 	int j;
	// 	for(j=0; j<n; j++) {
	// 		if(mat[i][j] == t) {
	// 			// I have found t at the index (i, j)
	// 			cout << "t is found at (" << i << ", " << j << ")" << endl;
	// 			// flag = true; // t is found
	// 			break;
	// 		}
 //  		}
 //  		if(j < n) {
 //  			// I found t at some  index and I breaked from inner loop
 //  			break;
 //  		}
 //  		// if(flag) {
 //  		// 	// t is found
 //  		// 	break;
 //  		// }
	// }

	// // if(i == m) {
	// // 	// I did not find t in mat
	// // 	cout << t << " is not present in matrix" << endl;
	// // }

	// // if(flag == false) {
	// // 	cout << t << " is not present in matrix" << endl;
	// // }

	// Pair

	pair<int, int> p = matrixSearch(mat, m, n, t);
	cout << p.first << " " << p.second << endl;

	pair<char, int> q;
	q = make_pair('A', 10);
	cout << q.first << " " << q.second << endl;


	pair<char, float> r{'B', 12.79f};
	cout << r.first << " " << r.second << endl;

	pair<string, int> f{"hello", 10};
	cout << f.first << " " << f.second << endl;

	return 0;
}