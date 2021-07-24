
/*

C++ STL implementation of the queue data structure

*/

#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	cout << "size = " << q.size() << endl;

	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();	
	}

	cout << endl;

	cout << "size = " << q.size() << endl;

	q.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}
