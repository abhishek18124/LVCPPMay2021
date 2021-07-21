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

void insertAtHead(Node*& head, int data) {
	Node* n = new Node(data);
	n->next = head;
	head = n;
}

void print(Node* head) {
	while(head) {
		cout << head->data;
		head = head->next;
		if(head) cout << "->";
	}
	cout << endl;
}

int length(Node* head) {
	int count = 0;
	while(head) {
		count++;
		head = head->next;
	}
	return count;
}

Node* bubbleSort(Node* head) {

	int n = length(head);
	for(int i=0; i<n-1; i++) {
		int j = 0;
		Node* cur = head;
		Node* prev = NULL;
		Node* nxt = NULL;
		while(j < n-i-1 && cur != NULL && cur->next != NULL) {
			nxt = cur->next;
			if(cur->data > nxt->data) {
				// swap the cur node with the nxt node
				if(prev == NULL) {
					// change the head
					cur->next = nxt->next;
					nxt->next = cur;
					head = nxt;
					prev = nxt;
				} else {
					// don't change the head
					cur->next = nxt->next;
					nxt->next = cur;
					prev->next = nxt;
					prev = nxt;
				}
			} else {
				// don't swap
				prev = cur;
				cur = nxt;
			}

			j++;
		}
	}

	return head;

}

int main() {

	Node* head = NULL;

	insertAtHead(head, 1);
	insertAtHead(head, 2);
	insertAtHead(head, 3);
	insertAtHead(head, 4);
	insertAtHead(head, 5);

	print(head);

	head = bubbleSort(head);

	print(head);

	return 0;
}