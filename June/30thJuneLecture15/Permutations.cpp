/*

Given a string (sequence of characters) of length n, generate all of its permutations. 

Example
	
	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>

using namespace std;

void generatePermutations(char inp[], int i) {
	if(inp[i] == '\0') {
		cout << inp << endl;
		return;
	}

	// I have to decide which character should go at the ith position
	for(int j=i; j<strlen(inp); j++) {
		swap(inp[i], inp[j]);
		generatePermutations(inp, i+1);
		swap(inp[i], inp[j]);
	}

}

int main() {

	char inp[] = "abc";
	generatePermutations(inp, 0);

	return 0;
}
