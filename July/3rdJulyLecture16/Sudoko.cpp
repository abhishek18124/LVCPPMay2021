/*

Sudoko 

Given a partially filled 'n x n' grid, the goal is to assign digits from 1 to 9 to the empty cells 
so that every row, column, and subgrid of size '√n x √n'  contains exactly one instance of 
the digits from 1 to 9. 

Assume 'n' is a perfect square, hence there are 'n' subgrids of size '√n x √n' each.


*/

#include<iostream>
#include<cmath>

using namespace std;

bool canPlace(int grid[][9], int n, int i, int j, int digit) {
	// check if digit is not already present in the same row or column
	for(int k=0; k<n; k++) {
		if(grid[i][k] == digit || grid[k][j] == digit) {
			return false;
		}
	}

	// check if digit is not already present in the subgrid of (i, j)
	int rn = sqrt(n);
	int sx = i/rn * rn;
	int sy = j/rn * rn;

	for(int x=sx; x<sx+rn; x++) {
		for(int y=sy; y<sy+rn; y++) {
			if(grid[x][y] == digit) {
				return false;
			}
 		}
	}

	return true;


}

void solveSudoko(int grid[][9], int n, int i, int j) {
	if(i == n) {
		// you have filled all the cell from row 0 to n-1 so you can stop
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	if(j == n) {
		solveSudoko(grid, n, i+1, 0);
		return;
	}

	if(grid[i][j] != 0) {
		// skip the non-empty cell
		solveSudoko(grid, n, i, j+1);
		return;
	}
	
	for(int digit=1; digit<=9; digit++) {
		if(canPlace(grid, n, i, j, digit)) {
			grid[i][j] = digit;
			solveSudoko(grid, n, i, j+1);
			// backtrack
			grid[i][j] = 0;
		}
	}

}

int main() {

	int n = 9;
	// int grid[][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
	// 		         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
	// 		         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
	// 		         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
	// 		         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
	// 		         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
	// 		         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
	// 		         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
	// 		         {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	// solveSudoko(grid, n, 0, 0);


	int grid[][9] = {{7, 8, 0, 4, 0, 0, 1, 2, 0}, 
			         {6, 0, 0, 0, 7, 5, 0, 0, 9}, 
			         {0, 0, 0, 6, 0, 1, 0, 7, 8}, 
			         {0, 0, 7, 0, 4, 0, 2, 6, 0}, 
			         {0, 0, 1, 0, 5, 0, 9, 3, 0}, 
			         {9, 0, 4, 0, 6, 0, 0, 0, 5}, 
			         {0, 7, 0, 3, 0, 0, 0, 1, 2}, 
			         {1, 2, 0, 0, 0, 7, 4, 0, 0}, 
			         {0, 4, 9, 2, 0, 6, 0, 0, 7}};

	solveSudoko(grid, n, 0, 0);

	// for(int i=0; i<n; i++) {
	// 	for(int j=0; j<n; j++) {
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// cout << endl;


	return 0;
}

