/*

given the pre-order traversal of a binary tree, design a recursive algorithm to compute
    
    > number of nodes
	> sum of nodes
 
Example : Input  :10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
          Output : # = 7, sum = 280
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
		// root represent an empty tree
		return root;
	}

	node* root  = new node(x);
	root->left  = buildTree();
	root->right = buildTree();

	return root;

}

int numOfNodes(node* root) {

	if(root == NULL) {
		return 0;
	}

	int nL = numOfNodes(root->left);
	int nR = numOfNodes(root->right);

	return nL + nR + 1;
}

int sumOfNodes(node* root) {

	if(root == NULL) {
		return 0;
	}

	int sL = sumOfNodes(root->left);
	int sR = sumOfNodes(root->right);

	return sL + sR + root->data;
}

int main() {

	node* root = NULL;

	root = buildTree();

	cout << "num = " << numOfNodes(root) << endl;
	cout << "sum = " << sumOfNodes(root) << endl;

	return 0;
}

