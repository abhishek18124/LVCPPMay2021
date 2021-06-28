/*

Given two non negative integers a and b, write a recursive algorithm to multiply them.

*/

#include<iostream>

using namespace std;

int multiply(int a, int b) {
	// base case 
	if(b == 0) {
		return 0;
	}
	
	// recursive case
	return a + multiply(a, b-1);
}

int multiplyV2(int a, int b) {
	// if(b == 0) {
	// 	return 0;
	// }

	if(b == 1) {
		return a;
	}

	int tmp = multiplyV2(a, b/2);
	if(b%2 == 1) return 2*tmp + a;
	return 2*tmp;

}

int main() {

	int a = 3;
	int b = 5;

	// cout << multiply(a, b) << endl;
	cout << multiplyV2(a, b) << endl;
	
	return 0;
}