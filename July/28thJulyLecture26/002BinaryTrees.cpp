/*

design a recursive algorithm to build a binary tree given its pre-order traversal.

eg: 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1

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

void inorder(node* root) {
	if(root == NULL) {
		// root represents an empty tree
		cout << "-1 ";
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(node* root) {
	if(root == NULL) {
		// root represents an empty tree
		cout << "-1 ";
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
	
}

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

int main() {

	node* root = NULL;
£
	root = buildTree();

	preorder(root);  cout << endl;
	inorder(root); cout << endl;
	postorder(root); cout << endl;

	return 0;
}


