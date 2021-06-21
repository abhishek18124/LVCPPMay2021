/*

Write a function to compute the length of a string represented as a character array.

*/
#include<iostream>

using namespace std;

int len(char* str) {
	int i=0;
	for(; str[i]!='\0'; i++);
	return i;
}

int main() {

	char str[] = "John Lenon";
	// cout << len(str) << endl;
	cout << strlen(str) ; // <cstring>

	return 0;
}