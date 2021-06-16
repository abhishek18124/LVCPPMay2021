/*

Write a function to check if a number is even or not.

*/

#include<iostream>

using namespace std;

// void isEven(int x) {

// 	if(x%2 == 0) {
// 		cout << x << " is an even number!" << endl;
// 	} else {
// 		cout << x << " is an odd number!" << endl;
// 	}
// }

// bool isEven(int x) {
// 	if(x%2 == 0) {
// 		return true;
// 	} else {
// 		return false; 
// 	}
// }

bool isEven(int x) {
	return x%2 == 0;
}

int main() {

	int n = 7;

	// bool answer = isEven(n); // invoke/call a function by passing an argument

	// if(answer == true) {
	// 	cout << n  << " is an even number!" << endl;
	// } else {
	// 	cout << n << " is an odd number!" << endl;
	// }

	// if(answer) {
	// 	cout << n  << " is an even number!" << endl;
	// } else {
	// 	cout << n << " is an odd number!" << endl;
	// }

	// if(isEven(n)) {
	// 	cout << n << " is an even number!" << endl;
	// } else {
	// 	cout <<  n << " is an odd number!" << endl;
	// }

	// ternary operator

	isEven(n) ? cout << n << " is an even number!" << endl : cout << n << " is an odd number!" << endl;

	return 0;
}
