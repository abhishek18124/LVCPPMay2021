/*

What are maps ? 

Maps are associative containers that store elements formed by a combination of a key value and a mapped value, 
following a specific order. Internally, the elements in a map are always sorted by its key.

Maps are typically implemented as binary search trees, and therefore are generally slower than unordered_map 
containers to access individual elements by their key.

How to create an map ? 
	> use empty container constructor (default constructor)
	> use initialiser list (C++11)
	> use copy constructor
	> use range constructor
How to insert (K, V) pair into an map ?
	> use map::insert (C++11)
    > use []
How to update a (K, V) pair in an map ?
    > use [] 
How to lookup/search for the value corresponding to a key in an map ? 
    > use map::find
    > use map::count
    > use []
How to delete a (K, V) pair from an map ?
	> use map::erase
	  > by key
	  > by position
	  > by range
    > use map::clear to remove all the elements from an map
How to check size of an map ?
	> use map::size to know number of (K, V) pairs present in an map
How to check if a map is empty ?
    > use map::empty or check if size of map is 0
How to iterate over elements in an map ?
    > use an iterator

*/

#include<iostream>
#include<map>

using namespace std;

class Comparator {
public:
	bool operator()(const string key1, const string key2) const {
		return key1 < key2;
	}
};

int main() {

	// build an map using the default constructor
	map<string, string, Comparator>  capitalMap;

	// inserting into a map

	// using map::insert

	capitalMap.insert(pair<string, string>("India", "New Delhi"));

	capitalMap.insert(make_pair("USA", "Washington"));

	capitalMap.insert({"Italy", "Rome"});

	// using []

	capitalMap["Brazil"] = "Rio";

	// print map size using map::size

	cout << "size = " << capitalMap.size() << endl;

	// iterating over the map

	// using an iterator

	for(auto it=capitalMap.begin(), end=capitalMap.end(); it != end; it++) {
		pair<string, string> p = *it;
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	// using for-each loop
	for(pair<string, string> p : capitalMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;


	// updating a value corresponding to a key in a map using []
	capitalMap["Brazil"] = "Rio de Janeiro";

	// using for-each loop
	for(pair<string, string> p : capitalMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	// lookups

	// using map::find
	string key = "India";
	if(capitalMap.find(key) != capitalMap.end()) {
		// key is found in the map
		cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
	} else {
		// key is not found in the map
		cout << key <<  " is not present!" << endl;
	}

	// using unordered_map::count
	
	key = "UK";
	if(capitalMap.count(key)){
		// key is found in the map
		cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
	} else {
		// key is not found in the map
		cout << key <<  " is not present!" << endl;
	}
 
	// deletion using unordered_map::erase

	// by key

	cout << "size = " << capitalMap.size() << endl;

	// erasing an invalid key
	key = "UK";
	cout << capitalMap.erase(key) << endl;

	cout << "size = " << capitalMap.size() << endl;

	// erasing a valid key
	key = "Japan";
	cout << capitalMap.erase(key) << endl;

	cout << "size = " << capitalMap.size() << endl;

	// clear using map::clear
	capitalMap.clear();
	cout << "size = " << capitalMap.size() << endl;

	// build an map using the initialiser list
	map<string, int> menuMap = {
		{"Burger", 10},	
		{"Pizza", 20},
		{"Pepsi", 40}
	};

	cout << endl;

	cout << "size = " << menuMap.size() << endl;

	// using for-each loop
	for(pair<string, int> p : menuMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;
	
	// build an map using the copy constructor
	map<string, int> copyMenuMap(menuMap);

	cout << endl;

	cout << "size = " << copyMenuMap.size() << endl;

	// using for-each loop
	for(pair<string, int> p : copyMenuMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	// build an map using the initialiser list
	map<int, int, greater<int>> int2squares = {
		{1, 1},	
		{2, 4},
		{3, 9}
	};

	cout << endl;

	cout << "size = " << int2squares.size() << endl;

	// using for-each loop
	for(pair<int, int> p : int2squares) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	return 0;
}