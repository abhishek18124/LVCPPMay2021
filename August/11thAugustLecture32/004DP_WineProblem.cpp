/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year you can sell the 
first or the last wine in the row. However, the price of wines increases over time. 

Let the initial profits from the wines be [p_0, p_1, ... , p_n-1]. In the yth year, the profit from 
the kth wine will be y*p_k. 

Find the maximum profit from all the wines.

Example :
	Input : wines[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& wines, int i, int j, int y) {
	// base case
	if(i == j) return y*wines[i];

	// recursive case

	// you're in the yth year, and you can sell either the ith wine or the jth wine

	// you sell ith wine
	int x1 = maxProfit(wines, i+1, j, y+1);

	// you sell jth wine
	int x2 = maxProfit(wines, i, j-1, y+1);

	return max(y*wines[i]+x1, y*wines[j]+x2);

}

int maxProfitTopDown(vector<int>& wines, int i, int j, int y, vector<vector<int>>& dp) {
	// base case
	if(i == j) return dp[i][j]=y*wines[i];

	// lookup
	if(dp[i][j] != -1) return dp[i][j];

	// recursive case

	// you're in the yth year, and you can sell either the ith wine or the jth wine

	// you sell ith wine
	int x1 = maxProfitTopDown(wines, i+1, j, y+1, dp);

	// you sell jth wine
	int x2 = maxProfitTopDown(wines, i, j-1, y+1, dp);

	return dp[i][j]=max(y*wines[i]+x1, y*wines[j]+x2);

}

int maxProfitBottomUp(vector<int>& wines) {
	int n = wines.size();
	vector<vector<int>> dp(n, vector<int>(n));

	// fill the main diagonal
	for(int i=0; i<n; i++) {
		dp[i][i] = n * wines[i];
	}

	for(int i=n-2; i>=0; i--) {
		for(int j=i+1; j<n; j++) {
			int y = n - (j-i);
			dp[i][j] = max(wines[i]*y + dp[i+1][j],
						   wines[j]*y + dp[i][j-1]);
		}
	}

	return dp[0][n-1];

}

// BottomUp Version 2, filling the matrix diagonal-wise

void fill(vector<int>& wines, vector<vector<int>>& dp, int i, int j) {
	int n = wines.size();
	// to iterate over the diagonal starting at the  (i, j)th index, first compute the length of the diagonal
	int len = n-j; 
	for(int l=0; l<len; l++) {
		dp[i+l][j+l] = max(len*wines[i+l] + dp[i+1+l][j+l],
			               len*wines[j+l] + dp[i+l][j-1+l]);
	}
}

int maxProfitBottomUpV2(vector<int>& wines) {
	int n = wines.size();
	vector<vector<int>> dp(n, vector<int>(n, 0));

	// fill main diagonal
	for(int i=0; i<n; i++) {
		dp[i][i] = n*wines[i];
	}

	// fill remaining diagonals
	for(int k=1; k<n; k++) {
		// iterate over the kth diagonal starting from index (0, k)
		fill(wines, dp, 0, k);
	}

	return dp[0][n-1];
}


int main() {

	vector<int> wines =  {2, 3, 5, 1, 4};
	int n = wines.size();
	
	cout << maxProfit(wines, 0, n-1, 1) << endl;

	vector<vector<int>> dp(n, vector<int>(n, -1));

	cout << maxProfitTopDown(wines, 0, n-1, 1, dp) << endl;
	cout << maxProfitBottomUp(wines) << endl;
	cout << maxProfitBottomUpV2(wines) << endl;

	return 0;
}