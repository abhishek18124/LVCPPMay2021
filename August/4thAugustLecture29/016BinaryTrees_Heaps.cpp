/*

Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class MinHeap {
	vector<int> v;

	void heapify(int i) {
		int min_idx = i;
		int left_idx = 2*i;
		int right_idx= 2*i + 1;

		if(left_idx < v.size() && v[left_idx] < v[min_idx]) {
			min_idx = left_idx;
		}

		if(right_idx < v.size() && v[right_idx]< v[min_idx]) {
			min_idx = right_idx;
		}

		if(min_idx != i) {
			swap(v[i], v[min_idx]);
			heapify(min_idx);
		}

	}

public:
	MinHeap() {
		v.push_back(-1); // reserve the 0th index
	}

	void push(int data) {
		v.push_back(data);
		int childIdx = v.size() - 1;
		int parentIdx= childIdx / 2;

		while(childIdx > 1 && v[childIdx] < v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx= childIdx/2;
		}
	}

	void pop() {
		swap(v[1], v[v.size()-1]);
		v.pop_back();
		// now, heap property is violated at the 1st index
		heapify(1);
	}

	int top() {
		return v[1];
	}

	bool empty() {
		return v.size() == 1;
	}

	int size() {
		return v.size() - 1;
	}

};

int main() {

	MinHeap minHeap;

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





