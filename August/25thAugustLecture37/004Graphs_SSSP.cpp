/*

Computing the Single Source Shortest Path (SSSP) using BFS in an undirected graph.

*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class Graph {
	bool directed;
	unordered_map<T, list<T>> neighbourMap;

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

	void iterativeBFS(T s, T d) {
		queue<T> q;
		unordered_set<T> visited;
		unordered_map<T, int> distaceMap;
		unordered_map<T, T> parentMap;
		
		q.push(s);
		visited.insert(s);
		distaceMap[s] = 0; // length of the shortest path from the source vertex to source vertex is zero
		parentMap[s] = s;

		cout << endl <<  "bfs(" << s << ") : ";
		while(!q.empty()) {
			T parent = q.front(); q.pop();
			cout << parent << " ";
			for(T child : neighbourMap[parent]) {
				if(visited.find(child) == visited.end()) {
					q.push(child);
					visited.insert(child);
					distaceMap[child] = distaceMap[parent] + 1;
					parentMap[child] = parent;
				}
			}
		}

		cout << endl << endl;

		cout << "The length of the shortest path between " << s << " & " << d << " = " << distaceMap[d] << endl;
		cout << "The shortest path between " << s << " & " << d << " is ";

		T temp = d;
		while(parentMap[temp] != temp) {
			cout << temp << "<-";
			temp = parentMap[temp];
		}
		cout << temp << endl << endl;


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

	g.iterativeBFS(0, 6);

	return 0;
}