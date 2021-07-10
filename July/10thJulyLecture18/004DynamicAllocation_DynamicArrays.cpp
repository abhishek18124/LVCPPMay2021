/*

Creating dynamic arrays.

*/

#include<iostream>

using namespace std;

int* resize(int* a, int size) {
	cout << "Resize from " << sizeof(int) * size << "B to " << sizeof(int) * size * 2 << "B" << endl;
	int* b = new int[size*2];
	for(int i=0; i<size; i++) {
		b[i] = a[i];
		// cout << "copying..." << endl;
	}
	delete [] a;
	a = NULL; // optional
	return b;
}

int main() {

	int size = 1;
	int * a = new int[size];

	int no;
	cin >> no;

	int i = 0;

	while(no > 0) {
		a[i++] = no;
		if(i == size) {
			// resize my array
			a = resize(a, size);
			size *= 2; // update the size after resize operation
		}
		cin >> no;
	}


	for(int j=0; j<i; j++) {
		cout << a[j] << " ";
	}

	cout << endl;

	delete [] a;

	a = NULL; //optional

	return 0;
}