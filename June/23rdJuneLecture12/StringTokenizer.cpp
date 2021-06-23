/*

char * strtok (char * str, const char * delimiters);

A sequence of calls to this function split str into tokens, 
which are sequences of contiguous characters separated by any 
of the characters that are part of delimiters.

*/

#include<iostream>

using namespace std;

int main() {

	char str[] = "a$bc..d/e$f...g/hi.j.kl mn/pqrs$";
	char delimiters[] = ".$/ ";

	char* token = strtok(str, delimiters);
	
	while(token != NULL) {
		cout << token << endl;
		token = strtok(NULL, delimiters);
	}

	return 0;
}







