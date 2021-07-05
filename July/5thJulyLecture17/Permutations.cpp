/*

Given a string (sequence of characters) of length n, generate all of its permutations. 

Example
	
	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<set>

using namespace std;

void generatePermutations(char inp[], int i, set<string>& s) {
	if(inp[i] == '\0') {
		// cout << inp << endl;
		s.insert(string(inp));
		return;
	}

	// I have to decide which character should go at the ith position
	for(int j=i; j<strlen(inp); j++) {
		swap(inp[i], inp[j]);
		generatePermutations(inp, i+1, s);
		swap(inp[i], inp[j]);
	}

}

int main() {

	char inp[] = "cba";
	set<string> s;
	generatePermutations(inp,  0, s);

	for(string str : s) {
		cout << str << endl;
	}

	return 0;
}
