/*

Usage of string class in C++.

*/

#include<iostream>

using namespace std;

int main() {

	#ifndef IO
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	// // String declaration

	// string str;

	// Initialization of a string

	string str1 = "this is a string 1";
	cout << str1 << endl;

	string str2{"this is a string 2"};
	cout << str2 << endl;

	string str3("this is a string 3");
	cout << str3 << endl;

	char chstr4[] = "this is a string 4";
	string str4(chstr4);
	cout << str4 << endl;

	string str5("this is a string 5");
	char* chstr5 = (char*)str5.c_str();
	cout << chstr5 << endl;

	// User Input
	string str6;
	cin >> str6;
	cout << str6 << endl;

	cin.ignore();

	string str7;
	getline(cin, str7);
	cout << str7 << endl;

	// String methods

	string str8("hello");
	string str9("world");

	// 0. Indexi"ng
	cout << str8[2] << endl;
	cout << str8.at(2) << endl;

	// 1. Length
	cout << str8.length() << endl;
	cout << str8.size() << endl;

	// 2. Append
	cout << "before append : str8 =  " << str8 << endl;
	str8.append(str9);
	cout << "after append : str8 =  " << str8 << endl;

	string str10("coding");
	string str11("blocks");

	// str10 = str10 + str11;
	// str10 += str11;
	// str10 = str10 + " " + str11;
	str10 += " " + str11;
	cout << str10 << endl;

	string str12(str11);

	// 3. Compare, ==, >, <, <=, >=
	cout << (str10 == str11) << endl;
	cout << (str10 == str10) << endl;
	cout << (str11 == str12) << endl;

	string str13("abc");
	string str14("cba");

	cout << (str13 > str14) << endl;

	// 4. Find
	string str15("this is a string 15");
	cout << str15.find('i') << endl; // first index of i in str15
	cout << str15.rfind('i') << endl; // first index of i from back
		
	cout << str15.find("str") << endl; // first index of substring str in str15
	cout << str15.find("hello") << endl;

	if(str15.find("hello") == string::npos) {
		cout << "hello is not present" << endl;
	} else {
		cout << "hello is present" << endl;
	}

	cout << string::npos << endl;

	// 5. Insert
	string s16("this is a string 16");
	s16.insert(2, "xx");
	cout << s16 << endl;

	// 6. Erase
	s16.erase(2, 4); // (idx, len)
	cout << s16 << endl;

	// 7. Substring
	string s17("hello world");
	cout << s17.substr(2) << endl;
	cout << s17.substr(2, 3) << endl;

}