/*

Write a function to print hello.

Function with 
	* no return value i.e. return type is void
	* no argument(s)

*/

#include<iostream>

using namespace std;

void printHello() {
	cout << "inside printHello() : hello !" << endl;
	return; // optional
}

int main() {

	cout << "inside main : before calling printHello()" << endl;
	printHello(); // function call or function invocation
	cout << "inside main : after calling printHello()" << endl;

	return 0;
}