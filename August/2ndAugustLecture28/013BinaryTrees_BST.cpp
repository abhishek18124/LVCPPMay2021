/*

Given a sorted array, design an algorithm to build a balanced BST.

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

node* buildBBST(int* arr, int s, int e) {
	if(s > e) {
		return NULL;
	}

	int m = s + (e-s)/2;
	node* root = new node(arr[m]);
	
	root->left  = buildBBST(arr, s, m-1);
	root->right = buildBBST(arr, m+1, e);
	
	return root;
}

int main() {

	int arr[] = {3, 5, 7, 10, 13, 15, 17};
	int n = sizeof(arr) / sizeof(int);

	node* root = NULL;

	root = buildBBST(arr, 0, n-1);

	levelOrder(root);
	
	return 0;
}


