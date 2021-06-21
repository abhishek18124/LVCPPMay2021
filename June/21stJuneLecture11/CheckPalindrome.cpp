/*

Given a string represented as a character array, write a function that returns
true if the string is a palindrome otherwise return false.

Example :
	Input : str[] = "level"
	Output: true

	Input : str[] = "abxyba"
	Output: false

*/
#include<iostream>

using namespace std;

bool isPalindrome(char* str) {
	int i = 0;
	int j = strlen(str) - 1;
	while(i < j) {
		if(str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main() {

	char str[] = "abxca";
	isPalindrome(str) ? cout << str << " is a palindrome !" << endl : cout << str << " is not a palindrome !" << endl;
	return 0;
}
