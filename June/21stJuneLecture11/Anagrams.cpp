/*

Given a two strings a & b represented as a character arrays, 
write a function that returns true if a & b are anagrams otherwise 
returns false.

Example :
	Input : a[] = "aabbccc" b[] = "cabccab"
	Output: true

	Input : a[] = "abc" b[] = "abd"
	Output: false
*/
#include<iostream>

using namespace std;

bool isAnagram(char* a, char* b) {
	int freqA[26] = {0};
	for(int i=0; a[i] != '\0'; i++) {
		char ch = a[i];
		int idx = ch - 'a';
		freqA[idx]++;
	}

	// for(int i=0; i<26; i++) {
	// 	cout << freqA[i] << " ";
	// }

	// cout << endl;

	int freqB[26] = {0};
	for(int i=0; b[i] != '\0'; i++) {
		freqB[b[i]-'a']++;
	}

	// for(int i=0; i<26; i++) {
	// 	cout << freqB[i] << " ";
	// }
	// cout << endl;

	// compare the frequency arrays

	for(int i=0; i<26; i++) {
		if(freqA[i] != freqB[i]) {
			return false;
		}
	}

	return true;
	
}

int main() {

	char a[] = "aabbccc";
	char b[] = "cabccab";

	isAnagram(a, b) ? cout << "Yes!\n" : cout << "No!\n";
	
	return 0;
}






