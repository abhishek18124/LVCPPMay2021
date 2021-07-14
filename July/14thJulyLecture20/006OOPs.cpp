/*

	Uniform Initialization
	   > cannot be confused with function declaration
	   > default constructor can be called explicitly

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
		
		Customer(string n, double c) {
			cout << "\nInside Customer's parameterised constructor\n";
			name = n;
			credits = c;
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

 		void setName(string n) {
 			name = n;
 		}

 		void setCredits(double c) {
 			credits = c;
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
};


int main() {

	Customer c1("Harish", 100.0); // functional form

	c1.printInfo();

	Customer c2{"Lucifier", 200.0}; // uniform initialisation

	c2.printInfo();

	Customer c3 = {"Krushi", 50.0};

	c3.printInfo();

	Customer c4; // we donot give empty parentheses to invoke the default constructor

	Customer c5{}; // explicitly calling the default constructor

	return 0;
}





