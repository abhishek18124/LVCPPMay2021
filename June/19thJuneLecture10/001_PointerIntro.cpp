/*

Introduction to Pointers in C++

1. Address Of operator (&)
2. Dereference Operator(*)

*/

#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int *xptr = &x;
	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << "B" << endl;
	cout << "&x = " << &x << endl;
	cout << "sizeof(&x) = " << sizeof(&x) << "B" << endl;
	cout << "xptr = " << xptr << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << "B" << endl;
	cout << "*xptr = " << *xptr << endl;

	cout << endl;

	char ch = 'A';
	char* chptr = &ch;
	cout << "ch = " << ch << endl;
	cout << "sizeof(ch) = " << sizeof(ch) << "B" << endl;
	cout << "&ch = " << (void *)&ch << endl;
	cout << "sizeof(&ch) = " << sizeof(&ch) << "B" << endl;
	cout << "chptr = " << (void *)chptr << endl;
	cout << "sizeof(chptr) = " << sizeof(chptr) << "B" << endl;
	cout << "*chptr = " << *chptr << endl;


	return 0;
}