/*

Desing an algorithm to perform following operations on a BST

	1. Insertion
	2. Search
	3. Deletion

*/

#include<iostream>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};


void inorder(node* root) {
	if(root == NULL) {
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {

	Node* root = NULL;

	// build a BST

	// perform an inorder traversal on a BST
	
	inorder(root);

	// check if the given key is present in a BST or not

	int key;

	cin >> key;

	// if key is present in the BST, then delete it

	return 0;
}
