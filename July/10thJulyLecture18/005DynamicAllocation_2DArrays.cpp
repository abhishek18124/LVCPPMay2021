/*

1. Use the following syntax to dynamically create 2D arrays to store integers
		
		int** a = new int*[rows];
		for(int i=0; i<rows; i++) {
			a[i] = new int[cols];
		}

2. Use the following syntax to free dynamically created 2D array

   > First free space for each row

   	 for(int i=0; i<row; i++) {
		delete[] a[i];
   	 } 

   > Then, free space for array of pointers

   	 delete[] a;

   > Don't forget to set pointer to NULL

     a = NULL;

   
*/

#include<iostream>

using namespace std;

int main() {

	int m;
	cin >> m;

	int n;
	cin >> n;

	int** ptr = new int*[m]; // creates an array of pointers to integer
	for(int i=0; i<m; i++) {
		ptr[i] = new int[n];
	}

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> ptr[i][j];
		}
	}

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}

	for(int i=0; i<m; i++) {
		delete [] ptr[i];
	}

	delete[] ptr;

	ptr = NULL;

	return 0;	
}














