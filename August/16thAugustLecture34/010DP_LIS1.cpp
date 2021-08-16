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

int main() {

    vector<int> nums = {10,9,2,5,3,7,101,18};

    nums.insert(nums.begin(), INT_MIN);
    cout << LIS(nums, 0, 1) << endl;

	return 0;
}


