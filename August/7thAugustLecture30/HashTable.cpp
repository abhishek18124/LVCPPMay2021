/*

Implement a hash table from scratch in C++ to store mapping between food item (string)
and its price (integer).

*/

#include<iostream>
#include<climits>

using namespace std;

class node {
public:
	string key;
	int value;
	node* next;

	node(string key, int value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}

	~node() {
		if(next != NULL) {
			delete next;
		}
	}
};


class HashTable {
	int ts; // tableSize
	int cs; // currentSize
	node** table;
	float loadFactorThreshold;

	int hashFn(string key) {
		int power = 1;
		int idx = 0;
		for(int i=0; i<key.size(); i++) {
			idx += ((key[i]%ts) * (power%ts))%ts;
			power= (power*61)%ts;
		}
		return idx%ts;
	}

	void transfer(node* head) {
		node* temp = head;
		while(temp != NULL) {
			insert(temp->key, temp->value);
			temp = temp->next;
		}
		if(head != NULL) delete head;
	}

	void rehash() {
		int old_ts = ts;
		node** old_table = table;

		ts *= 2;
		cs = 0;
		table = new node*[ts];
		for(int i=0; i<ts; i++) {
			table[i] = NULL;
		}

		for(int i=0; i<old_ts; i++) {
			transfer(old_table[i]);
		}

		delete [] old_table;

	}

public:

	HashTable(int ts, float loadFactorThreshold=0.7) {
		this->ts = ts;
		this->cs = 0;

		table = new node*[ts];
		for(int i=0; i<ts; i++) {
			table[i] = NULL;
		}

		this->loadFactorThreshold = loadFactorThreshold;
	}

	void insert(string key, int value) {
		// create a node
		node* n = new node(key, value);

		// obtain the hash idx using the hash fn
		int hash_idx = hashFn(key);

		// insert the node in the linked list maintained at the hash_idx inside the table
		n->next = table[hash_idx];
		table[hash_idx] = n;

		// increment the current size
		cs++;

		float loadFactor = cs / (ts * 1.0);
		if(loadFactor > loadFactorThreshold) {
			cout << loadFactor << " Rehasing..." << ts << endl;
			rehash();
			cout << ts << endl;
			
		}

	}

	node* search(string key) {
		// obtain the hash_idx using the hash_fn
		int hash_idx = hashFn(key);

		node* temp = table[hash_idx];
		while(temp != NULL) {
			if(temp->key == key) {
				// you've found the node with the given key
				return temp;
			}
			temp = temp->next;
		}
		// key doesn't exist inside the hash table
		return NULL;
	}

	void printLinkedList(node* head) {
		while(head != NULL) {
			cout << "(" << head->key << ", " << head->value << ")";
			head = head->next;
			if(head != NULL) cout << "->";
		}
		cout << endl;
	}

	void print() {
		for(int i=0; i<ts; i++) {
			cout << i << " ";
			printLinkedList(table[i]);
		}
	}

	int& operator[](string key) {
		node* n = search(key);
		if(n == NULL) {
			// key is not present in the hash table
			int garbage = INT_MIN;
			insert(key, garbage);
			n = search(key);
		}
		return n->value;
	}
};


int main() {

	HashTable menu(7);

	// insert
	menu.insert("Burger", 100);
	menu.insert("Pizza", 200);
	menu.insert("Pepsi", 50);
	menu.insert("FrenchFries", 100);

	// print
	// menu.print(); cout << endl;

	menu.insert("Sushi", 90);
	menu.insert("Waffle", 100);
	menu.insert("Momos", 20);
	menu.insert("Chai", 5);
	menu.insert("Coffee", 10);

	menu.print(); cout << endl;

	// search
	string key =  "Burger";
	node* n = menu.search(key);
	n ? cout << n->key << " Rs." << n->value << endl : cout << "Item not present!" << endl;
	
	// overload the [] operator to perform insertion, updation and search

	menu["Coffee"] = 50;

	menu.print(); cout << endl;

	menu["Dosa"] = 20;
	// menu["Dosa"] = 40;
	// menu["Dosa"] += 10;

	menu.print(); cout << endl;

	// if(menu["Idli"] == INT_MIN) {
	// 	cout << "Item not present" << endl;
	// } else {
	// 	cout << menu["Idli"] << endl;
	// }

	// menu["Idli"] = 20;
	// if(menu["Idli"] == INT_MIN) {
	// 	cout << "Item not present" << endl;
	// } else {
	// 	cout << menu["Idli"] << endl;
	// }
}







