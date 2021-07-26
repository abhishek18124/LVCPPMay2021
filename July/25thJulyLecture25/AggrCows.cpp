/*

https://www.spoj.com/problems/AGGRCOW/

*/

#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

bool canYouPlaceCows(int n, int c, int* pos, int m) {
	// you can place the 1st cow in the 1st stall
	int prevCowPos = pos[0];
	int numCowsPlaced = 1;
	for(int i=1; i<n; i++) {
		// can I place the next cow in the ith stall
		if(pos[i]-prevCowPos >= m) {
			// you can place the next cow in the ith stall
			prevCowPos = pos[i];
			numCowsPlaced++;
			if(numCowsPlaced == c) {
				return true;
			}
		}
	}
	return false;
}

int largestMinDist(int n, int c, int* pos) {
	int s = 1;
	int e = INT_MAX;
	int ans = s;

	while(s <= e) {
		int m = s + (e-s)/2;
		if(canYouPlaceCows(n, c, pos, m)) {
			// you can place c cows in n stalls s.t. min dist. is m
			// save the ans, and move toward the right
			// [s, e] -> [m+1, e]
			ans = m;
			s = m+1;
		} else {
			// you cannot place c cows in n stalls s.t min. dist. in m
			// move towards the left
			// [s, e] -> [s, m-1]
			e = m-1;
		}
	}
	return ans;
}

int main() {

	// int t;
	// cin >> t;

	// int n, c;
	// int* pos = new int[n];

	// while(t--) {
	// 	cin >> n >> c;
	// 	for(int i=0; i<n; i++) {
	// 		cin >> pos[i];
	// 	}
	// 	sort(pos, pos+n);
	// 	cout << largestMinDist(n, c, pos) << endl;
	// }	

	int n = 5;
	int c = 3;
	int pos[] = {1, 2, 4, 8, 9};
	cout << largestMinDist(n, c, pos) << endl;

	return 0;
}