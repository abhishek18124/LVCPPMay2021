/*

Write a program to reverse a linked list.

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

void reverse(Node*& head) {

	Node* cur = head;
	Node* prev = NULL;
	Node* temp = NULL;

	while(cur != NULL) {
		temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	head = prev;
}

int main() {

	Node* head = NULL;

	insertAtHead(head, 1);
	insertAtHead(head, 2);
	insertAtHead(head, 3);
	insertAtHead(head, 4);
	insertAtHead(head, 5);

	print(head);

	reverse(head);

	print(head);

	return 0;
}