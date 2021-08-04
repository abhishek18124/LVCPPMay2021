/*

Given an infinite stream of non-negative integers, design an algorithm to output the top-K integers every time you 
encounter -1.

Example : Input = 4, 1, 2, -1, 3, -1 7 0 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8
                   . . .

*/

#include<iostream>
#include<queue>

using namespace std;

void print(priority_queue<int, vector<int>, greater<int>> minHeap) {
    cout << "top-k = ";
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {

    int k;
    cout << "k >> ";
    cin >> k;

    int x;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int cnt = 0;

    while(true) {
        cin >> x;
        if(x == -1) {
            // print the top-k elements from the min heap
            print(minHeap);
        } else {
            if(cnt < k) {
                // assume you' wont get -1 till you've seen at least k elements
                minHeap.push(x);
                cnt++;
            } else {
                if(x > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(x);
                }
            }
        }
    }

	return 0;
}