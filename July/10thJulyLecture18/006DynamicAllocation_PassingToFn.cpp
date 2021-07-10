/*

Dynamically and statically allocated 2D arrays CANNOT be used interchangbly during a function 
call. 

*/

#include<iostream>

using namespace std;

void f0(int** a) {

}


void f1(int a[][4]) {

}

void f5(int (*a)[4]) {

}

void f2(int ptr[][4]) {

}

void f3(int** ptr) {

}

int main() {

	int a[3][4];
	// f0(a); // give an error
	f1(a); // works
	f5(a);

	int** ptr = new int*[3];
	for(int i=0; i<3; i++) {
		ptr[i] = new int[4];
	}

	// f2(ptr); // give an error

	f3(ptr); // works

	return 0;
}