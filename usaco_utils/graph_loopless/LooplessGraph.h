class LooplessGraph {
	int V;
	int parents[];
	public:
		LooplessGraph(int nodes, int* graph);
		int* path(int start, int end);
};
