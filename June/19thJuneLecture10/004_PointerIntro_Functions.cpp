/*

Passing arguments to a function

1. call by value
2. call by reference
	2.1 using reference variables
	2.2 using pointers

*/

#include<iostream>

using namespace std;

void increment(int* aptr) {
	cout << "inside increment before increment: *aptr = " << *aptr << endl;
	(*aptr)++;
	cout << "inside increment after increment : *aptr = " << *aptr << endl;
}

int main() {

	int a = 10;;
	cout << "inside main before increment : a = " << a << endl;
	increment(&a);
	cout << "inside main after increment : a = " << a << endl;

	return 0;
}