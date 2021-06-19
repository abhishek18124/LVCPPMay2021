/*

Part 1 : Why pointers in C++ are always strongly typed ?

*/

#include<iostream>

using namespace std;

int main() {

	int x = 516;
	int* xptr = &x;

	cout << "*xptr = " << *xptr << endl;

	// char* chptr = (char *)&x;
	char* chptr = (char*) xptr;

	// cout << "*chptr = " << *chptr << endl; // 4

	cout << "*chptr==4 = " << (*chptr == 4) << endl;

	return 0;
}