/*

Write a function to check if a number is prime or not.

*/

#include<iostream>

using namespace std;

bool isDivisible(int x, int y) {
	return x%y == 0;
}

bool isPrime(int n) {
	for(int i=2; i<n; i++) {
		if(isDivisible(n, i)) {
			return false;
		}
	}
	return true;
}

void printPrimes(int n) {
	int count = 0; 
	int x = 2;
	while(count < n) {
		if(isPrime(x)) {
			cout << x << " ";
			count++;
		}
		x++;
	}
	return; // optional
}

int main() {

	// isPrime(7) ? cout << "7 is prime!" : cout << "7 is not prime";

	printPrimes(10);
	
	return 0;
}