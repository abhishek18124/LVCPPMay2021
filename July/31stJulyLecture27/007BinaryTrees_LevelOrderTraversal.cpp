/*

given the pre-order traversal of a binary tree, output its level-order traversal.

Example 
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: 10 20 30 40 50 60 70
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

void levelOrder(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		node* front = q.front(); q.pop();
		if(front == NULL) {
			// you've visited a level, so print a new line
			cout << endl;
			// you've visited a level, that also means you've seen all the children of the next level
			if(!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->data << " ";
			if(front->left != NULL) q.push(front->left);
			if(front->right!= NULL) q.push(front->right);
		}
	}
	cout << endl;
}

int main() {

	node* root = NULL;

	root = buildTree();

	// perform the level-order traversal of the binary tree
	levelOrder(root);

	return 0;
}

