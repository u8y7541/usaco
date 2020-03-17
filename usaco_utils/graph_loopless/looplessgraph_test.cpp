#include <iostream>
#include "LooplessGraph.h"
using namespace std;

int main(void) {
	int graph[6] = {0, 0, 0, 1, 1, 2};
	LooplessGraph g(6, graph);
	int* path;
	path = g.path(3, 5);
	for (int i = 0; i<6; i++) {
		cout<<path[i];
		cout<<endl;
	}
	delete path;
	return 0;
}
