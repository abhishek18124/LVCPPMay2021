
/*

Implementation of the circurlar queues using arrays.

*/

#include<iostream>

using namespace std;

class CircularQueue {
	int front;
	int rear;
	int capacity;
	int len;
	int* arr;

public:

	CircularQueue(int capacity = 8) {
		this->capacity = capacity + 1;
		this->arr = new int[capacity + 1];
		this->len = 0;
		this->front = this->rear = 0;
	}
	
	void push(int data) {
		if(front == (rear+1)%capacity) {
			// queue is full
		} else {
			rear = (rear+1)%capacity;
			arr[rear] = data;
			len++;
		}
	}

	void pop() {
		if(front == rear) {
			// queue is empty
		} else {
			front = (front+1)%capacity;
			len--;
		}
	}

	void print() {
		int temp = front;
		while(temp != rear) {
			temp = (temp + 1)%capacity;
			cout << arr[temp] << " ";
		}
		cout << endl;
	}

	int getFront() {
		return arr[(front+1)%capacity];
	}

	bool empty() {
		return front == rear;
	}

	int size() {
		return len;
	}

};

int main() {

	CircularQueue cq(4);

	cq.push(1);
	cq.push(2);
	cq.push(3);
	cq.push(4);

	cq.print();

	cout << "size = " << cq.size() << endl;

	cq.pop();
	cq.pop();

	cout << "size = " << cq.size() << endl;

	cq.print();

	cq.push(5);

	cout << "size = " << cq.size() << endl;
	
	cq.print();

	return 0;
}