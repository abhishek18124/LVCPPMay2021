/*

Given a two strings a & b represented as a character arrays, 
write a function that copies string b into string a.

Example :
	Input : a[] = "abc" b[] = "def"
	Output: a[] = "def"
*/
#include<iostream>

using namespace std;

void copy(char* a, char* b) {
	int i = 0;
	while(i <= strlen(b)) {
		a[i] = b[i];
		i++;
	}
}

int main() {

	char a[100] = "ab";
	char b[100] = "def";

	cout << "before copy a = " << a << endl;
	// copy(a, b);
	strcpy(a, b);
	cout << "after copy a = " << a << endl;

	return 0;
}