/*

Getters and Setters to access private data members.

*/


#include<iostream>

using namespace std;

class  Customer {
// private:
		
		double credits;
		int age;
		char gender;
		
public:

		char name[100];
		
		void printInfo() {
			cout << "\nCustomer Info\n";
			cout << "Name :" << name << endl;
			cout << "Age : " << age << endl;
			cout << "Gender : " << gender << endl;
			cout << "Credits :" << credits << endl;
 		}


 		Customer(char n[], int a, char g, double c) {
 			cout << "\nInside the parameterised constructor!\n"; 
 			strcpy(name, n);
 			age = a;
 			gender = g;
 			credits = c;
 		}

 		void applyCoupon(string coupon) {
 			if(coupon == "2021") {
 				credits += 100;
 				cout << "Sucess! 100 credits added." << endl;
 			} else {
 				cout << "Coupon not valid!" << endl;
 			}
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

	c1.applyCoupon("2021");

	cout << c1.getCredit() << endl;

	c1.setAge(19);

	cout << c1.getAge() << endl;

	return 0;
}