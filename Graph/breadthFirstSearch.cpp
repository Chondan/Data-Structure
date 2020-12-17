#include <iostream>
#include <list>
using namespace std;

// Pseudo code
/*
1. create a Graph'class -> capacity, adjecent vertex's list of each vertex
2. traversal starting from a given source
	- create a list storing boolean defined visited history -> at first, set visited to false for every vetices
	- start exploring at a given source and push it to the 'queue' (enqueue)
		- push all of it adjacents into the 'queue' and set an adjacency vertex as visited
		- if some adjacency vertex is already visited -> take it out from the 'queue'
	- after exploring a vertex, take it out from the 'queue' (dequeue)
	- loop until the 'queue' is empty
*/

class Graph {

private:
	int V;
	list<int> *adj; // a list stored all of the adjacent vertices of each vertex
public:
	Graph(int V);
	void addEdge(int v, int w); // add w to v's list
	void BFS(int s); // BFS search starting form s

};

int main(void) {
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
}

Graph::Graph(int V) {
	this->V = V;
	this->adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::BFS(int s) {
	// create a boolean array and mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	// create a queue for ordering an order for exploration
	list<int> queue;

	// start exploring from s
	queue.push_back(s);
	visited[s] = true;

	list<int>::iterator i;
	while (!queue.empty()) {

		s = queue.front();
		cout << s << " ";

		for (i = adj[s].begin(); i != adj[s].end(); i++) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}

		queue.pop_front();
	}
}