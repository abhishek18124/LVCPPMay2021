/*

1. Do not return a pointer to a local variable from a function. 

*/

#include<iostream>

using namespace std;

int* add(int x, int y) {
	int z = x + y;
	return &z;
}

int main() {

	int x = 10;
	int y = 20;

	int*z = add(x, y);

	// cout << *z << endl; // don't do this

	return 0;
}