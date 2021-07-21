/*

Write a program to check if there exists a cycle in a linked list or not.
If a cycle is found then remove it.

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


Node* getNode(Node* head, int index) {
    int i = 0;
    while(i < index && head != NULL) {
        head = head->next;
        i++;
    }

    return head;
}

Node* getTail(Node* head) {
    while(head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

bool detectCycle(Node* head) {
	Node* fast = head;
	Node* slow = head;

	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			return true;
		}
	}
	return false;
}

void removeCycle(Node* head) {
	// we will call this function when there is a cycle
	// and for a cycle you need atleast two nodes
	
	Node* fast = head;
	Node* slow = head;

	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			// slow and fast meet
			break;
		}
	}

	// maintain a prev pointer to be one step behind fast
	Node* prev = head;
	while(prev->next != fast) {
		prev = prev->next;
	}

	slow = head;
	while(slow != fast) {
		prev = prev->next;
		slow = slow->next;
		fast = fast->next;
	}

	// slow and fast are at the intersection point
	// prev is one step behind fast i.e. one step before intersection point

	// remove the cycle 
	prev->next = NULL;

}


void insertACycle(Node* head, int index) {
	// assume head is not NULL and index is valid
	Node* tail = getTail(head);
	Node* n = getNode(head, index);
	tail->next = n;
}


int main() {

	Node* head = NULL;

	insertAtHead(head, 1);
	insertAtHead(head, 2);
	insertAtHead(head, 3);
	insertAtHead(head, 4);
	insertAtHead(head, 5);

	print(head);

	insertACycle(head, 2);

	if(detectCycle(head)) {
		cout << "cycle found!" << endl;
		removeCycle(head);
		print(head);
	} else {
		cout << "cycle not found!" << endl;
		print(head);
	}

	return 0;
}