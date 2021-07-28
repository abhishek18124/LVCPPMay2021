#include<iostream>
#include<stack>

using namespace std;

void insertAtMid(stack<int>& stack, int x, int p) {
	if(p == 0) {
		stack.push(x);
		return;
	}

	int y = stack.top(); stack.pop();
	insertAtMid(stack, x, p-1);
	stack.push(y);
}

void reverse(stack<int>& stack, int m) {
	if(m == 0) {
		return;
	}

	int x = stack.top(); stack.pop(); 
	reverse(stack, m-1);
	insertAtMid(stack, x, m-1);
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
	s.push(6);

	print(s);

	int n = 6;

	reverse(s, n/2);

	print(s);
	return 0;
}