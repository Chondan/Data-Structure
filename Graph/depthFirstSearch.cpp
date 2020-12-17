#include <iostream>
#include <list>
using namespace std;

class Graph {
private:
	int V;// No. of vertices
	list<int> *adj; // adjacency list store all of the adjacent vertices of each vertex
	void DFSUtil(int v, bool *visited); // A recursive function used by DFS
public:
	Graph(int V); // constructor
	void addEdge(int v, int w); // add w to v's list
	void DFS(); // DFS traversal starting from vertex s
};

int main(void) {
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS();
}

Graph::Graph(int V) {
	this->V = V;
	this->adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::DFS() {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			DFSUtil(i, visited);
		}
	}
	cout << '\n';
}

void Graph::DFSUtil(int v, bool *visited) {
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++) {
		if (!visited[*i]) {
			DFSUtil(*i, visited);
		}
	}
}