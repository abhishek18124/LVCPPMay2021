/*

Implementation of the stack data structure using the linked list data structure.

*/

#include<iostream>

using namespace std;

template <typename T>
class node {
public:
	T data;
	node<T>* next;

	node(T data) {
		this->data = data;
		this->next = NULL;
	}
};

template <typename T>
class forward_list {
	node<T>* head;
	int len;

public:

	forward_list() {
		head = NULL;
		len = 0;
	}

	void push_front(T data) {
		// insert at the head
		node<T>* n = new node<T>(data);
		n->next = head;
		head = n;
		len++;
	}

	void pop_front() {
		// delete from the head
		if(head == NULL) return;
		node<T>* temp = head;
		head = head->next;
		delete temp;
		len--;
	}

	T front() {
		return head->data;
	}

	int size() {
		return len;
	}

	bool empty() {
		return head == NULL;
	}

};

template <typename T>
class stack {
	forward_list<T> l;

public: 

	void push(T data) {
		l.push_front(data);
	}

	void pop() {
		l.pop_front();
	}

	T top() {
		return l.front();
	}

	bool empty() {
		return l.empty();
	}

	int size() {
		return l.size();
	}

};

int main() {


	stack<char> s;

	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	s.push('e');

	cout << "size = " << s.size() << endl;

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	cout << endl;

	cout << "size = " << s.size() << endl;

	s.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}


