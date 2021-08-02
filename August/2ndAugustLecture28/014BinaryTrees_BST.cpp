/*

Given a BST, design an algorithm transform it into a sorted linked list in-place.

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
	node* head;
	node* tail;
};

Pair sortedLinkedList(node* root) {
	Pair p;

	if(root == NULL) {
		p.head = p.tail = NULL;
		return p;
	}

	Pair pL = sortedLinkedList(root->left);

	if(pL.head != NULL) {
		pL.tail->right = root;
		p.head = pL.head;
	} else {
		p.head = root;
	}

	Pair pR = sortedLinkedList(root->right);

	if(pR.head != NULL) {
		root->right = pR.head;
		p.tail = pR.tail;
	} else {
		p.tail = root;
	}

	return p;
}

void printLinkedList(node* head) {
	while(head != NULL) {
		cout << head->data;
		head = head->right;
		if(head != NULL) cout << "->";
	}
	cout << endl;
}


int main() {

	// sample BST

	node* root = NULL;

	root = new node(10);
	
	root->left = new node(5);
	root->left->left  = new node(3);
	root->left->right = new node(7);

	root->right = new node(15);
	root->right->left  = new node(13);
	root->right->right = new node(17);

	Pair p = sortedLinkedList(root);

	printLinkedList(p.head);

	return 0;
}