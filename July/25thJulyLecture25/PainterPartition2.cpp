/*

https://hack.codingblocks.com/app/contests/2340/1057/problem

When we calculate the mid point 'm', we ask the question 

	can 'k' painters paint 'n' boards of given 'len' in 'm' amt. of time ?
	
	now, we can rephrase this question as

    2. how many boards of given 'len' can 'k' painters paint in 'm' amt. of time ? 
	   
	   refer the canPaint() fn which answers the the original question but implements it
	   as the rephrased question.

time complexity : O(min(k, n)log(e-s))
				  canPaint() runs in O(min(k, n))
				  (e-s) indicates size of the search space

*/

#include<iostream>

using namespace std;

bool canPaint(int k, int n, int* len, int timeLimit) {
	// to keep track of total no. of boards painted by k painters in given timeLimit
	int totalBoardsPainted = 0; 
	// to iterate of the boards
	int j = 0;

	for(int i=0; i<k; i++) {
		// to keep track of time consumed by the ith painter
		int time = 0;
		// to keep track of no. of boards painted by the ith painter in the given timeLimit
		int numOfBoardsPainted = 0;
		while(time <= timeLimit && j < n) {
			// paint the jth board
			time += len[j];
			if(time > timeLimit) {
				// move to the next painter
				break;
			}
			// take into account the board painted by the ith painter 
			numOfBoardsPainted++;
			// and move to the next board
			j++;
		}
		// take into account the no. of boards painted by the ith painter
		totalBoardsPainted += numOfBoardsPainted;
		if(totalBoardsPainted >= n) {
			// k painters can paint at least n boards in the given timeLimit
			return true;
		}
	}
	// k painters cannot paint at least n boards in the given timeLimit
	return false;
}

int getMinTime(int k, int n, int* len) {
	int sum = 0;
	int maxLen = 0;
	for(int i=0; i<n; i++) {
		sum += len[i];
		maxLen = max(maxLen, len[i]);
	}
	int s = maxLen;
	int e = sum;
	int ans = e;

	while(s <= e) {
		int m = s + (e-s) / 2;
		// can k painters paint n boards in m amt. of time ?
		if(canPaint(k, n, len, m)) {
			// k painters can also paint n boards in m amt. time
			// [s, e] -> [s, m-1]
			ans = m;
			e = m-1;

		} else {
			// k painters cannot paint n boards in m amt. time
			// [s, e] -> [m+1, e]
			s = m+1;
		}
	}

	return ans;
}

int main() {
	
	int k;
	cin >> k;

	int n;
	cin >> n;

	int* len = new int[n];
	for(int i=0; i<n; i++) {
		cin >> len[i];
	}

	cout << getMinTime(k, n, len) << endl;

	return 0;
}