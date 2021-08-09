/*

Implement a phonebook storing mapping between person's name and their phone numbers using an unordered_map.

*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main() {

	unordered_map<string, vector<long long>> phonebook;

	phonebook["Abhishek"].push_back(9999366996);
	phonebook["Abhishek"].push_back(1234567890);

	phonebook["Ayush"].push_back(1111122222);
	phonebook["Ayush"].push_back(9617425555);

	phonebook["Shailesh"].push_back(9560972545);

	for(auto p : phonebook) {
		cout << p.first << " ";
		for(auto number : p.second) {
			cout << number << " ";
		}
		cout << endl;
	}


}