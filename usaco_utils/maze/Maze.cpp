#include <iostream>
#include <string.h>
#include <algorithm>
#include "Maze.h"
using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0 , -1, 0};

Maze::Maze(int x, int y, bool* maze) {
	height = x;
	width = y;
	done = false;
	data = new bool*[height];
	for (int i = 0; i<height; i++) {
		data[i] = new bool[width];
		for (int j = 0; j<width; j++) {
			data[i][j] = maze[i*width+j];
		}
	}
}

bool Maze::inBounds(int r, int c) {
	return (0<=r && r<height && 0<=c && c<width);
}

bool** Maze::newBoolArray() {
	bool** answer = new bool*[height];
	for (int i = 0; i<height; i++) {
		answer[i] = new bool[width];
		for (int j = 0; j<width; j++) {
			answer[i][j] = false;
		}
	}

	return answer;
}

void Maze::recursePath(int r, int c, int fr, int fc, bool** answer) {
	answer[r][c] = true;
	if (r == fr && c == fc) {
		done = true;
		return;
	}

	int nr, nc;
	for (int i = 0; i<4; i++) {
		nr = r+dr[i];
		nc = c+dc[i];
		if (!inBounds(nr, nc) || data[nr][nc] || answer[nr][nc]) {
			continue;
		}
		recursePath(nr, nc, fr, fc, answer);
		if (done) {
			return;
		}
	}
	answer[r][c] = false;
	return;
}

bool** Maze::path(int r, int c, int fr, int fc) {
	bool** answer = newBoolArray();
	recursePath(r, c, fr, fc, answer);
	return answer;
}

void Maze::recurseFloodfill(int r, int c, bool** answer) {
	answer[r][c] = true;
	int nr, nc;
	for (int i = 0; i<4; i++) {
		nr = r+dr[i];
		nc = c+dc[i];
		if (!inBounds(nr, nc) || data[nr][nc] || answer[nr][nc]) {
			continue;
		}
		recurseFloodfill(nr, nc, answer);
	}
}

bool** Maze::floodfill_dfs(int r, int c) {
	bool** answer = newBoolArray();
	recurseFloodfill(r, c, answer);
	done = false;
	return answer;
}

bool** Maze::floodfill_bfs(int r, int c) {
	bool** answer = newBoolArray();
	bool** border = newBoolArray();
	border[r][c] = true;
	int nr, nc;
	bool changed = true;

	while (changed) {
		changed = false;
		for (int i = 0; i<height; i++) {
			for (int j = 0; j<width; j++) {
				if (border[i][j]) {
					border[i][j] = false;
					answer[i][j] = true;
					for (int k = 0; k<4; k++) {
						nr = i+dr[k];
						nc = j+dc[k];
						if (!inBounds(nr, nc) || data[nr][nc] || answer[nr][nc]) {
							continue;
						}
						changed = true;
						border[nr][nc] = true;
					}
				}
			}
		}
	}

	delete border;
	return answer;
}
