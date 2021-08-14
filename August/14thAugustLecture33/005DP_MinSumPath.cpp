/*

Given a m x n grid filled with non-negative numbers, find a path from (0, 0) to (x, y), which minimizes 
the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example : 
	Input: grid = [[1,3,1],
	               [1,5,1],
	               [4,2,1]]
	       
	       (x, y) = (2, 2)

	Output: 7
	Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Constraints :
	1 <= m, n <= 200
	0 <= grid[i][j] <= 100
	0 <= x < m 
	0 <= y < n

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minSumPath(vector<vector<int>>& grid, int i, int j) {

	// base case
	if(i == 0 && j == 0) return grid[0][0];

	if(i == 0) // && j != 0
		// you can only reach the (i, j)th cell from the left
		return grid[0][j] + minSumPath(grid, 0, j-1);

	if(j == 0) // && i != 0
		// you can only reach the (i, j)th cell from the top
		return grid[i][0] + minSumPath(grid, i-1, 0);

	// if(i < 0 || j < 0) return INT_MAX; 

	// recursive case
	return grid[i][j] + min(minSumPath(grid, i-1, j),
		                    minSumPath(grid, i, j-1));

}

int minSumPathTopDown(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {

	// base case
	if(i == 0 && j == 0) return dp[0][0] = grid[0][0];

	// lookup
	if(dp[i][j] != -1) return dp[i][j];

	if(i == 0) // && j != 0
		// you can only reach the (i, j)th cell from the left
		return dp[0][j] = grid[0][j] + minSumPathTopDown(grid, 0, j-1, dp);

	if(j == 0) // && i != 0
		// you can only reach the (i, j)th cell from the top
		return dp[i][0] = grid[i][0] + minSumPathTopDown(grid, i-1, 0, dp);

	// if(i < 0 || j < 0) return INT_MAX; 

	// recursive case
	return dp[i][j] = grid[i][j] + min(minSumPathTopDown(grid, i-1, j, dp),
		                               minSumPathTopDown(grid, i, j-1, dp));

}

int minSumPathBottomUp(vector<vector<int>>& grid, int x, int y) {
	int m = grid.size();
   	int n = grid[0].size();

	vector<vector<int>> dp(m, vector<int>(n));

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(i == 0 && j == 0) dp[0][0] = grid[0][0];
			else if(i == 0) dp[0][j] = grid[0][j] + dp[0][j-1];
			else if(j == 0) dp[i][0] = grid[i][0] + dp[i-1][0];
			else dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[x][y];
}

int main() {

	vector<vector<int>> grid = {{1, 1, 2},
   								{2, 2, 2},
   								{4, 1, 1}};

   	int m = grid.size();
   	int n = grid[0].size();

   	int x = 2;
   	int y = 2;

   	cout << minSumPath(grid, x, y) << endl;

   	vector<vector<int>> dp(m, vector<int>(n, -1));
   	cout << minSumPathTopDown(grid, x, y, dp) << endl;
   	cout << minSumPathBottomUp(grid, x, y) << endl;

	return 0;
}






