/*

given the pre-order traversal of a binary tree, design a recursive algorithm to mirror it.

Example : Input  : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 10 30 60 -1 -1 -1 20 50 -1 70 -1 -1 40 -1 -1 

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


node* buildTree() {
	int x; 
	cin >> x;

	if(x == -1) {≈
		return NULL;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right= buildTree();

	return root;
}

void preorder(node* root) {
	if(root == NULL) {
		// root represents an empty tree
		cout << "-1 ";
		return;
	}

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void mirror(node* root) {
	if(root == NULL) {
		// root represents empty tree
		return;
	}

	mirror(root->left);
	mirror(root->right);
	swap(root->left, root->right);
}

int main() {

	node* root = NULL;

	root = buildTree();
	mirror(root);
	preorder(root); cout << endl;

	return 0;
}