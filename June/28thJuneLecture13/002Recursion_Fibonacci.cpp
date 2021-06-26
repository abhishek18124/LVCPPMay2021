/*

Given a number n, write a recursive algorithm to find the nth fibonacci number.

Example 
	Input  : n = 5
	Output : 5

	Input  : n = 6
	Output : 8

	Input  : n = 7
	Output : 13

*/

#include<iostream>

using namespace std;

int fibo(int n) {
	if(n == 0 || n == 1)  return n;
	return fibo(n-1) + fibo(n-2);
}

int main() {

	cout << fibo(10) << endl;
	return 0;
}