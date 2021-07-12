/*

	1. Creating a class
	2. Creating an object
	3. Passing an object to a function

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

	return 0;
}