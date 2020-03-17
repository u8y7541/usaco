#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0 , -1, 0};

class Maze {
	private:
		int width, height;
		bool** data;
		bool** pathAnswer;
		bool done;
		bool** newBoolArray();

	public:
		Maze(int x, int y, bool* maze);
		bool inBounds(int r, int c);
		int floodfill_bfs(int r, int c);
};

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

int Maze::floodfill_bfs(int r, int c) {
	bool** answer = newBoolArray();
	bool** border = newBoolArray();
	border[r][c] = true;
	int nr, nc;
	bool changed = true;
	int iterations = 0;

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
		iterations++;
	}

	delete border;
	delete answer;
	return iterations;
}

int main(void) {
	int X, Y, Mx, My;
	cin>>X>>Y>>Mx>>My;
	Mx -= 1;
	My = Y - My;
	bool farm[X][Y];
	char tmp;
	for (int i = 0; i<X; i++) {
		for (int j = 0; j<Y; j++) {
			cin>>tmp;
			farm[i][j] = (tmp == '*');
		}
	}
	Maze m(X, Y, (bool*)farm);

	cout<<m.floodfill_bfs(Mx, My);
}
