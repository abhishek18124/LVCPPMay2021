/*
	
--------------------------------------
Summary : Functions and Variable Scope 
--------------------------------------

* Scope of a variable defines it visibility.
* It is a section of code where we can use the name of the variable to access it.

1. Variables declared within a function are only available in the scope of the function.
2. Arguments to a function are also declared in the scope of the function, these variables 
   are not available to the caller even though the caller provides the values.
3. Variables declared in the scope of a function are not available in other functions 
   called during execution of the first function.

* Variables defined within a function or a block are known as local variables.

*/


#include<iostream>

using namespace std;


int main() {

	// let me declare two variables
	
	int x = 10;
	int y = 20;

	// where can we use these variables ?
	












	// we can use them within the scope in which they are defined.

	


	// and we know, in C++, {} defines a scope




	// ,and here {} is also the scope of the main function



	// so I can say I can use these two variables anywhere in the main function





	// To conclude, variables defined within a function can be only be used 

	// in the scope of the function.

	return 0;
}