#include <stdlib.h>
#include <string.h>
#include "Graph.h"
using namespace std;

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
	newBorder[start] = true;
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
		}
		memcpy(border, newBorder, V*sizeof(bool));
		memset(newBorder, false, V*sizeof(bool));
	}
	delete border;
	delete newBorder;
	return visited;
}
