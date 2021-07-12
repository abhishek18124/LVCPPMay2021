/*

1. Dynamic data members
2. Role of default constructor - set dynamic members to NULL
3. Destructor

*/

#include<iostream>

using namespace std;

class  Customer {
// private:
		char* name;
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
 			name = NULL; // to avoid derefercing unassigned pointer
 		}

 		Customer(char n[], int a, char g, double c) {
 			cout << "\nInside the parameterised constructor!\n"; 
 			name = new char[strlen(n)+1];
 			strcpy(name, n);
 			age = a;
 			gender = g;
 			credits = c;
 		}	

 		// // shallow copy by default
 		// Customer(Customer& c) {
 		// 	cout << "\nInside the copy constructor !\n";
 		// 	name = c.name;
 		// 	age = c.age;
 		// 	gender = c.gender;
 		// 	credits = c.credits;
 		// }

 		// // shallow copy by default
 		// void operator=(Customer& c) {
 		// 	cout << "\nInside the copy assignment opertor !\n";
 		// 	name = c.name;
 		// 	age = c.age;
 		// 	gender = c.gender;
 		// 	credits = c.credits;
 		// }

 		// deep copy
 		Customer(Customer& c) {
 			cout << "\nInside the copy constructor !\n";
 			name = new char[strlen(c.name)+1];
 			strcpy(name, c.name);
 			age = c.age;
 			gender = c.gender;
 			credits = c.credits;
 		}

 		// deep copy
 		void operator=(Customer& c) {
 			cout << "\nInside the copy assignment opertor !\n";
 			name = new char[strlen(c.name)+1];
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

 		void setName(char n[]) {
 			strcpy(name, n);
 		}

 		~Customer() {
 			cout << "\nInside " << name << "'s Destructor!\n";
 			delete [] name; // freeing the dynamically allocated space
 			name = NULL; // optional 
 		}
};

int main() {	

	Customer c0;


	char name[] = "Misaka";
	Customer c1(name, 101, 'F', 10);

	c1.printInfo();
 
	Customer c2(c1); // deep copy

	c2.printInfo();

	char name2[] = "Osaka";
	c2.setName(name2);

	c2.printInfo();

	c1.printInfo();

	return 0;
}