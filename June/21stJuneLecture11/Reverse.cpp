/*

Given a string represented as a character array, write a function to reverse it.

Example :
	Input : str[] = "abcde"
	Output: str[] = "edcba"
*/
#include<iostream>

using namespace std;

void reverse(char* str) {
	int i = 0;
	int j = strlen(str) - 1;
	while(i < j) {
		swap(str[i], str[j]);
		i++;
		j--;
	}
}

int main() {

	char str[] = "abcde";
	// cout << "before reverse str = " << str << endl;
	// reverse(str);
	// cout << "after reverse str = " << str << endl;
	
	// cout << str << endl;
	// reverse(str, str+strlen(str)); // built-in
	// cout << str << endl;

	int arr[] = {1, 2, 3};
	reverse(arr, arr+3);
	for(int i=0; i<3; i++) cout << arr[i] << " ";

	return 0;
}