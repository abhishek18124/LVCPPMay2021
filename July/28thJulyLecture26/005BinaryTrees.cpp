/*

given the pre-order traversal of a binary tree, design a recursive algorithm to compute 
its diameter

	  diameter of a binary tree is the length of the longest path between any 
	  two nodes in the binary tree.

Example : Input  : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : 5

          Input  : 10 20 30 50 -1 -1 -1 40 -1 60 -1 -1 70 -1 -1
          Output : 4
          
          Input  : 10 20 -1 -1 30 40 60 -1 -1 -1 50 -1 70 -1 -1
          Output :4
          
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

class Pair {
public:
	int height;
	int diameter;
};


node* buildTree() {
	int x; 
	cin >> x;

	if(x == -1) {
		// x == -1 presents an empty tree
		return NULL;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right= buildTree();

	return root;
}

int height(node* root) {
	if(root == NULL) {
		// root represents an empty tree
		return -1;
	}

	int hL = height(root->left);
	int hR = height(root->right);
	return 1 + max(hL, hR);
}

int diameter(node* root) {

	if(root == NULL) {
		// root represents an empty tree
		return 0;
	}

	int dL = diameter(root->left);
	int dR = diameter(root->right);
	
	int hL = height(root->left);
	int hR = height(root->right);

	return max(hL+hR+2, max(dL, dR));
}

pair<int, int> diameterEfficientWithBuiltInPair(node* root) {
	pair<int, int> p;

	if(root == NULL) {
		// root represents an empty tree
		p.first = -1;
		p.second = 0;
		return p;
	}

	pair<int, int> pL = diameterEfficientWithBuiltInPair(root->left);
	pair<int, int> pR = diameterEfficientWithBuiltInPair(root->right);

	p.first = 1 + max(pL.first, pR.first);
	p.second = max(2+pL.first+pR.first, max(pL.second, pR.second));

	return p;
}


Pair diameterEfficient(node* root) {
	Pair p;

	if(root == NULL) {
		// root represents an empty tree
		p.height = -1;
		p.diameter = 0;
		return p;
	}

	Pair pL = diameterEfficient(root->left);
	Pair pR = diameterEfficient(root->right);

	p.height = 1 + max(pL.height, pR.height);
	p.diameter = max(2+pL.height+pR.height, max(pL.diameter, pR.diameter));

	return p;
}

int main() {

	node* root = NULL;

	root = buildTree();

	cout << "diameter = " << diameter(root) << endl;
	cout << "diameter = " << diameterEfficient(root).diameter << endl;
	cout << "diameter = " << diameterEfficientWithBuiltInPair(root).second << endl;

	return 0;
}

