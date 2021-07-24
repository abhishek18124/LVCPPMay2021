/*

C++ STL implementation of the stack data structure

*/

#include<iostream>
#include<stack>

using namespace std;

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