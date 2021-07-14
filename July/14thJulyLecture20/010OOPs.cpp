/*

	Static class members 
    	> static data members a.k.a class members are shared by all class objects 
		> static member function can access only static data members

*/

#include<iostream>

using namespace std;

class  Customer {

	string name;
	double credits;
	
	
public:
		
		static int counter;

		Customer() {
			cout << "\nInside Customer's default constructor\n";
			counter++;
		}
		
		Customer(string name, double credits) : name(name), credits(credits) {
			cout << "\nInside Customer's parameterised constructor\n";
			counter++;
		}

		Customer(Customer& c) {
			cout << "\nInside Customer's copy constructor\n";
			name = c.name;
			credits = c.credits;
			counter++;
		}

		void operator=(Customer& c) {
			cout << "\nInside Customer's copy assignment operator function\n";
			name = c.name;
			credits = c.credits;
			counter++;
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
 			cout << "\nInside Customer's destructor\n";
 			counter--;
 		}

 		static int getCounter() {
 			return counter;
 		}
};

int Customer::counter = 0; // initialising static data member or class variable

int main() {

	Customer c1;
	Customer *c2 = new Customer;
	Customer c3;
	Customer c4;

	cout << Customer::counter << endl;

	delete c2;

	cout << Customer::getCounter() << endl;

	return 0;
}
