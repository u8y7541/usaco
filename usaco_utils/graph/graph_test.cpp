#include <iostream>
#include "Graph.h"
using namespace std;

int main(void) {
	bool graph[4][4] = {{0, 1, 0, 1},
						{0, 0, 1, 0},
						{0, 0, 0, 1},
						{0, 0, 0, 0}};
	Graph g(4, (bool*)graph);
	bool* bfs;
	bfs = g.bfs(0);
	for (int i = 0; i<4; i++) {
		cout<<bfs[i]<<endl;
	}
	delete bfs;
	return 0;
}
