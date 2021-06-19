#include<iostream>

using namespace std;

int main() {

	int x = 10; // &x = 100
	int* y = &x;

	cout << "x =" << x << endl;
	cout << "&x = " << &x << endl;
	cout << "y = " << y << endl;
	cout << "&y = " << &y << endl;
	cout << "*(&x) = " << *(&x) << endl; 
	cout << "&(*y) = " << &(*y) << endl;
	cout << "x+1 = " << x+1 << endl;
	cout << "&x+1 = " << &x+1 << endl;
	cout << "y+1 = " << y+1 << endl;
	cout <<"*y+1 = " << *y+1 << endl;
	cout <<"*(&y) = " << *(&y) << endl;
	cout <<"&y+1 = " << &y+1 << endl;
	
	// int x = 10; // &x = 100
	// int* a = &x;

	// int y = 20; // &y = 200
	// int* b = &y;

	// (*a)++;

	// int* c = &x;
	// cout << *c << endl;

	// (*b)++;

	// (*(&x))++;

	// cout << y << endl;

	// (*c)++;

	// cout << x << endl;

	return 0;
}