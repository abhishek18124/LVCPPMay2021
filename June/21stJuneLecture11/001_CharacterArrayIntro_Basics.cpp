#include<iostream>

using namespace std;

int main() {
	
	char str1[] = {'A', 'B', 'C', 'D', '\0'};
	cout << str1 << endl;

	cout << (str1+1) << endl;

	char str2[5] = {'W', 'X', 'Y', 'Z', '\0'};
	cout << str2 << endl;

	char str3[] = "abcdef";
	char str4[100] = "abcdef";
	cout<< str4 << endl;

	return 0;
}