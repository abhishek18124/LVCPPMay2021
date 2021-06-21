#include<iostream>

using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int num;
	cin >> num;

	// cin.ignore();
	cin.get();	

	char str[100];
	cin.getline(str, 50);

	cout << "num = " << num << endl;
	cout << "str = " << str << endl;
	
	return 0;
}