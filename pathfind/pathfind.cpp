#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class Graph {
	int V;
	bool** adj;

	public:
	Graph(int nodes, bool* graph);
	bool* bfs(int start);
};

Graph::Graph(int nodes, bool* graph) {
	V = nodes;
	adj = (bool**)malloc(V*sizeof(bool*));
	for (int i = 0; i<V; i++) {
		adj[i] = (bool*)malloc(V*sizeof(bool));
		for (int j = 0; j<V; j++) {
			adj[i][j] = graph[i*V+j];
		}
	}
}

bool* Graph::bfs(int start) {
	bool* border = (bool*)malloc(V*sizeof(bool));
	memset(border, false, V*sizeof(bool));
	bool* newBorder = (bool*)malloc(V*sizeof(bool));
	memset(newBorder, false, V*sizeof(bool));
	border[start] = true;
	bool* visited = (bool*)malloc(V*sizeof(bool));
	memset(visited, false, V*sizeof(bool));
	visited[start] = true;

	bool changed = true;
	while (changed) {
		changed = false;
		for (int i = 0; i<V; i++) {
			if (border[i]) {
				for (int j = 0; j<V; j++) {
					if (adj[i][j] && !visited[j] && !border[j]) {
						changed = true;
						newBorder[j] = true;
					}
				}
			}
		}
		for (int i = 0; i<V; i++) {
			if (border[i]) {
				visited[i] = true;
			}
			if (newBorder[i]) {
				cout<<i+1<<" ";
			}
		}
		cout<<endl;
		memcpy(border, newBorder, V*sizeof(bool));
		memset(newBorder, false, V*sizeof(bool));
		for (int i = 0; i<V; i++) {
			cout<<(border[i]? '1':'0')<<' ';
		}
		cout<<endl;
		for (int i = 0; i<V; i++) {
			cout<<(newBorder[i]? '1':'0')<<' ';
		}
		cout<<endl;
	}
	delete border;
	delete newBorder;
	return visited;
}

int main(void) {
	int N, M;
	cin>>N>>M;
	bool graph[4][4];
	char tmp;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			cin>>tmp;
			graph[i][j] = (tmp == '1');
		}
	}
	cout<<M<<endl;
	Graph g(N, (bool*)graph);
	g.bfs(M-1);
	return 0;
}
