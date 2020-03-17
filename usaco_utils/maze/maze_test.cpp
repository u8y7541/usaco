#include <iostream>
#include "Maze.h"
using namespace std;

int main(void) {
	const int rows = 6;
	const int cols = 5;
	bool map[rows][cols] = {{0, 0, 1, 0, 0},
	 				   		{1, 0, 0, 0, 1},
	 				   		{1, 1, 1, 0, 1},
							{0, 0, 0, 0, 1},
							{0, 1, 0, 1, 1},
							{0, 0, 0, 1, 1}};
	cout<<"Initial map:"<<endl;
	for (int i = 0; i<rows; i++) {
		for (int j = 0; j<cols; j++) {
			cout<<(map[i][j]? '#':'.');
		}
		cout<<endl;
	}
	Maze maze(rows, cols, (bool*)map);
	bool** path;
	path = maze.path(0, 0, 4, 0);

	cout<<"\nPath:"<<endl;
	for (int i = 0; i<rows; i++) {
		for (int j = 0; j<cols; j++) {
			cout<<(path[i][j]? '>':'.');
		}
		cout<<endl;
	}

	bool** flood_dfs;
	flood_dfs = maze.floodfill_dfs(0, 0);
	cout<<"\nDepth-first floodfill:"<<endl;
	for (int i = 0; i<rows; i++) {
		for (int j = 0; j<cols; j++) {
			cout<<(flood_dfs[i][j]? "*":".");
		}
		cout<<endl;
	}

	bool** flood_bfs;
	flood_bfs = maze.floodfill_bfs(0, 0);
	cout<<"\nBreadth-first floodfill:"<<endl;
	for (int i = 0; i<rows; i++) {
		for (int j = 0; j<cols; j++) {
			cout<<(flood_bfs[i][j]? "*":".");
		}
		cout<<endl;
	}

	bool map2[rows][cols] = {{1, 1, 0, 1, 1},
							 {1, 0, 0, 0, 1},
							 {0, 0, 0, 0, 0},
							 {1, 0, 0, 0, 1},
							 {1, 1, 0, 1, 1},
							 {0, 1, 1, 1, 1}};
	cout<<"\nBreadth-first floodfill 2 map:"<<endl;
	for (int i = 0; i<rows; i++) {
		for (int j = 0; j<cols; j++) {
			cout<<(map2[i][j]? '#':'.');
		}
		cout<<endl;
	}
	Maze maze2(rows, cols, (bool*)map2);
	bool** flood_bfs_border;
	flood_bfs_border = maze2.floodfill_bfs(0, 2);
	cout<<"\nBreadth-first floodfill 2:"<<endl;
	for (int i = 0; i<rows; i++) {
		for (int j = 0; j<cols; j++) {
			cout<<(flood_bfs_border[i][j]? "*":".");
		}
		cout<<endl;
	}

	delete path;
	delete flood_dfs;
	delete flood_bfs;
	delete flood_bfs_border;
	return 0;
}
