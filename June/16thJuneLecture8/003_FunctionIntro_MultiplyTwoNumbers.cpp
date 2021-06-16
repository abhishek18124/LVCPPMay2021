/*

Write a function to multiply two integers.

*/
#include<iostream>

using namespace std;

int multiply(int x, int y) {
	return x * y;
}

int main() {

	int a = 10;
	int b = 20;

	int c = multiply(a, b);

	cout << c << endl;

	c = c + 10;

	cout << c << endl;

	cout << multiply(a, b) + 10 << endl;

	return 0;
}