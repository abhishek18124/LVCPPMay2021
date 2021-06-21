#include<iostream>

using namespace std;

int add(int a, int b, int c=0) {
	cout << "inside int fn " << endl;
	return a+b+c;
}

int add(double a, double b, int c=0) {
	cout << "inside float fn" << endl;
	return a+b+c;
}

int main() {
	
	// cout << add(10, 20, 30, 40) << endl;
	// cout << add(10, 20, 30) << endl;
	// cout << add(10, 20) << endl;

	cout << add(10, 20) << endl; 
	cout << add(12.78, 19.7) << endl;

	return 0;
}