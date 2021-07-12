/*

Member Functions

Constructor
	1. Default Constructor
	2. Parameterised Constructors (>1)

*/

#include<iostream>

using namespace std;

class  Customer {

public:
		int age;
		char name[100];
		double credits;
		char gender;

		void printInfo() {
			cout << "\nCustomer Info\n";
			cout << "Name :" << name << endl;
			cout << "Age : " << age << endl;
			cout << "Gender : " << gender << endl;
			cout << "Credits :" << credits << endl;
 		}

 		Customer() {
 			// this is a default constructor
 			cout << "\nInside the default constructor !\n";
 		}

 		Customer(char n[], int a, char g, double c) {
 			cout << "\nInside the parameterised constructor 1!\n"; 
 			strcpy(name, n);
 			age = a;
 			gender = g;
 			credits = c;
 		}

 		Customer(char n[], int a, char g) {
 			cout << "\nInside the parameterised constructor 2!\n"; 
 			strcpy(name, n);
 			age = a;
 			gender = g;
 			credits = 0;
 		}


};

// void printInfo(Customer c) {
// 	cout << "\nCustomer Info\n";
// 	cout << "Name : " << c.name << endl;
// 	cout << "Age : " << c.age << endl;
// 	cout << "Gender : " << c.gender << endl;
// 	cout << "Credits : " << c.credits << endl;
// }

int main() {

	Customer c1;

	// assigning values to data members
	
	c1.age = 20;
	c1.gender = 'M';
	c1.credits = 100;
	strcpy(c1.name, "Abhishek");
	
	// printInfo(c1);	

	c1.printInfo();

	Customer c2;

	c2.age = 40;
	c2.gender = 'F';
	c2.credits = 0;
	strcpy(c2.name, "Anamika");

	// printInfo(c2);

	c2.printInfo();

	char name3[] = "Misaka";
	Customer c3(name3, 101, 'F', 10);

	c3.printInfo();

	char name4[] = "Nora";
	Customer c4(name4, 28, 'F');

	c4.printInfo();

	return 0;
}