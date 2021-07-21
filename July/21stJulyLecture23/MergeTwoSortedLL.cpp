/*

Write a program to merge two sorted linked list.

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

Node* merge(Node* head1, Node* head2) {

	// base cases
	if(head1 == NULL) {
		return head2;
	}

	if(head2 == NULL) {
		return head1;

	}

	// recursive case
	Node* head = NULL;

	if(head1->data < head2->data)  {
		// head1 becomes the head of the merged linked list
		head = head1;
		head->next = merge(head1->next, head2);
	} else {
		// head2 becomes the head of the merged linked list
		head = head2;
		head->next = merge(head1, head2->next);
	}

	return head;
}

int main() {

	Node* head1 = NULL;

	insertAtHead(head1, 7);
	insertAtHead(head1, 5);
	insertAtHead(head1, 3);
	insertAtHead(head1, 1);

	print(head1);

	Node* head2 = NULL;

	insertAtHead(head2, 8);
	insertAtHead(head2, 6);
	insertAtHead(head2, 4);
	insertAtHead(head2, 2);

	print(head2);

	Node* head = merge(head1, head2);

	print(head);

	return 0;
}