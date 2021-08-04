/*

STL implementation of the heap/priority_queue data structure.


*/

#include<iostream>
#include<queue>

using namespace std;

class Comparator {
public:
	bool operator()(int a, int b) {
		return a > b; // return a < b for max heap
	}
};

int main() {

	// priority_queue<int> maxHeap; // priority_queue<int, vector<int>, less<int>> maxHeap;
	
	priority_queue<int, vector<int>, Comparator> minHeap; // priority_queue<int, vector<int>, greater<int>> minHeap;
	

	minHeap.push(5);
	minHeap.push(0);
	minHeap.push(3);
	minHeap.push(7);
	minHeap.push(1);
	minHeap.push(2);
	minHeap.push(6);
	minHeap.push(4);

	while(!minHeap.empty()) {
		cout << minHeap.top() << " ";
		minHeap.pop();
	}

	cout << endl;

	return 0;
}