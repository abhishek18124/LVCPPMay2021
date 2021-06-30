/*

Given a string str, design a recursive algorithm to move all the occurrence of letter x 
to the end of the string str.

Example 
	Input : str = "axbcxdxfx"
	Output: str = "abcdfxxxx"

	Input : str = "xabcxdxfx"
	Output: str = "abcdfxxxx"

*/

#include<iostream>

using namespace std;

string moveXtoTheEnd(string str) {
	// base case
	
	if(str == "") { 
		return "";
	}

	// recursive case

	// keep aside the first character of the string str
	string firstChar = str.substr(0, 1);

	// move all the occurrence of x in the substring starting from the 1st index to the end
	string substr = str.substr(1);
	string substrFromRecursion = moveXtoTheEnd(substr);

	if(firstChar == "x") {
		// append firstChar to the end of the string returned by recursion
		return substrFromRecursion + firstChar;
	} else {
		// append firstChar to the beginning of the string returned by recusion
		return firstChar + substrFromRecursion;
	}

}

int main() {

	string str = "xabcxdxfx";
	cout << moveXtoTheEnd(str) << endl;

	return 0;
}
