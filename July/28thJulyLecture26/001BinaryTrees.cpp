/*

given a binary tree, design a recursive algorithm to perform following traversals
	> pre-order
	> in-order
	> post-order
*/

#include<iostream>

using namespace std;

template <typename T>
class node {
public:
	T data;
	node<T>* left;
	node<T>* right;

	node(T data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

template <typename T>
void preorder(node<T>* root) {
	if(root == NULL) {
		// root represent an empty
		cout << "-1 ";
		return;
	}

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}


template <typename T>
void inorder(node<T>* root) {
	if(root == NULL) {
		// root represent an empty
		cout << "-1 ";
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}


template <typename T>
void postorder(node<T>* root) {
	if(root == NULL) {
		// root represent an empty
		cout << "-1 ";
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
	
}

int main() {

	node<int>* root = NULL; // tree is initially empty

	root = new node<int>(10);
	root->left = new node<int>(20);
	root->right = new node<int>(30);
	root->left->left = new node<int>(40);
	root->left->right = new node<int>(50);
	root->right->right = new node<int>(60);
	root->left->right->left = new node<int>(70);

	preorder(root);  cout << endl;
	inorder(root);   cout << endl;
	postorder(root); cout << endl;
	
	return 0;
}








