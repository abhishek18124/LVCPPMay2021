/* 

https://www.spoj.com/problems/PRATA/

*/

#include<iostream>
#include<climits>

using namespace std;

int numPratasCookedByACook(int rank, int timeLimit) {
	int cnt = 0;
	int time = 0;
	int i = 1;

	while(time <= timeLimit) {
		// cook a prata
		time += i*rank;
		if(time > timeLimit) {
			return cnt;
		}
		i++;
		cnt++;
	}
	return cnt;
}

int numPratasCooked(int l, int* ranks, int timeLimit) {
	int numPratas = 0;
	for(int i=0; i<l; i++) {
		numPratas += numPratasCookedByACook(ranks[i], timeLimit);
	}
	return numPratas;
}

int getMinTime(int p, int l, int* ranks) {
	int s = 0;
	int e = INT_MAX;
	int ans = e;

	while(s <= e) {
		int m = s + (e-s) / 2;
		// how many cooks are required to cook p pratas in m amt. of time?


		// can l cooks with givens ranks cook p pratas in m amt. of time ?
		// or
		// how many pratas can l cooks with the given ranks cook in m amt. of time ?
		if(numPratasCooked(l, ranks, m) >= p) {
			// [s, e] -> [s, m-1]
			ans = m;
			e = m - 1;
		} else {
			// [s, e] -> [m+1, e]
			s = m + 1;
		}
	}
	return ans;
}

int main() {

	int t;
	cin >> t;

	int p, l;
	int* ranks = new int[l];

	while(t--) {
		cin >> p >> l;
		for(int i=0; i<l; i++) {
			cin >> ranks[i];
		}
		cout << getMinTime(p, l, ranks) << endl;
	}

	return 0;
}

