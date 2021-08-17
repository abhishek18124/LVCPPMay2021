/*

Given an integer array 'nums' return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without 
changing the order of the remaining elements. 

Example 1:
	Input: nums = [10,9,2,5,3,7,101,18]
	Output: 4
	Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
	Input: nums = [0,1,0,3,2,1]
	Output: 3
    Explanation: The longest increasing subsequence is [0, 1, 3] or [0, 1, 2], therefore the length is 3.

*/

#include<iostream>
#include<vector>

using namespace std;

int LIS(vector<int>& nums, int i, int j) {
	// base case
	if(j == nums.size()) return 0;

	// recursive case
	if(nums[j] > nums[i]) {
		// you've an option to either include the jth element or exclude it
		int X = 1 + LIS(nums, j, j+1);
		int Y = LIS(nums, i, j+1);
		return max(X, Y);
	}

	// you've no option but to exclude the jth element since nums[i] >= nums[j]
	return LIS(nums, i, j+1);
}


int LISTopDown(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
	// base case
	if(j == nums.size()) return dp[i][j] = 0;

	// lookup
	if(dp[i][j] != -1) return dp[i][j];

	// recursive case
	if(nums[j] > nums[i]) {
		// you've an option to either include the jth element or exclude it
		int X = 1 + LIS(nums, j, j+1);
		int Y = LIS(nums, i, j+1);
		return dp[i][j] = max(X, Y);
	}

	// you've no option but to exclude the jth element since nums[i] >= nums[j]
	return dp[i][j] = LIS(nums, i, j+1);
	
}

int LISBottomUp(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(n+1, 0));

	// order of evaluation is column-wise, right to left
	// each column can be filled in any direction, here, we fill each column from top to bottom
	for(int j=n-1; j>=1; j--) {
		// i is always less than j, so you don't have to completely fill a column
		for(int i=0; i<j; i++) { 
			if(nums[j] <= nums[i]) dp[i][j] = dp[i][j+1];
			else {
				dp[i][j] = max(1 + dp[j][j+1], dp[i][j+1]);
			}
		}
	}

	return dp[0][1];
}

int main() {

    vector<int> nums = {10,9,2,5,3,7,101,18};

    nums.insert(nums.begin(), INT_MIN);
    cout << LIS(nums, 0, 1) << endl;

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    cout << LISTopDown(nums, 0, 1, dp) << endl;
    cout << LISBottomUp(nums) << endl;

	return 0;
}


