/*

=============
Edit Distance
=============

Given two strings s1 and s2, return the minimum number of operations (edits) required to convert s1 to s2.

You have the following three operations permitted on a word:

	> Insert a character
	> Delete a character
	> Replace a character

The minimum number of edits required to convert s1 to s2 is also known as the edit distance between s1 & s2.

Examples

Example 1:

	Input: s1 = "horse", s2 = "ros"
	Output: 3

	Explanation: 
	horse -> rorse (replace 'h' with 'r')
	rorse -> rose (remove 'r')
	rose -> ros (remove 'e')

Example 2:

	Input: s1 = "intention", s2 = "execution"
	Output: 5
	
	Explanation: 
	intention -> inention (remove 't')
	inention -> enention (replace 'i' with 'e')
	enention -> exention (replace 'n' with 'x')
	exention -> exection (replace 'n' with 'c')
	exection -> execution (insert 'u')

Example 3:

	Input: s1 = "food", s2 = "money"
	Output: 4
	
Example 4:
	
	Input: s1 = "algorithm", s2 = "altruistic"
	Output: 6

*/

#include<iostream>
#include<vector>

using namespace std;

int editDistance(string& s1, string& s2, int i, int j) {
	// base case
	if(i == s1.size() && j == s2.size()) {
		// s1 is empty and s2 is empty
		return 0;
	}

	if(i == s1.size()) {
		// s1 is empty, s2 is not empty
		int n = s2.size();
		return n - j;
	}

	if(j == s2.size()) {
		// s1 is not empty, s2 is empty
		int m = s1.size();
		return m - i;
	}

	// recursive case
	int ins = 1 + editDistance(s1, s2, i, j+1);
	int del = 1 + editDistance(s1, s2, i+1, j);
	int sub = editDistance(s1, s2, i+1, j+1) + (s1[i]!=s2[j] ? 1:0);

	return min({ins, del, sub});

}

int editDistanceBottomUp(string&s1, string& s2, int m, int n) {
	vector<vector<int>> dp(m+1, vector<int>(n+1));

	for(int i=m; i>=0; i--) {
		for(int j=n; j>=0; j--) {
			if(i == m && j == n) dp[i][j] = 0;
			else if(i == m) dp[i][j] = n-j;
			else if(j == n) dp[i][j] = m-i;
			else {
				int ins = 1 + dp[i][j+1];
				int del = 1 + dp[i+1][j];
				int sub = dp[i+1][j+1] + (s1[i]!=s2[j] ? 1:0);
				dp[i][j] = min({ins, del, sub});
			}
		}
	}

	return dp[0][0];
}

int main() {

	string s1("intention");
	string s2("execution");

	int m = s1.size();
	int n = s2.size();

	cout << editDistance(s1, s2, 0, 0) << endl;
	cout << editDistanceBottomUp(s1, s2, m, n) << endl;

	return 0;
}
