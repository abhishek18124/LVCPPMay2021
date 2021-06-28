/*

Given a number n, write a recursive algorithm to compute n!.

Example 
	Input  : n = 5
	Output : 120

*/

#include<iostream>

using namespace std;

int factorial(int n) {
	if(n == 0) {
		return 1;
	}

	return n * factorial(n-1);
}

int main() {

	cout << factorial(0) << endl;
	return 0;
}