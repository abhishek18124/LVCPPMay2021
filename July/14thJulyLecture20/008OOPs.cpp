/*

   Member Initialization
   Member Objects
    How to intialise data members of member object ?
    > invoke parameterised constructor of member object via member initialization
    > this is mandatory if member object doesn't have a default contructor

*/

#include<iostream>

using namespace std;

class CreditCard {
	string cardNumber;
	int cvv;

public: 

	CreditCard(string cn, int c) {
		cout << "\nInside CreditCard's parameterised constructor\n";
		cardNumber = cn;
		cvv = c;
	}

	void setCardNumber(string cn) {
		cardNumber = cn;
	}

	void setCVV(int c) {
		cvv = c;
	}

	string getCardNumber() {
		return cardNumber;
	}

	int getCVV() {
		return cvv;
	}

	~CreditCard() {
		cout << "\nInside CreditCard's destructor\n";
	}
};

class  Customer {

	string name;
	double credits;
	CreditCard card; // custom member object

public:

		
		Customer(string n, double c, string cn, int cv) : card(cn, cv) {
			cout << "\nInside Customer's parameterised constructor\n";
			name = n;
			credits = c;
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

 		void setCreditCardInfo(string cardNumber, int cvv) {
 			card.setCardNumber(cardNumber);
 			card.setCVV(cvv);
 		}

 		void printCreditCardInfo() {
 			cout << "\nCreditCard Info\n";
			cout << "Number :" << card.getCardNumber() << endl;
			cout << "CVV :" << card.getCVV() << endl;
 		}

 		~Customer() {
 			cout << "\nInside Customer's destructor\n";
 		}
};

int main() {

	Customer c("Abhishek", 100.0, "12-34-56-78", 123);

	c.printInfo();

	c.printCreditCardInfo();


	return 0;
}
