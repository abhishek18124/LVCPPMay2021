/*

N Queens Problem

The problem is to place 'n' queens on an 'n x n' chessboard, so that no two queens are attacking 
each other, this means that no two queens are in the same row, the same column, or the same diagonal.

Example 
	Input : N = 4
	Output: 
			_ Q _ _	     _ _ Q _
	        _ _ _ Q      Q _ _ _ 
	        Q _ _ _      _ _ _ Q
	        _ _ Q _      _ Q _ _ 

Constraint:
	1<=n<=10	        

*/

#include<iostream>

using namespace std;

void placeQueens(int QPos[], int n, int r) {
	if(r == n) {
		// for(int i=0; i<n; i++) {
		// 	cout << QPos[i] << " ";
		// }
		// cout << endl;

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(QPos[i] == j) {
					cout << "Q ";
				} else {
					cout << "_ "; 
				}
			}
			cout << endl;
		}

		cout << endl;

		return;
	}

	// I am at the rth row, trying to place the Qr
	for(int j=0; j<n; j++) {
		bool canPlace = true;

		// Check if jth coln of row r is valid
		for(int i=r-1; i>=0; i--) {
			if(QPos[i]==j || QPos[i]==j+r-i || QPos[i] == j-r+i) {
				canPlace = false;
				break;
			}
		}

		if(canPlace) {
			QPos[r] = j;
			placeQueens(QPos, n, r+1);
		}
	}
}

int main() {

	int n = 4;
	int QPos[4];

	placeQueens(QPos, n, 0);

	return 0;
}