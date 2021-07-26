/*

Implementation of the stack using two queues.

*/

#include<iostream>
#include<queue>

using namespace std;

template <typename T>
class stack {
	queue<T> q1;
	queue<T> q2;

public:

	void push(T data) {
		if(q1.empty() && q2.empty()) {
			q1.push(data);
		} else if(q1.empty() && !q2.empty()) {
			q2.push(data);
		} else {
			q1.push(data);
		}
	}

	void pop() {
		if(q1.empty() && q2.empty()) {
			// stack is empty
		} else if(q1.empty() && !q2.empty()) {
			// transfer n-1 elements from q2 to q1
			while(q2.size() > 1) {
				q1.push(q2.front());
				q2.pop();
			}
			// pop stack top i.e. pop the nth element from q2
			q2.pop();
		} else {
			// transfer n-1 elements from q1 to q2
			while(q1.size() > 1) {
				q2.push(q1.front());
				q1.pop();
			}
			// pop stack top i.e. pop the nth element from q1
			q1.pop();
		}
	}

	T top() {
		if(q1.empty() && !q2.empty()) {
			// transfer n-1 elements from q2 to q1
			while(q2.size() > 1) {
				q1.push(q2.front());
				q2.pop();
			}
			// save & pop the nth element from q2 and transfer it to q1
			T ans = q2.front();
			q2.pop();
			q1.push(ans);
			return ans;
		} else {
			// transfer n-1 elements from q1 to q2
			while(q1.size() > 1) {
				q2.push(q1.front());
				q1.pop();
			}
			// save & pop the nth element from q1 and transfer it to q2
			T ans = q1.front();
			q1.pop();
			q2.push(ans);
			return ans;
		}
	}

	bool empty() {
		return q1.empty() && q2.empty();
	}

	int size() {
		return max(q1.size(), q2.size());
	}
};

int main() {

	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout << "size = " << s.size() << endl;

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;

	s.empty() ? cout << "true" << endl : cout << "false" << endl;
 
	return 0;	
}