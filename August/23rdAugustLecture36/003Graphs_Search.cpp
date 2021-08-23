/*

Graph search

 > Depth First Search (DFS)
 > Breadth First Search (BFS)

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<stack>
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

	void dfsHelper(T u, unordered_set<T>& visited) {
		visited.insert(u);
		cout << u << " ";
		for(T neighbour : neighbourMap[u]) {
			if(visited.find(neighbour) == visited.end()) {
				dfsHelper(neighbour, visited);
			}
		}
	}

	void recursiveDFS(T s) {
		unordered_set<T> visited;
		cout << "dfs(" << s << ") : ";
		dfsHelper(s, visited);
		cout << endl; 
	}

	void iterativeDFS(T s) {
		stack<T> stk;
		unordered_set<T> visited;

		stk.push(s);
		visited.insert(s);

		cout << "dfs(" << s << ") : ";
		while(!stk.empty()) {
			T top = stk.top(); stk.pop();
			cout << top << " ";
			for(T neighbour : neighbourMap[top]) {
				if(visited.find(neighbour) == visited.end()) {
					stk.push(neighbour);
					visited.insert(neighbour);
				}
			}
		}

		cout << endl;
	}

	void iterativeBFS(T s) {
		queue<T> q;
		unordered_set<T> visited;

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

		cout << endl;
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

	g.print();

	g.recursiveDFS(0);
	g.iterativeDFS(0);
	g.iterativeBFS(0);

	return 0;
}