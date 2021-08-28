/*

Trie traversal and auto-completion.

*/

#include<iostream>
#include<map>

using namespace std;

class node {
public:
	char ch;
	bool terminal;
	map<char, node*> childMap;

	node(char ch) {
		this->ch = ch;
		this->terminal = false;
	}
};

class trie {
	
public:
	node* root;
	trie() {
		root = new node('\0');
	}

	void insert(string word) {
		node* temp = root;
		for(char ch : word) {
			if(!temp->childMap.count(ch))  {
				// temp node do not have ch as a child
				node* n = new node(ch);
				temp->childMap[ch] = n;
			}
			temp = temp->childMap[ch];
		}

		// make the node corresponding to the last character of the word, a terminal node
		temp->terminal = true;
	}

};


int main() {

	trie t;

	t.insert("new");
	t.insert("news");
	t.insert("newspaper");

	t.insert("nickle");
	t.insert("nice");

	t.insert("code");
	t.insert("coder");
	t.insert("coding");

	t.insert("cobra");
	t.insert("cobweb");

	return 0;
}