/*

How to

1. declare 2D integer arrays
2. initialize 2D integer arays
3. initialize 2D integer arrays with user input
4. print 2D integers

*/
#include<iostream>

using namespace std;

void printRow(int* ptr) {
	for(int j=0; j<3; j++) {
		cout << ptr[j] << " ";
	}
}

int main() {

	#ifndef IO
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int a[][3] = {{10, 20, 30},
				  {40, 50, 60}};

	// row-wise
	for(int i=0; i<2; i++) {
		for(int j=0; j<3; j++) {
			cout << a[i][j] << " ";
		}
		// printRow(a[i]);
		cout << endl;
	}

	cout << endl << endl;

	// column-wise
	for(int j=0; j<3; j++) {
		for(int i=0; i<2; i++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}


	// int b[][3] = {{10, 20, 30},
	// 			  {40, 50, 60},
	// 			  {70, 80, 90}};

	// cout << "Address of 0th element in 0th row = " << b[0] << " or " << &b[0][0] << endl; 
	// cout << "Address of 0th element in 1st row = " << b[1] << " or " << &b[1][0] << endl; 
	// cout << "Address of 0th element in 2nd row = " << b[2] << " or " << &b[2][0] << endl; 

	// cout << "Address of 0th and 1st element in 0th row = " << b[0] << " " << b[0]+1 << endl; 
	// cout << "Address of 0th and 1st element in 1st row = " << b[1] << " " << b[1]+1<< endl; 
	// cout << "Address of 0th and 1st element in 2nd row = " << b[2] << " " << b[2]+1<< endl; 

	// cout << "b =  " << b << " b+1 = " << b+1 << endl;

	cout << endl << endl;

	// int c[3][4];
	// for(int i=0; i<3; i++) {
	// 	for(int j=0; j<4; j++) {
	// 		cin >> c[i][j];
	// 	}
	// }

	// for(int i=0; i<3; i++) {
	// 	for(int j=0; j<4; j++) {
	// 		cout << c[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int m, n;
	cin >> m >> n;

	int d[10][10];
	int no = 1;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			d[i][j] = no;
			no++;
		}
	}

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}