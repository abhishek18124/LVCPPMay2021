/*

Find the mid-point of a linked list without computing the length of the linked list.

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
    // 1. create a node
    Node* n = new Node(data);
    // 2. assign the next of new node to head
    n->next = head; //  (*n).next = head; 
    // 3. reassign the head to new node
    head = n;
}


void deleteFromHead(Node*& head) {
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data; 
        head = head->next;
        if(head != NULL) cout << "->";
    }
    cout << endl;
}

Node* getMidPoint(Node* head){ 
    if(head == NULL) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next; // or fast = head (depends on question)

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}

int main() {

    Node* head = NULL;

    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    print(head);

    Node* midPoint = getMidPoint(head);

    if(midPoint != NULL) {
        cout << midPoint->data << endl;
    }



    return 0;
}



