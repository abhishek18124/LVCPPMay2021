
/*

Implementation of the queue data structure using the linked list data structure.

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
	node<T>* tail;
	int len;

public:

	forward_list() {
		head = NULL;
		tail = NULL;å
		len = 0;
	}å

	void push_back(T data) {
		// insert at tail
		node<T>* n = new node<T>(data);
		if(head == NULL) {
			head = tail = n;
			len++;
			return;
		}
		tail->next = n;
		tail = n;
		len++;
	}

	void pop_front() {
		if(head == NULL)  return;
		node<T>* temp = head;
		head = head->next;
		delete temp;
		len--; å
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
class queue {
	forward_list<T> l;

public:

	void push(T data) {
		l.push_back(data);
	}

	void pop() {
		l.pop_front();
	}

	T front() {
		return l.front();
	}

	int size() {
		return l.size();
	}

	bool empty() {
		return l.empty();
	}
};


int main() {

	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	cout << "size = " << q.size() << endl;

	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();	
	}

	cout << endl;

	cout << "size = " << q.size() << endl;

	q.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}


