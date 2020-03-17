#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "LooplessGraph.h"
using namespace std;

LooplessGraph::LooplessGraph(int nodes, int* graph) {
	V = nodes;
	memcpy(parents, graph, V);
}

int* LooplessGraph::path(int start, int end) {
	int* answer = (int*)malloc(V*sizeof(int));
	int* startBranch = (int*)malloc(V*sizeof(int));
	int* endBranch = (int*)malloc(V*sizeof(int));
	memset(answer, 0, V*sizeof(int));
	memset(startBranch, -1, V*sizeof(int));
	memset(endBranch, -2, V*sizeof(int));

	int counter = 0;
	startBranch[0] = start;
	endBranch[0] = end;
	while (startBranch[counter] != endBranch[counter]) {
		counter++;
		startBranch[counter] = parents[startBranch[counter-1]];
		endBranch[counter] = parents[endBranch[counter-1]];
	}
	counter++;

	memcpy(answer, startBranch, counter*sizeof(int));
	for (int i = 1; i<counter; i++) {
		answer[counter+i-1] = endBranch[counter-i-1];
	}	

	delete startBranch;
	delete endBranch;
	return answer;
}
