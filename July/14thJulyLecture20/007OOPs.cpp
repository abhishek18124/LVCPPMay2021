/*

	1. Member Initialization
   2. Member Objects
      > default constructed
      How to assign values to data members of member object ?
       > use a member function
     
*/

#include<iostream>

using namespace std;

class CreditCard {
	string cardNumber; 
	int cvv; 

public: 

	CreditCard() {
		cout << "\nInside credit card's default constructor\n";
	}

	string getCardNumber() {
		return cardNumber;
	}

	int getCVV() {
		return cvv;
	}

	void setCardNumber(string cn) {
		cardNumber = cn;
	}

	void setCVV(int c) {
		cvv = c;
	}

	~CreditCard() {
		cout << "\nInside CreditCard's destructor\n";
	}

};

class  Customer {

	string name; // member object
	double credits;
	CreditCard card; // member object

public:

		Customer() {
			cout << "\nInside Customer's default constructor\n";
		}
		
		Customer(string n, double c) : name(n), credits(c) {
			cout << "\nInside Customer's parameterised constructor\n";
		}

		Customer(Customer& c) : name(c.name), credits(c.credits) {
			cout << "\nInside Customer's copy constructor\n";
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

 		void setCardInfo(string cardNumber, int cvv) {
 			card.setCardNumber(cardNumber);
 			card.setCVV(cvv);
 		}

 		void printCardInfo() {
 			cout << "\nCreditCard Info\n";
 			cout << card.getCardNumber() << endl;
 			cout << card.getCVV() << endl;
 		}

 		~Customer() {
 			cout << "\nInside Customer's destructor\n";
 		}
};

int main() {

	Customer c1("Kevin", 20.0);

	c1.printInfo();

	c1.setCardInfo("12-34-56-78", 123);

	c1.printCardInfo();

	return 0;
}
