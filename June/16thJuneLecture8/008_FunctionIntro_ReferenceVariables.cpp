/*

Passing arguments to a function

	1. Call by Value
	2. Call by Reference 

*/

#include<iostream>

using namespace std;

// // call by values

// void increment(int x) {
// 	cout << "inside increment : before incrementing " << x << endl;
// 	x++;
// 	cout << "inside increment : after incrementing " << x << endl;
// }

void increment(int &a) {
	cout << "inside increment : before incrementing " << a << endl;
	a++;
	cout << "inside increment : after incrementing " << a << endl;
}

int main() {
	
	int x = 10;
	cout << "inside main : before calling increment()" << x << endl;
	increment(x);
	cout << "inside main : after calling increment()" << x << endl;

	// int y = 10;

	// int &z = y; // after initialize reference variable while declaring it

	// cout << y << " ";

	// z++;

	// cout << y;

	return 0;

}