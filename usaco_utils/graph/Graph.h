class Graph {
	int V;
	bool** adj;

	public:
		Graph(int nodes, bool* graph);
		bool* bfs(int start);
};
