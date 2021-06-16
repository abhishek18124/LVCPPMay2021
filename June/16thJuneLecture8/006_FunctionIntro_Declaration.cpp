/*

Function Declaration vs Definition

*/

#include<iostream>

using namespace std;

// int add(int, int); // function prototype or forward declartion or function declaration


int add(int x, int y) {
	return x+y;
}

int main() {

	cout << add(3, 4) << endl;
	return 0;
}

