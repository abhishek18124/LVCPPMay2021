/*

LinkedList 
----------

Length
 > iterative
 > recursive

Search
 > iterative
 > recursive
 
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

int lengthIterative(Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int lengthRecursive(Node* head) {

    if(head == NULL) {
        return 0;
    }

    return 1 + lengthRecursive(head->next);

}

bool searchIterative(Node* head, int key) {
    while(head != NULL) {
        if(head->data == key) {
            return true;
        }
        head = head->next;
    }
    return false;
}

bool searchRecursive(Node* head, int key) {
    if(head == NULL) {
        return false;
    }

    if(head->data == key) {
        return true;
    }

    return searchRecursive(head->next, key);
}


int main() {

    Node* head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    print(head);

    cout << lengthIterative(head) << endl;
    cout << lengthRecursive(head) << endl;
    searchIterative(head, 3) ? cout << "true" << endl : cout << "false" << endl;
    searchIterative(head, 7) ? cout << "true" << endl : cout << "false" << endl;
    searchRecursive(head, 2) ? cout << "true" << endl : cout << "false" << endl;
    searchRecursive(head, 7) ? cout << "true" << endl : cout << "false" << endl;
   
    return 0;
}




