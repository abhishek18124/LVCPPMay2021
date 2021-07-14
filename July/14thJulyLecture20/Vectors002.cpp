/*
	
	Vectors Part II
	
	How to create a vector ? 
		> use fill constructor
		> use range constructor
		> use copy constructor
		> use initialiser list (C++11)
	How to add elements to a vector ?
	    > use vector::insert
	      > single element
	      > fill
	      > range
	      > initialiser list
	How to remove elements from a vector ?
	    > use vector::erase
	      > single element
	      > range

	How to sort a vector ?
      > use built-in comparator
      > use user-defined comparator
      > pass in reverse order

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	vector<int> v1(4, 100); // parameterised constructor a.k.a fill constructor

	for(int i=0; i<v1.size(); i++) {
		cout << v1[i] << " "; 
	}

	cout << endl;


	vector<int> v2(3); // parameterised constructor a.k.a fill constructor

	v2[0] = 0;
	v2[1] = 1;
	v2[2] = 2;

	for(int i=0; i<v2.size(); i++) {
		cout << v2[i] << " ";
	}

	cout << endl;

	vector<int> v3(v2); // copy constructor
	for(int i=0; i<v3.size(); i++) {
		cout << v3[i] << " ";
	}

	cout << endl;

	vector<int> v4 = v1; // copy constructor
	for(int i=0; i<v4.size(); i++) {
		cout << v4[i] << " ";
	}

	cout << endl;

	vector<int> v5; // default constructor
	v5 = v1; // copy assignment operator

	for(int i=0; i<v5.size(); i++) {
		cout << v5[i] << " ";
	}

	cout << endl;

	vector<int> v6 = {9, 8, 7}; // initialiser list

	for(int i=0; i<v6.size(); i++) {
		cout << v6[i] << " ";
	}

	cout << endl;

	// range constructor

	vector<int> v7(v6.begin(), v6.end()); // [ v6.begin(), v6.end() )

	for(int i=0; i<v7.size(); i++) {
		cout << v7[i] << " ";
	}

	cout << endl;

	int arr[] = {3, 2, 1};
	vector<int> v8(arr, arr+3);
	for(int i=0; i<v8.size(); i++) {
		cout << v8[i] << " ";
	}

	cout << endl;

	sort(v8.begin(), v8.end()); // sort the vector

	for(int i=0; i<v8.size(); i++) {
		cout << v8[i] << " ";
	}

	cout << endl;

	vector<int> v9 = {10, 20, 30};

	sort(v9.rbegin(), v9.rend());

	for(int i=0; i<v9.size(); i++) {
		cout << v9[i] << " ";
	}

	cout << endl;

	vector<int> v10 = {100, 200, 300};

	sort(v10.begin(), v10.end(), greater<int>());

	for(int i=0; i<v10.size(); i++) {
		cout << v10[i] << " ";
	}

	cout << endl;

	return 0;
}






