/*

1. Use the 'new' keyword to dynamically allocate memory.
2. Use the 'delete' keyword to free memory allocated dynamically.
3. Always set the pointer to freed memory to NULL.   
4. You can return a pointer to a dynamically allocated memory from a function. 

*/

#include<iostream>

using namespace std;

int* add(int x, int y) {
	int* z = new int;
	*z = x + y;
	return z;
}

int main() {
	
	int *p = new int;

	// cout << p << endl;

	*p = 20;

	cout << *p << endl;

	delete p;

	p = NULL;

	// cout << *p << endl; // error

	int x = 10;
	int y = 20;

	int*z = add(x, y);

	cout << *z << endl;

	delete z;

	z = NULL;

	return 0;
}