/*

Given a binary tree, design an algorithm to check if the given tree is a BST or not.

*/

#include<iostream>
#include<climits>

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


int findMax(node* root) {
	if(root == NULL) {
		return INT_MIN;
	}

	while(root->right != NULL) {
		root = root->right;
	}

	return root->data;
}

int findMin(node* root) {
	if(root == NULL) {
		return INT_MAX;
	}

	while(root->left != NULL) {
		root = root->left;
	}

	return root->data;
}

class Triple {
public:
	int minData;
	int maxData;
	bool bst;
};

bool isBST(node* root) {

	if(root == NULL) {
		// root represents an empty tree
		return true;
	}

	int leftMax = findMax(root->left);
	int rightMin= findMin(root->right);

	if(leftMax <= root->data && root->data < rightMin 
		&& isBST(root->left) 
		&& isBST(root->right)) {
		return true;
	}

	return false;

}

Triple isBSTEfficient(node* root) {

	Triple t;

	if(root == NULL) {
		t.bst = true;
		t.minData = INT_MAX;
		t.maxData = INT_MIN;
		return t;
	}

	Triple tL = isBSTEfficient(root->left);
	Triple tR = isBSTEfficient(root->right);

	if(tL.maxData <= root->data && root->data < tR.minData
		&& tL.bst
		&& tR.bst) {
		t.bst = true;
	} else {
		t.bst = false;
	}

	t.minData = min(root->data, min(tL.minData, tR.minData));
	t.maxData = max(root->data, max(tL.maxData, tR.maxData));

	return t;
}

bool isBSTEfficientV2(node* root, int minData, int maxData) {
	if(root == NULL) {
		return true;
	}

	if(minData < root->data && root->data <= maxData 
		&& isBSTEfficientV2(root->left, minData, root->data)
		&& isBSTEfficientV2(root->right,root->data, maxData)) {
			return true;
		}

	return false;

}

int main() {

	// sample BT

	node* root = NULL;

	root = new node(1);
	
	root->left = new node(1);
	// root->left->left  = new node(3);
	// root->left->right = new node(7);

	// root->right = new node(15);
	// root->right->left  = new node(13);
	// root->right->right = new node(17);

	isBST(root) ? cout << "true" << endl : cout << "false" << endl;
	isBSTEfficient(root).bst ? cout << "true" << endl : cout << "false" << endl;
	isBSTEfficientV2(root, INT_MIN, INT_MAX) ? cout << "true" << endl : cout << "false" << endl;
	
	return 0;
}