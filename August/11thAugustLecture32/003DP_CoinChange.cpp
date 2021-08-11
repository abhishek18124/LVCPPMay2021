/*

You are given an integer array coins representing coins of different denominations and an integer amount 
representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 

You may assume that you have an infinite number of each kind of coin.

Don't forget to handle the case if that amount of money cannot be made up by any combination of the coins.

Example 1:

	Input: coins = [1,2,5], amount = 11
	Output: 3

	Input: coins = [3, 6], amount = 13
	Output: no way

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minCoinsToZero(vector<int>& coins, int n) {
	// base case
	if(n == 0) return 0;

	// recursive case
	int minCoins = INT_MAX;
	for(int i=0; i<coins.size(); i++) {
		if(n-coins[i] >= 0) {
			minCoins = min(minCoins, minCoinsToZero(coins, n-coins[i]));

		}
	}

	return minCoins == INT_MAX ? minCoins : 1 + minCoins; 
}

int minCoinsToZeroTopDown(vector<int>& coins, int n, vector<int>& dp) {
	// base case
	if(n == 0) return dp[n]=0;

	// lookup
	if(dp[n] != -1) return dp[n];

	// recursive case
	int minCoins = INT_MAX;
	for(int i=0; i<coins.size(); i++) {
		if(n-coins[i] >= 0) {
			minCoins = min(minCoins, minCoinsToZeroTopDown(coins, n-coins[i], dp));
		}
	}

	int ans = minCoins == INT_MAX ? minCoins : 1 + minCoins;
	return dp[n] = ans; 
}

int minCoinsToZeroBottomUp(vector<int>& coins, int n) {
	vector<int> dp(n+1);

	dp[0] = 0;
	for(int j=1; j<=n; j++) {
		// dp[j] = f(j) = min. no. of coins required to reduce an amount j to 0
		int minCoins = INT_MAX;
		for(int i=0; i<coins.size(); i++) {
			if(j-coins[i] >= 0) {
				minCoins = min(minCoins, dp[j-coins[i]]);
			}
		}

		dp[j] = minCoins == INT_MAX ? minCoins : 1 + minCoins;
	}

	return dp[n];

}

int main() {

	vector<int> coins = {5, 10};
	int n = 35;

	cout << minCoinsToZero(coins, n) << endl;

	vector<int> dp(n+1, -1);
	cout << minCoinsToZeroTopDown(coins, n, dp) << endl;
	cout << minCoinsToZeroBottomUp(coins, n) << endl;

	return 0;
}











