/*

Given a two strings a & b represented as a character arrays, 
write a function that appends string b to string a.

Example :
	Input : a[] = "abc" b[] = "def"
	Output: a[] = "abcdef"
*/
#include<iostream>

using namespace std;

void append(char* a, char* b) {
	int i = strlen(a);
	int j = 0;
	while(j <= strlen(b)) {
		a[i++] = b[j++];
	}
}

int main() {

	char a[100] = "abc";
	char b[100] = "def";

	cout << "Before append a = " << a << endl;
	// append(a, b);
	strcat(a, b); // built-in
	cout << "After append a = " << a << endl;

	return 0;
}