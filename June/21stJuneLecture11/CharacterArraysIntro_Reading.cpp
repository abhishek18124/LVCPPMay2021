#include<iostream>

using namespace std;

void readString(char* str, char delimiter='\n') {
	char ch = cin.get();
	int i = 0;
	while(ch != delimiter) {
		str[i++] = ch;
		ch = cin.get();
	}
	str[i] = '\0';
}

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	char str[100];
	// cin >> str;
	// cout << str << endl;

	// readString(str);
	cin.getline(str, 20);
	// cout << str << endl;
	for(int i=0; str[i] != '\0'; i++) {
		cout << str[i] << " ";
	}


	return 0;
}