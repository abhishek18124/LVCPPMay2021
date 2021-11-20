/*
Given K painters to paint N boards where each painter takes 1 unit of time to paint 1 unit of boards i.e. if the length of a particular board is 5, it will take 5 units of time to paint the board. Compute the minimum amount of time to paint all the boards.

Note that:

Every painter can paint only contiguous segments of boards.
A board can only be painted by 1 painter at maximum.

Input Format
First line contains K which is the number of painters. Second line contains N which indicates the number of boards. Third line contains N space separated integers representing the length of each board.


https://hack.codingblocks.com/app/contests/2340/1057/problem

When we calculate the mid point 'm', we ask the question 

	can 'k' painters paint 'n' boards of given 'len' in 'm' amt. of time ?
	
	now, we can rephrase this question in two ways 

	1. how many painters are required to paint 'n' boards of given 'len' in 'm' amt. of time ?
	
	   say, 'x' painters can paint 'n' boards of given 'len' in 'm' amt. of time then
	   
	   case (a)

	   now, if x <= k then that means 'k' painters can also paint 'n' boards of given 'len' 
	   in 'm' amt. of time so we get 'true' and move towards the left to minimize time
	
	   case (b)

	   if x > k then that means 'k' painters cannot paint 'n' boards of given 'len' in 'm'
	   amt. of time i.e we get false and move towards the right.

    2. how many boards of given 'len' can 'k' painters paint in 'm' amt. of time ? 
	   
	   see PainterPartition2.cpp for its implementation

time complexity : O(nlog(e-s))
				  numPaintersRequired() runs in O(n)
				  (e-s) indicates size of the search space


*/

#include<iostream>

using namespace std;

int numPaintersRequired(int n, int* len, int timeLimit) {
	int numPainters = 1;
	int time = 0;
	for(int i=0; i<n; i++) {
		// paint the ith board
		time += len[i];
		if(time > timeLimit) {
			// add another painter to the job
			numPainters++;
			// this painter restart painting the ith board
			time = len[i];
		}
	}
	return numPainters;
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
		// or
        // how many painters do I need to paint n boards in m amt. of time ?
        int x = numPaintersRequired(n, len, m);
		if(x <= k) {
			// if x painters can paint n boards in m amt. of time such that x <= k then
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
