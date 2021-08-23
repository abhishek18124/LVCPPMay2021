/*

Graph traversal using

 > Depth First Search (DFS)
 > Breadth First Search (BFS)

*/

#include<iostream>
#include<map>
#include<unordered_set>
#include<list>
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

	void iterativeBFS(T s) {
		queue<T> q;
		unordered_set<T> visited;
		
		q.push(s);
		visited.insert(s);
		
		cout << "bfs(" << s << ") : ";
		while(!q.empty()) {
			T front = q.front(); q.pop();
			cout << front << " ";
			for(T neighbour :  neighbourMap[front]) {
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

}