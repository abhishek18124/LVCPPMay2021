/*

Pointer to Pointer in C++

*/

#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int *p = &x;

	cout << "x = " << x << endl;
	cout << "*p = " << *p << endl;

	int** q = &p;
	cout << "**q = " << **q << endl;

	int*** r = &q;
	cout << "***r = " << ***r << endl;

	return 0;
}