/*

Given a phone keypad as shown below, and an n digit number, print all words which are possible by 
pressing the n digits on the keypad.

 1()     2(abc) 3(def) 
 4(ghi)  5(jkl) 6(mno)
 7(pqrs) 8(tuv) 9(wxyz)

Constraint

n <= 10

*/

#include<iostream>

using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void pressKeypad(char inp[], int i, char out[], int j) {

	if(inp[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	
	// I am standing at the ith digit of the number, and I need to decide which character it should be mapped to.
	int dig = inp[i] - '0';
	if(dig == 0 || dig == 1) {
		pressKeypad(inp, i+1, out, j);
		return;
	}

	string options = keypad[dig];
	for(char ch : options) {
		out[j] = ch;
		pressKeypad(inp, i+1, out, j+1);
	}

}

int main() {

	char inp[10] = "12";
	char out[10];

	pressKeypad(inp, 0, out, 0);
	
	return 0;
}


