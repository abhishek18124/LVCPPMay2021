/*

Operator Overloading using operator functions

*/

#include<iostream>

using namespace std;

class  Customer {

	string name;
	double credits;

public:
		Customer() {
			cout <<"\nInside default constructor\n";
		}

		Customer(string name, double credits) {
			cout << "\nInside Customer's parameterised constructor\n";
			this->name = name;
			this->credits = credits;
		}

		void operator=(Customer& c) {
			cout << "\nInside Customer's copy assignment operation function\n";
			this->name = c.name;
			this->credits = c.credits;
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

 		bool operator>(Customer& c) {
 			return credits > c.credits;
 		}

 		~Customer() {
 			cout << "\nInside Customer's destructor\n";
 		}
};


bool operator<(Customer& c1, Customer& c2) {
	return c1.getCredits() < c2.getCredits();
}

int main() {
	
	Customer c1("Abhishek", 10.0);

	c1.printInfo();

	Customer c2("Tanishk", 50.0);

	c2.printInfo();

	Customer c3;

	// c3 = c2; // simple way to call operation= function

	c3.operator=(c2); // another way to explicitly call operation fn

	c3.printInfo();

	if(c1.operator>(c2)) { // or c1 > c2
		cout << c1.getName() << " has more credits than " << c2.getName();
	} else {
		cout << c2.getName() << " has more credits than " << c1.getName();
	}

	cout << endl;

	if(c1 < c2) {
		cout << c1.getName() << " has less credits than " << c2.getName();
	} else {
		cout << c2.getName() << " has less credits than " << c1.getName();
	}

	return 0;
}
