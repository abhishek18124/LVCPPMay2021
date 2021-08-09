/*

What are unordered maps ? 

Unordered maps are associative containers that store elements formed by the combination of a key value and a 
mapped value, and which allows for fast retrieval of individual elements based on their keys. 

No two elements in the container can have equivalent keys.

What is the meaning of associative container ? 

Elements in associative containers are referenced by their key and not by their absolute position in the container.

How to create an unordered_map ? 
	> use empty container constructor (default constructor)
	> use initialiser list (C++11)
	> use copy constructor
	> use range constructor
How to insert (K, V) pair into an unordered_map ?
	> use unordered_map::insert (C++11)
    > use []
How to update a (K, V) pair in an unordered_map ?
    > use [] 
How to lookup/search for the value corresponding to a key in an unordered_map ? 
    > use unordered_map::find
    > use unordered_map::count
    > use []
How to delete a (K, V) pair from an unordered_map ?
	> use unordered_map::erase
	  > by key
	  > by position
	  > by range
    > use unordered_map::clear to remove all the elements from an unordered_map
How to check size of an unordered_map ?
	> use unordered_map::size to know number of (K, V) pairs present in an unordered_map
How to check number of buckets in an unordered_map ?
	> use unordered_map::bucket_count to know number of buckets present in an unordered_map
How to check if a unordered_map is empty ?
    > use unordered_map::empty or check if size of unordered_map is 0
How to iterate over elements in an unordered_map ?
    > use an iterator

*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	// build an unordered_map using the default constructor
	unordered_map<string, string>  capitalMap;

	// inserting into a map

	// using unordered_map::insert

	capitalMap.insert(pair<string, string>("India", "New Delhi"));

	capitalMap.insert(make_pair("USA", "Washington"));

	capitalMap.insert({"Italy", "Rome"});

	// using []

	capitalMap["Brazil"] = "Rio";

	// print map size using unordered_map::size

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

	// using an iterator to iterate over buckets
	for(int i=0; i<capitalMap.bucket_count(); i++) {
		cout << i << " ";
		// iterate over the linked list present at the ith bucket or ith index in the hash table
		for(auto it=capitalMap.begin(i), end=capitalMap.end(i); it != end; it++) {
			pair<string, string> p = *it;
			cout << "(" << p.first << ", " << p.second << ") " ;
		}
		cout << endl;
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

	// using unordered_map::find
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

	// using [], be cautious
	key = "Japan";
	if(capitalMap[key] != "") {
		// key is found in the map
		cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
	} else {
		// key is not found in the map
		cout << key <<  " is not present!" << endl;
	}

	if(capitalMap.find(key) != capitalMap.end()) {
		// key is found in the map
		cout << "(" << key << ", " << capitalMap[key] << ")" << endl;
	} else {
		// key is not found in the map
		cout << key <<  " is not present!" << endl;
	}

	cout << endl;

	capitalMap["Japan"] = "Tokyo";
 
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

	// clear using unordered_map::clear
	capitalMap.clear();
	cout << "size = " << capitalMap.size() << endl;

	// build an unordered_map using the initialiser list
	unordered_map<string, int> menuMap = {
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
	
	// build an unordered_map using the copy constructor
	unordered_map<string, int> copyMenuMap(menuMap);

	cout << endl;

	cout << "size = " << copyMenuMap.size() << endl;

	// using for-each loop
	for(pair<string, int> p : copyMenuMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	return 0;
}