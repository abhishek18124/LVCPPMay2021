/*

	1. Const class members
	   > const data members : can only be initialized using member initialization
	   > const member functions :
	     > they cannot change the state of an object, can only modify static data members
	     > they cannot call non-const member functions

	2. Const class objects
	   > data members are read only
	   > can only call const member function
	   > call to constructor (non-const member fn) is allowed
	
	3. Non-Const objects can call both const and non-const member function

*/

#include<iostream>

using namespace std;

class  Customer {

	string name;
	double credits;
	static int counter;
	const int id;

public:

		Customer(string name, double credits, int id) : id(id) {
			cout << "\nInside Customer's parameterised constructor\n";
			this->name = name;
			this->credits = credits;
			counter++;
		}

		Customer(const Customer& c) : id(c.id) {
			cout << "\nInside Customer's copy constructor\n";
			name = c.name;
			credits = c.credits;
			counter++;
		}

		void printInfo() const {
			cout << "\nCustomer Info\n";
			cout << "Id :" << id << endl;
			cout << "Name :" << name << endl;
			cout << "Credits :" << credits << endl;
 		}

 		void setName(string name) {
 			this->name = name;
 		}

 		void setCredits(double credits) {
 			this->credits = credits;
 		}

 		string getName() const {
 			return name;
 		}

 		double getCredits() const {
 			return credits;
 		}

 		static int getCounter() {
 			return counter;
 		}

 		void constFunction() const {
 			counter++;
 		}

 		~Customer() {
 			cout << "\nInside Customer's destructor\n";
 			counter--;
 		}
};

int Customer::counter = 0;

int main() {

	Customer c("Abhishek", 100.0, 1);

	c.printInfo();

	cout << Customer::getCounter() << endl;

	c.constFunction();

	cout << Customer::getCounter() << endl;

	const Customer c2("Shailesh", 200, 2);

	Customer c3(c);
	return 0;
}
