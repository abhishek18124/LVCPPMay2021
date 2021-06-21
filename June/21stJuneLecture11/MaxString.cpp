/*

Given a n strings represented as a character arrays, 
write a function that find the maximum length string.

Example :
	Input : a[] = "ab" b[] = "cde" c[] = "ghijk"
	Output: 5, "ghijk"
*/
#include<iostream>
#include<climits>

using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	cin.ignore(); // very important

	char temp[100];
	char maxString[100];
	int maxLen = INT_MIN;

	for(int i=0; i<n; i++) {
		cin.getline(temp, 99);
		if(int(strlen(temp)) > maxLen) {
			maxLen = strlen(temp);
			strcpy(maxString, temp);
		}
	}

	cout << maxLen << " " << maxString << endl;

	return 0;
}