/*

Given string str of size n, design a recursive algorithm to replace all occurrences of pi 
with 3.14 in the given string and print the modified string.

Example : 
	Input : inp[] = "pippppiiiipi"
	Output: out[] = "3.14ppp3.14iii3.14"

	Input : inp[] = "pip"
	Output: out[] = "3.14p"

	Input : inp[] = "xpix"
	Output: out[] = "x3.14x"

*/

#include<iostream>

using namespace std;

void replacePi(char inp[], int i) {
	if(inp[i] == '\0') {
		return;
	}
	
	// I am standing at the ith character, and I need to check if the ith & (i+1)th character are equal to "pi" or not
	if(inp[i] == 'p' and inp[i+1] == 'i') {
		// shift all the characters starting from the (i+2)th index 2 steps to the right
		int j = i+2;
		while(inp[j] != '\0') {
			j++;
		}

		while(j >= i+2) {
			inp[j+2] = inp[j];
			j--;
		}

		// replace pi at the ith and (i+1)th index with 3.14
		inp[i] = '3';
		inp[i+1] = '.';
		inp[i+2] = '1';
		inp[i+3] = '4';

		// replace pi with 3.14 in the remaining str starting from the (i+4)th index
		replacePi(inp, i+4);

	} else {
		// replace pi with 3.14 in the remaing str starting from the (i+1)th index
		replacePi(inp, i+1);
	}

}

int main() {

	char inp[100] = "pip";
	replacePi(inp, 0);
	cout << inp << endl;
	return 0;
}
