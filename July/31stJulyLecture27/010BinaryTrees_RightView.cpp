
/*

given the pre-order traversal of a binary tree, output its right view.

Example 
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: 10 30 50 70
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

	if(x == -1) {
		node* root = NULL;
		// root represents an empty tree
		return root;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right=buildTree();

	return root;
}

void rightView(node* root, int level, int& max_level) {

	if(root == NULL) {
		return;
	}

	if(max_level < level) {
		cout << root->data << " ";
		max_level = level;	
	}

	rightView(root->right, level+1, max_level);
	rightView(root->left, level+1,  max_level);
}


int main() {

	node* root = NULL;

	root = buildTree();

	// print the right view of the binary tree
	int max_level = -1;
	rightView(root, 0, max_level);
	
	return 0;
}