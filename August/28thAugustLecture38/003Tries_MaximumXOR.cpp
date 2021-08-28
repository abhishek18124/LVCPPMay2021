/*

Given an array of non-negative integers of size n, find the maximum possible XOR between 
any two numbers present in the array.

Example: 
	Input : A[] = {25, 10, 2, 8, 5} 
	Output: 28 
	Explanation: The maximum result is 5 ^ 25 = 28 
	
	Input: A[] = {1, 2, 3, 4, 5, 6, 7} 
	Output: 7 
	Explanation: The maximum result is 1 ^ 6 = 7 

*/

#include<iostream>

using namespace std;

class node {
public:
	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1
	
	node() {
		this->left = NULL;
		this->right= NULL;
	}
};

class trie {
	node* root;
public:
	trie() {
		root = new node();
	}

	void insert(int x) {
		node* temp = root;
		for(int i=31; i>=0; i--) {
			int bit = (1<<i)&x;
			if(!bit) {
				// ith bit of x is 0, check if temp node has a left child or not
				if(!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				// ith bit of x is 1, check if temp node has a right child or not
				if(!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	int helper(int x) {
		int XOR = 0; // to store the maximum possible XOR between x & nos. inside the Trie
		node* temp = root;
		int y = 0;
		for(int i=31; i>=0; i--) {
			int bit = (1<<i) & x;
			if(!bit) {
				// ith bit is 0 then,
				// to maximise XOR, check if temp node has a right child i.e. bit 1
				if(temp->right) {
					// temp node has a right child
					XOR += (1<<i); 
					y += (1<<i);
					temp = temp->right;
				} else {
					// temp node do not have a right child
					temp = temp->left;
				}
			} else { 
				// ith bit is 1
				// then, to maximise XOR, check if temp node has a left child i.e. bit 0
				if(temp->left) {
					// temp node has a left child
					XOR += (1<<i);
					temp = temp->left;
				} else {
					// temp node do not have a left child
					temp = temp->right;
					y += (1<<i);
				}
			}
		}

		cout << x << "^" << y << " = " << XOR << endl;

		return XOR;
	}

	int maximumXOR(int* A, int n) {
		int finalAns = 0;
		for(int i=0; i<n; i++) {
			insert(A[i]);
			finalAns = max(finalAns, helper(A[i]));
		}
		return finalAns;
	}
};

int main() {

	int A[] = {25, 10, 2, 8, 5};
	int n = sizeof(A) / sizeof(int);

	trie t;
	// for(int i=0; i<n; i++) {
	// 	t.insert(A[i]);
	// }

	cout << t.maximumXOR(A, n) << endl;

	return 0;
}



