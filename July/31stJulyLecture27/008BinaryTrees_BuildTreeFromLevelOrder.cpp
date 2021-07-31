/*

given the level order traversal of a binary tree, design an algorithm to construct a 
binary tree from it.

Example 
	Input: 10 20 30 40 50 -1 60 -1 -1 70 -1 -1 -1 -1 -1
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

void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.emtpy()) {
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

node* buildTree() {
	
	int x;
	cin >> x;

	node* root = new node(x);
	queue<node*> q;
	q.push(root);

	while(!q.empty()) {
		int leftData, rightData;
		cin >> leftData >> rightData;

		node* front = q.front(); q.pop();

		if(leftData != -1) {
			front->left = new node(leftData);
			q.push(front->left);
		} 

		if(rightData != -1) {
			front->right = new node(rightData);
			q.push(front->right);
		}
	}
	return root;
}


int main() {

	node* root = NULL;

	// build a binary tree from the level-order traversal
	root = buildTree();

	levelOrder(root);

	return 0;
}