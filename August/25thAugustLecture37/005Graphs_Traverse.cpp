/*

Using reachability algorithms (DFS/BFS) to traverse a graph.

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class Graph {
	bool directed;
	map<T, list<T>> neighbourMap;

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

	void iterativeBFS(T s, unordered_set<T>& visited) {
		queue<T> q;

		q.push(s);
		visited.insert(s);

		cout << "bfs(" << s << ") : ";
		while(!q.empty()) {
			T front = q.front(); q.pop();
			cout << front << " ";
			for(T neighbour : neighbourMap[front]) {
				if(visited.find(neighbour) == visited.end()) {
					q.push(neighbour);
					visited.insert(neighbour);
				}
			}
		}

		cout << endl << endl;
	}

	void traverseBFS() {
		unordered_set<T> visited;
		int numComponents = 0;
		for(pair<T, list<T>> vertex : neighbourMap) {
			T vertexName = vertex.first;
			if(visited.find(vertexName) == visited.end()) {
				numComponents++;
				iterativeBFS(vertexName, visited);
			}
		}
		cout << "Number of components in the graph = " << numComponents << endl;
	}
};


int main() {

	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 6);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 7);
	g.addEdge(6, 8);
	g.addEdge(7, 8);

	g.addEdge(9, 10);
	g.addEdge(9, 11);
	g.addEdge(10, 11);

	g.addEdge(12, 13);
	g.addEdge(14, 13);
	
	g.print();

	cout << endl;

	g.traverseBFS();

	return 0;
}