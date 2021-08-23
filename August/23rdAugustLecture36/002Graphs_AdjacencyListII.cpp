/*

Implementation of the graph using adjacency list.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<list>
#include<map>

using namespace std;

template <typename T>
class Graph {
	map<T, list<T>> neighbourMap;
	bool directed;

public:
	Graph(bool directed=false) {
		this->directed = directed;
	}

	void addEdge(T u, T v) {
		neighbourMap[u].push_back(v);
		if(!directed) neighbourMap[v].push_back(u);
	}

	void print() {
		for(pair<T, list<T>> p : neighbourMap) {
			cout << p.first << " : ";
			for(T neighbour : p.second) {
				cout << neighbour << " ";
			}
			cout << endl;
		}
	}
};


int main() {

	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	g.print();

	return 0;
}