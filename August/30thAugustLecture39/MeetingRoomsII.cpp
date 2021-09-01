#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// make this fn static when submitting to leetcode
bool compare(vector<int> v1, vector<int> v2) {
	return v1[0] < v2[0];
}

int minMeetingRooms(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), compare);

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(intervals[0][1]);

	for(int i=1; i<intervals.size(); i++) {
		if(intervals[i][0] < pq.top()) {
			// assign a new room to the ith meeting
			pq.push(intervals[i][1]);
		} else {
			// reuse a meeting room
			pq.pop();
			pq.push(intervals[i][1]);
		}
	}

	return pq.size();
}

int main() {

	// vector<vector<int>> intervals = {{0, 30},
	// 								 {5, 10},
	// 								 {15, 20}};

	// vector<vector<int>> intervals =  {{7, 10},
	//                                   {2, 4}};

	vector<vector<int>> intervals = {{4, 9}, {2, 15}, {16, 23}, {9, 29}, {36, 45}};

	cout << minMeetingRooms(intervals) << endl;

	return 0;
}