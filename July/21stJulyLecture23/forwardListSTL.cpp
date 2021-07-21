/*

	Forward List - STL implementation of singly linked list	

	How to create a forward_list ? 
		> use empty container constructor (default constructor)
		> use fill constructor
		> use range constructor
		> use copy constructor
		> use initialiser list (C++11)
	How to add elements to a forward_list ?
	    > use forward_list::push_front to add element at head (constant time operator)
	How to remove elements from a forward_list ?
	    > use forward_list::pop_front to remove element from the head (constant time operation)
	    > use forward_list::clear to remove all the elements from a forward_list
	How to check size of a forward_list ?
	    > forward_list is the only standard container to deliberately lack a size member function 
	      for efficiency considerations. To obtain the size of a forward_list object, you can use 
	      the distance algorithm with its begin and end, which is an operation that takes linear time.
		> use forward_list::max_size to know maximum number of elements that can added in a forward_list
	How to check if a forward_list is empty ?
	    > use forward_list::empty or check if forward_list size is 0
	How to access element at the front? 
	    > use forward_list::front 
	How to iterate over elements in a forward_list ?
	    > use an iterator

*/

#include<iostream>
#include<forward_list>
#include<iterator>

using namespace std;

int main() {

	// create an empty forward_list

	forward_list<int> l1;

	cout << "size = " << distance(l1.begin(), l1.end()) << endl;

	// insert data at the head 

	l1.push_front(3);
	l1.push_front(2);
	l1.push_front(1);
	l1.push_front(0);

	cout << "size = " << distance(l1.begin(), l1.end()) << endl;

	// access the element at the head
	cout << "head = " << l1.front() << endl;

	// iterate over the foward_list using iterator

	for(auto it = l1.begin(), end = l1.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	// iterate over the forward list using for-each loop

	for(int x : l1) {
		cout << x << " ";
	}

	cout << endl;

	// remove data at the head 

	l1.pop_front();
	l1.pop_front();

	cout << "size = " << distance(l1.begin(), l1.end()) << endl;

	// iterate over the foward_list using iterator

	for(auto it = l1.begin(), end = l1.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	// clear forward_list
	
	l1.clear();
	cout << "size = " << distance(l1.begin(), l1.end()) << endl;


	// check if list is empty
	cout << "is list empty ? " << l1.empty() << endl;

	// create a list using fill constructor

	forward_list<int> l2(3, 1); // creates a forward_list of size 3 all with values 0
	
	cout << "size = " << distance(l2.begin(), l2.end()) << endl;

	// iterate over the foward_list using iterator

	for(auto it = l2.begin(), end = l2.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	forward_list<int> l3(4); // creates a forward_list of size 4

	// create a list using initializer list
	forward_list<int> l4 = {1, 2, 3, 4, 5};
	cout << "size = " << distance(l4.begin(), l4.end()) << endl;

	// iterate over the foward_list using iterator

	for(auto it = l4.begin(), end = l4.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}



