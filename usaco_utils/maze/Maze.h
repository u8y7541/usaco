class Maze {
	private:
		int width, height;
		bool** data;
		bool** pathAnswer;
		bool done;
		void recursePath(int r, int c, int fr, int fc, bool** answer);
		void recurseFloodfill(int r, int c, bool** answer); 
		bool** newBoolArray();

	public:
		Maze(int x, int y, bool* maze);
		bool inBounds(int r, int c);
		bool** path(int r, int c, int fr, int fc);
		bool** floodfill_dfs(int r, int c);
		bool** floodfill_bfs(int r, int c);
};
