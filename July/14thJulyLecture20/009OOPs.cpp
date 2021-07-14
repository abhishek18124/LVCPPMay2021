/*

	1. Pointer to a class object
		> using the arrow (->) operator to dereference a object pointer to access public members
	2. Constructing a class object dynamically using the 'new' keyword
		> invoking default and parameterised constructor
		> don't forget to delete object pointer to de-allocate dynamic memory
	3. The 'this' keyword
	    > it a pointer to the current object present in the class by default
	    > check if object passed to a member function is current object itself

*/

#include<iostream>

using namespace std;

class  Customer {

	string name;
	double credits;

public:

		Customer() {
			cout << "\nInside Customer's default constructor\n";
		}
		
		Customer(string name, double credits) {
			cout << "\nInside Customer's parameterised constructor\n";
			this->name = name;
			this->credits = credits;
		}

		Customer(Customer& c) {
			cout << "\nInside Customer's copy constructor\n";
			name = c.name;
			credits = c.credits;
		}

		void operator=(Customer& c) {
			cout << "\nInside Customer's copy assignment operator function\n";
			name = c.name;
			credits = c.credits;
		}

		void printInfo() {
			cout << "\nCustomer Info\n";
			cout << "Name :" << name << endl;
			cout << "Credits :" << credits << endl;
 		}

 		void setName(string name) {
 			this->name = name;
 		}

 		void setCredits(double credits) {
 			this->credits = credits;
 		}

 		string getName() {
 			return name;
 		}

 		double getCredits() {
 			return credits;
 		}

 		~Customer() {
 			cout << "\nInside " << name << "'s destructor\n";
 		}

 		bool isCurrentObject(Customer *cptr) {
 			return this == cptr;
 		}
};


int main() {

	Customer c("Ned", 10.0);

	Customer* cptr = &c;

	cptr->printInfo(); // (*cptr).printInfo();

	// Dynamically allocate memory

	Customer* ptr = new Customer; // invokes the default constructor

	delete ptr; // without it destructor won't be invoked

	ptr = NULL; // for safety

	ptr = new Customer{"Alex", 200.0}; // invokes parameterised constructor

	ptr->printInfo();

	delete ptr;

	ptr = NULL; // for safety


	Customer c2("Shawn", 20);

	c2.printInfo();

	c2.isCurrentObject(&c2) ? cout << "Yes, same object is passed!" << endl: cout << "No, different object" << endl;
    c2.isCurrentObject(&c) ? cout << "Yes, same object is passed!" << endl: cout << "No, different object" << endl;


	return 0;
}
