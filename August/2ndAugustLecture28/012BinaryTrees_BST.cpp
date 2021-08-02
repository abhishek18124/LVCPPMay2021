/*

Desing an algorithm to perform each of the following operations on a BST

	1. Insertion into a BST
	2. Print data within a given range in sorted manner
	3. Find the minimum and maximum data present in a BST
	4. Search for a key in a BST
	5. Deletion in a BST

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


void inorder(node* root) {
	if(root == NULL) {
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

node* insertInBST(node*& root, int data) {
	if(root == NULL) {
		// root represent an empty BST
		root = new node(data);
		return root;
	}

	if(data <= root->data) {
		// insert node with the given data in the LST which is also a BST 
		root->left = insertInBST(root->left, data);
	} else {
		// insert node with the given data in the RST which is also BST
		root->right = insertInBST(root->right, data);
	}

	return root;
}


node* buildBST() {

	node* root = NULL;

	int data;
	cin >> data;

	while(data != -1) {
		root = insertInBST(root, data);
		cin >> data;
	}

	return root;
}

void range(node* root, int s, int e) {
	if(root == NULL) {
		return;
	}

	range(root->left, s, e);
	
	if(root->data >= s && root->data <= e) {
		cout << root->data << " ";
	}

	range(root->right, s, e);
}

node* findMin(node* root) {

	while(root != NULL && root->left != NULL) {
		root = root->left;
	}
	// at this point, root points to the left-most node in the BST
	// i.e. the node with the minimum data

	return root;
}

node* findMax(node* root) {

	while(root != NULL && root->right != NULL) {
		root = root->right;
	}
	// at this point, root points to the right-most node in the BST
	// i.e. the node with the maximum data

	return root;
}

bool search(node* root, int key) {
	if(root == NULL) {
		// root represens an empty tree
		return false;
	}

	if(root->data == key) {
		return true;	
	} else if(key < root->data) {
		return search(root->left, key);
	} else {
		return search(root->right, key);
	}

}

node* del(node* root, int key) {
	if(root == NULL) {
		// root represents an empty
		return root;
	}

	if(key < root->data) {
		root->left = del(root->left, key);
		return root;
	} else if(key > root->data) {
		root->right= del(root->right, key);
		return root;
	} else {
		// you're at a node whose data matches the key
		if(root->left == NULL && root->right == NULL) {
			// you want to delete a node with no child nodes
			delete root;
			return NULL;
		} else {
			// you want to delete a node with children
			if(root->left != NULL && root->right == NULL) {
				// you want to delete a node with only a left child
				node* temp = root->left;
				delete root;
				return temp;
			} else if(root->left == NULL && root->right != NULL) {
				// you want to delete a node with only a right child
				node* temp = root->right;
				delete root;
				return temp;
			} else {
				// you want to delete a node with two child nodes;
				node* replace = findMax(root->left); // or node* replace = findMin(root->right);
				swap(root->data, replace->data);
				root->left = del(root->left, replace->data); // or root->right = del(root->right, replace->data)
				return root;
			}
		}

	}
}

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

int main() {

	node* root = NULL;

	// build a BST
	root = buildBST();
	
	// traverse the BST using inorder traversal
	cout << "inorder = ";
	inorder(root);
	cout << endl;
	
	// // print data in a BST in the given range [s, e] in sorted manner
	// int s, e;
	
	// cout << "s >> ";
	// cin >> s;
	// cout << "e >> ";
	// cin >> e;

	// cout << "range[" << s << ", " << e << "] = ";
	// range(root, s, e);
	// cout << endl;

	// // find min and max data in the BST
	// node* minNode = findMin(root);
	// minNode != NULL ? cout << "min data = " << minNode->data << endl : cout << "BST is empty!" << endl;

	// node* maxNode = findMax(root);
	// maxNode != NULL ? cout << "max data = " << maxNode->data << endl : cout << "BST is empty!" << endl;

	// check if there exists a node in the BST with the given key or not
	int key;
	cout << "key >> ";
	cin >> key;

	// search(root, key) ? cout << "found!" << endl : cout << "not found!" << endl;

	// delete a node in the BST with the given key
	del(root, key);

	// traverse the BST using inorder traversal
	inorder(root); cout << endl << endl;

	levelOrder(root); cout << endl;
	
	return 0;
}
