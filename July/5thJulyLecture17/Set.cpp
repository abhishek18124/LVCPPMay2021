#include<iostream>
#include<set>

using namespace std;

int main() {

	multiset<int> s;

	s.insert(10);
	s.insert(20);
	s.insert(10);

	// set<int>::iterator it = s.begin();

	// cout << *it << endl;

	// it++;

	// cout << *it << endl;

	// it++;

	// cout << *it << endl;

	for(auto it = s.begin(), end = s.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	set<string> s2;

	s2.insert("cba");
	s2.insert("bca");
	s2.insert("abc");

	// for(auto it = s2.begin(), end = s2.end(); it != end; it++) {
	// 	cout << *it << endl;
	// }

	for(auto str : s2) {
		cout << str << endl;
	}

	return 0;
}