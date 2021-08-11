/*

Design a recursive algorithm to convert a string into an integer.

Example :
	Input : str[] = "123"
	Output: 123

*/

#include<iostream>

using namespace std;

int stringToInteger(string str, int n) {
	if(n == 0) {
		return 0;
	}
	int lastDigit = str[n-1] - '0'; // converts char repr. digit into digit
	return stringToInteger(str, n-1) * 10 + lastDigit;
}

int main() {

	char str[] = "456";
	string str = "456";
	// int n = strlen(str);
	int n = str.length();

	int integer = stringToInteger(str, n); 
	cout << integer << endl;

	return 0;
}

