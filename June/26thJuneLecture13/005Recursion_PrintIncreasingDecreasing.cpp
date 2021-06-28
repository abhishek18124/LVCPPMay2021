/*

Given a number n, write a recursive algorithm to numbers from 1 to n in

	a) decreasing order
	b) increasing order

Example 
	Input  : n = 5
	Output : a) 5, 4, 3, 2, 1 
	         b) 1, 2, 3, 4, 5

*/

#include<iostream>

using namespace std;

void printInc(int n) {
	// if(n == 1) {
	// 	cout << 1 << " ";
	// 	return;
	// }

	if(n == 0) {
		return;
	}

	printInc(n-1);
	cout << n << " ";
}

void printDec(int n) {
	// if(n == 1) {
	// 	cout << 1 << " ";
	// 	return;
	// }

	if(n == 0) {
		return;
	}

	cout << n << " ";
	printDec(n-1);
	
}

int main() {

	printInc(5);
	cout << endl;
	printDec(5);
	return 0;
}