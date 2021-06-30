/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to
	a) check if there exists a path from src to dst
	b) print all the paths from src to dst (assume last cell is not blocked)
such at each step the rat can only move in the right or down direction.

Constraint 

 1 <= m, n <= 10

Example 
	Input : 

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}
	
	Output :

		1 (Yes, path exist from src to dst)
	
		Paths : 
			       {"1100", {"1000", {"1000",
		            "0100",	 "1100",  "1000",
		            "0110",  "0110",  "1110",
		            "0011"}  "0011"}  "0011"}

*/

#include<iostream>

using namespace std;

bool doesPathExist(char maze[][10], char soln[][10], int m, int n, int i, int j) {
	if(i == m || j == n) {
		// you have crossed the boundaries of the grid
		return false;
	}

	if(i == m-1 and j == n-1) {

		// you are already at the dst i.e. bottom right
		soln[i][j] = '1';
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				cout << soln[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		soln[i][j] = '0';
		return true;
	}

	// I am standing at the (i, j)th cell, and I want to know if there exists a path
	// from the (i, j)th cell to the dst (m-1, n-1)

	
	// If the (i, j)th cell is blocked, definitely no path exists
	if(maze[i][j] == 'X') {
		return false;
	}

	// otherwise, a path may or maynot exists

	soln[i][j] = '1';

	// go right
	bool fromRight = doesPathExist(maze, soln, m, n, i, j+1);

	// go down
	bool fromDown  = doesPathExist(maze, soln, m, n, i+1, j);

	// backtracking
	soln[i][j] = '0';

	return fromRight || fromDown;

}

int main() {

	char maze[][10] {"0000",
	           		 "00X0",
	             	 "000X",
	            	 "0X00"};

	char soln[][10] {"0000",
	           		 "0000",
	             	 "0000",
	            	 "0000"};

	cout << doesPathExist(maze, soln, 4, 4, 0, 0) << endl;


	char name[10] = "hi";


	return 0;
}


