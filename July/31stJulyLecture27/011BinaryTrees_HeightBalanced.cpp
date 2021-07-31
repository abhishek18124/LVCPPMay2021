
/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example 
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

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

int height(node* root) {
	if(root == NULL) {
		return -1;
	}

	int hL = height(root->left);
	int hR = height(root->right);

	return 1 + max(hL, hR);

}

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

bool isBalanced(node* root) {

	if(root == NULL) {
		return true;
	}

	int hL = height(root->left);
	int hR = height(root->right);

	if(abs(hL-hR) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
		return true;
	}

	return false;

}

class Pair {
public:
	int height;
	bool isBalanced;
};

Pair isBalancedEfficient(node* root) {
	Pair p;

	if(root == NULL) {
		p.height = -1;
		p.isBalanced = true;
		return p;
	}

	Pair pL = isBalancedEfficient(root->left);
	Pair pR = isBalancedEfficient(root->right);

	p.height = 1 + max(pL.height, pR.height);

	if(abs(pL.height - pR.height) <= 1 && pL.isBalanced && pR.isBalanced) {
		p.isBalanced = true;
	} else {
		p.isBalanced = false;
	}

	return p;

}


int main() {

	node* root = NULL;

	root = buildTree();

	// check if the binary tree is height balanced or not
		
	isBalanced(root) ? cout << "true" << endl : cout << "false" << endl;
 	isBalancedEfficient(root).isBalanced ? cout << "true" << endl : cout << "false" << endl;
 	
 	return 0;
 }