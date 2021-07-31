/*

given the in-order & pre-order traversal of a binary tree, design an algorithm to construct 
a binary tree from it.

Example 
	Input: pre[] = {10, 20, 40, 50, 70, 30, 60}
	       in[]  = {40, 20, 70, 50, 10, 30, 60}

*/

#include<iostream>
#include<queue>

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

void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		node* front = q.front(); q.pop();
		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->data << " ";
			if(front->left) q.push(front->left);
			if(front->right)q.push(front->right);
		}
	}

}

void preorder(node* root) {
	if(root == NULL) {
		// root represents an empty tree
		return;
	}

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}


void inorder(node* root) {
	if(root == NULL) {
		// root represents an empty tree
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

node* buildTree(int* pre, int& i, int* in, int s, int e) {
	if(s > e) {
		return NULL;
	}

	int rootData = pre[i]; i++;

	node* root = new node(rootData);
	int k = -1;
	for(int j=s; j<=e; j++) {
		if(in[j] == rootData) {
			k = j;
			break;
		}
	}

	root->left = buildTree(pre, i, in, s, k-1);
	root->right= buildTree(pre, i, in, k+1, e);

	return root;

}


int main() {

	
	node* root = NULL;

	int pre[] = {10, 20, 40, 50, 70, 30, 60};
	int in[]  = {40, 20, 70, 50, 10, 30, 60};
	int n = sizeof(in) / sizeof(int);

	// build the binary tree from the pre-order and in-order traversal

	int s = 0;
	int e = n-1;

	int i = 0;

	root = buildTree(pre, i, in, s, e);

	preorder(root); cout << endl;
	inorder(root);  cout << endl;
	levelOrder(root); cout << endl;

	return 0;
}

