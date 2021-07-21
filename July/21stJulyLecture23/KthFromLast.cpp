/*

Write a program to find the kth node from last in a linked list.

*/

#include<iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

void insertAtHead(Node*& head, int data) {
	Node* n = new Node(data);
	n->next = head;
	head = n;
}

void print(Node* head) {
	while(head != NULL) {
		cout << head->data;
		head = head->next;
		if(head != NULL) cout << "->";
	}
	cout << endl;
}

Node* kthFromLast(Node* head, int k) {
	Node* slow = head;
	Node* fast = head;

	// move the fast pointer k steps forward
	int i = 0;
	while(i < k && fast != NULL) {
		fast = fast->next;
		i++;
	}

	// move the slow and fast pointers one step at a time till fast becomes null
	while(fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;



}

int main() {

	Node* head = NULL;

	insertAtHead(head, 21);
	insertAtHead(head, 23);
	insertAtHead(head, 13);
	insertAtHead(head, 44);
	insertAtHead(head, 51);

	print(head);

	int k = 2;

	Node* n = kthFromLast(head, k);

	n ? cout << n->data << endl : cout << "n is NULL !" << endl;

	return 0;
}