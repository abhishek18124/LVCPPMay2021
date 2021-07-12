/*

1. Copy Constructor
2. Copy Assignment Operator

*/

#include<iostream>

using namespace std;

class  Customer {
// private:
		char name[100];
		double credits;
		int age;
		char gender;
		
public:

		void printInfo() {
			cout << "\nCustomer Info\n";
			cout << "Name :" << name << endl;
			cout << "Age : " << age << endl;
			cout << "Gender : " << gender << endl;
			cout << "Credits :" << credits << endl;
 		}

 		Customer () {
 			cout << "\nInside the default constructor !\n";
 		}

 		Customer(char n[], int a, char g, double c) {
 			cout << "\nInside the parameterised constructor!\n"; 
 			strcpy(name, n);
 			age = a;
 			gender = g;
 			credits = c;
 		}

 		// shallow copy
 		Customer(Customer& c) {
 			cout << "\nInside the copy constructor !\n";
 			strcpy(name, c.name);
 			age = c.age;
 			gender = c.gender;
 			credits = c.credits;
 		}

 		// shallow copy
 		void operator=(Customer& c) {
 			cout << "\nInside the copy assignment opertor !\n";
 			strcpy(name, c.name);
 			age = c.age;
 			gender = c.gender;
 			credits = c.credits;
 		}

 		void setAge(int a) {
 			age = a;
 		}

 		void setGender(char g) {
 			gender = g;
 		}

 		double getCredit() {
 			return credits;
 		}

 		int getAge() {
 			return age;
 		}

 		char getGender() {
 			return gender;
 		}
};

int main() {	


	char name[] = "Misaka";
	Customer c1(name, 101, 'F', 10);

	c1.printInfo();
 
	Customer c2 = c1; // default copy constructor is called by c++ automatically
 
	c2.printInfo();

	Customer c3(c1); // default copy constructor is called by c++ automatically

	c3.printInfo();

	Customer c4; // declaration
 
	c4 = c1; // default copy assignment operator (member fn)

	c4.printInfo();

	return 0;
}