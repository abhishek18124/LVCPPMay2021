/*

Write a program to sort a linked list using the merge sort algorithm.

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

Node* insertAtHead(Node* head, int data) {
	Node* n = new Node(data);
	n->next = head;
	head = n;
	return head;
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

	if(head1 == NULL) {
		return head2;
	} 

	if(head2 == NULL) {
		return head1;
	}

	Node* head = NULL;
	if(head1->data < head2->data) {
		head = head1;
		head->next = merge(head1->next, head2);
	} else {
		head = head2;
		head->next = merge(head1, head2->next);
	}
	return head;

}

Node* getMidPoint(Node* head) {
	if(head == NULL) {
		return head;
	}

	Node* slow = head;
	Node* fast = head->next;

	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

Node* mergeSort(Node* head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}

	Node* mid = getMidPoint(head);
	Node* head1 = head;
	Node* head2 = mid->next;
	mid->next = NULL;

	head1 = mergeSort(head1);
	head2 = mergeSort(head2);

	head = merge(head1, head2);
	return head;
}

int main() {

	Node* head = NULL;

	head = insertAtHead(head, 1);
	head = insertAtHead(head, 2);
	head = insertAtHead(head, 3);
	head = insertAtHead(head, 4);
	head = insertAtHead(head, 5);

	print(head);

	head = mergeSort(head);

	print(head);

	return 0;
}