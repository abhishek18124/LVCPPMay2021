/*

LinkedList 
----------

Insert
 > at the head 
 > at the tail 
 > at an index 

Delete 
 > from the head
 > from the tail
 > fraom an index

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

Node* getNode(Node* head, int index) {
    int i = 0;
    while(i < index && head != NULL) {
        head = head->next;
        i++;
    }

    return head;
}

void insertAtIndex(Node*& head int data, int index) {
    if(index == 0) {
        insertAtHead(head, data);
        return;
    }
    if(index < 0) {
        // index cannot be negative
        return;
    }
    Node* prev = getNode(head, index-1);
    if(prev == NULL) {
        // user has given an index greater than the length of the linked list.
        return;   
    }
    Node* n = new Node(data);
    n->next = prev->next;
    prev->next = n;
}

Node* getTail(Node* head) {
    while(head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

void insertAtTail(Node*& head, int data) {
    if(head == NULL) {
        insertAtHead(head, data);
        return;
    }

    Node* tail = getTail(head); // O(N)
    Node* n = new Node(data);
    tail->next = n;
}

void deleteFromHead(Node*& head) {
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromIndex(Node*& head, int index) {
    if(index == 0) {
        deleteFromHead(head);
        return;
    } else if(index < 0) {
        // index cannot be negative
        return;
    }

    Node* cur = getNode(head, index);
    if(cur == NULL) {
        // index is greater equal to the length of the linked list
        return;
    }
    Node* prev = getNode(head, index-1);
    prev->next = cur->next;
    delete cur;
} 



void print(Node* head) {
    while(head != NULL) {
        cout << head->data; 
        head = head->next;
        if(head != NULL) cout << "->";
    }
    cout << endl;
}

void deleteFromTail(Node*& head) {
    if(head == NULL) {
        return;
    } else if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* prev = NULL;
    Node* tail = head;

    while(tail->next != NULL) {
        prev = tail;
        tail = tail->next;
    }

    prev->next = NULL;
    delete tail;
}


int main() {

    Node* head = NULL;
    Node* tail = NULL:

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    print(head);

    insertAtIndex(head, 3, 2);

    print(head);

    insertAtIndex(head, 6, 10);

    print(head);

    insertAtIndex(head, 6, 5);

    print(head);

    insertAtIndex(head, 0, 0);

    print(head);

    insertAtIndex(head, 8, -1);

    print(head);

    insertAtTail(head, 7);
    insertAtTail(head, 8);

    print(head);

    deleteFromHead(head);
    deleteFromHead(head);

    print(head);

    deleteFromIndex(head, 2);

    print(head);

    deleteFromTail(head);
    deleteFromTail(head);
    deleteFromTail(head);
    deleteFromTail(head);
    deleteFromTail(head);
    deleteFromTail(head);
    deleteFromTail(head);

    print(head);

    return 0;
}



