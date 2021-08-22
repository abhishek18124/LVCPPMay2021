/*

You are packing for a vacation on the sea side and you are going to carry only one bag with 
capacity C (1 <= C <= 1000). You also have N (1<= N <= 1000) items that you might want to take 
with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will 
have to choose. For each item you are given its size and its value. You want to maximize the total 
value of all the items you are going to bring. What is this maximum total value?

Example :
	Input : N = 5, C = 4
			w = {1, 2, 3, 2, 2}
			p = {8, 4, 1, 5, 3}
	Output: 12

*/


#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& p, vector<int>& w, int c, int n, int i) {
	
	// base cases
	if(i == n || c == 0) return 0;

	// recursive case
	if(w[i] > c) {
		// exclude the ith item
		return maxProfit(p, w, c, n, i+1);
	}

	// you've an option to either include or exclude the ith item
	int p1 = p[i] + maxProfit(p, w, c-w[i], n, i+1);
	int p2 = maxProfit(p, w, c, n, i+1);
	return max(p1, p2);
}


int maxProfitTopDown(vector<int>& p, vector<int>& w, int c, int n, int i, vector<vector<int>>& dp) {
	
	// base cases
	if(i == n || c == 0) return dp[i][c] = 0;

	// lookup
	if(dp[i][c] != -1) return dp[i][c];

	// recursive case
	if(w[i] > c) {
		// exclude the ith item
		return dp[i][c] = maxProfitTopDown(p, w, c, n, i+1, dp);
	}

	// you've an option to either include or exclude the ith item
	int p1 = p[i] + maxProfitTopDown(p, w, c-w[i], n, i+1, dp);
	int p2 = maxProfitTopDown(p, w, c, n, i+1, dp);
	return dp[i][c] = max(p1, p2);
}

int maxProfitBottomUp(vector<int>& p, vector<int>& w, int C, int N) {
	vector<vector<int>> dp(N+1, vector<int>(C+1, 0));

	for(int i=N-1; i>=0; i--) {
		for(int c=C; c>=1; c--) {
			if(w[i] > c) dp[i][c] = dp[i+1][c];
			else {
				int p1 = p[i] + dp[i+1][c-w[i]];
				int p2 = dp[i+1][c];
				dp[i][c] = max(p1, p2);
			}
		}
	}

	return dp[0][C];
}

int main() {

	vector<int> p = {8, 4, 1, 5, 3};
	vector<int> w = {1, 2, 3, 2, 2};
	int C = 4;
	int N = 5;

	cout << maxProfit(p, w, C, N, 0) << endl;

	vector<vector<int>> dp(N+1, vector<int>(C+1, -1));
	cout << maxProfitTopDown(p,w, C, N, 0, dp) << endl;
	cout << maxProfitBottomUp(p, w, C, N) << endl;

	return 0;
}