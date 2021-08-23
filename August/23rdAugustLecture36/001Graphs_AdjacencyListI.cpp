/*

Implementation of the graph using adjacency list.

Note : each vertex in the graph is an integer.

*/

#include<iostream>
#include<list>

using namespace std;

class Graph {
	int V;
	list<int>* arr;
	bool directed;

public:
	Graph(int V, bool directed=false) {
		this->V = V;
		this->directed = directed;
		arr = new list<int>[V];
	}

	void addEdge(int u, int v) {
		arr[u].push_back(v);
		if(!directed) arr[v].push_back(u);
	}

	void print() {
		for(int i=0; i<V; i++) {
			cout << i << " : ";
			for(int neighbour : arr[i]) {
				cout << neighbour << " ";
			}
			cout << endl;
		}
	}
};

int main() {

	Graph g(5, true);

	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	g.print();

	return 0;
}