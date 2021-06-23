/*

How to

1. declare 2D character arrays
2. initialize 2D character arays
3. initialize 2D character arrays with user input
4. print 2D character arrays

*/
#include<iostream>

using namespace std;

int main() {

	#ifndef IO
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	char strs1[][5] = {"abc",
					   "defg",
					   "hi"};

	for(int i=0; i<3; i++) {
		cout << strs1[i] << endl;
	}

	// char str[] = "def";
	// cout << str << endl;

	
	return 0;
}





