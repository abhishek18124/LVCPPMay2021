/*

Implementation of the stack data structure using the vector container.

*/

#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class stack {
	vector<T> v;

public:

	void push(T data) {
		v.push_back(data);
	}

	void pop() {
		v.pop_back();
	}

	T top() {
		return v[v.size()-1];
	}

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty();
	}

};


int main() {

	stack<char> s;

	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	s.push('e');

	cout << "size = " << s.size() << endl;

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;

	cout << "size = " << s.size() << endl;

	s.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}

