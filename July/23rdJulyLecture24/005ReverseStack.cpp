/*

Write a program to reverse a stack without using any additional data structure.

*/

#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>& s, int x) {
	if(s.empty()) {
		s.push(x);
		return;
	}	

	int y = s.top();
	s.pop();
	insertAtBottom(s, x);
	s.push(y);
}

void reverse(stack<int>& s) {
	if(s.empty()) {
		return;
	}

	int x = s.top(); s.pop();
	reverse(s);
	insertAtBottom(s, x);
}

void print(stack<int> s) {
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

int main() {

	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	print(s);

	reverse(s);

	print(s);

	return 0;
}