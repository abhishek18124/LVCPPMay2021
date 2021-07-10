/*

1. Use the following syntax to dynamically allocate memory to store an array
	
	type * ptr	= new type[size]{init} ;

	> size can be provided at compile time or run time

2. Use the following syntax to free memory allocated for array
	
		delete[] ptr ;

3. Dynamically and statically allocated 1D arrays can be used interchangbly during a function 
   call. 
*/

#include<iostream>

using namespace std;

void f1(int* ptr) {

}

void f2(int ptr[]) {

}

int main() {

	int* ptr = new int[5];
	for(int i=0; i<5; i++) {
		ptr[i] = i*10;
	}

	for(int i=0; i<5; i++) {
		cout << ptr[i] << " ";
	}

	cout << endl;

	delete [] ptr;

	ptr = NULL;

	ptr = new int[3]{1, 2, 3}; // > C++11
	for(int i=0; i<3; i++) {
		cout << ptr[i] << " ";
	}

	cout << endl;

	int n;
	cin >> n;

	ptr = new int[n];
	for(int i=0; i<n; i++) {
		cin >> ptr[i];
	}

	for(int i=0; i<n; i++) {
		cout << ptr[i] << " ";
	}

	cout << endl;

	f1(ptr);
	f2(ptr);


	return 0;	
}