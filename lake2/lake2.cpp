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
		bool** floodfill_bfs(int r, int c);
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

int main(void) {
	int N, M, K;
	cin>>N>>M>>K;
	bool lakes[N][M];
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			lakes[i][j] = true;
		}
	}
	int x, y;
	for (int i = 0; i<K; i++) {
		cin>>x>>y;
		lakes[x-1][y-1] = false;
	}
	Maze m(N, M, (bool*)lakes);
	int counter, max = 0;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			if (lakes[i][j] == false) {
				bool** flood;
				counter = 0;
				flood = m.floodfill_bfs(i, j);
				for (int x = 0; x<N; x++) {
					for (int y = 0; y<M; y++) {
						if (flood[x][y]) {
							counter++;
						}
					}
				}
				if (counter>max) {
					max = counter;
				}
				delete flood;
			}
		}
	}

	cout<<counter;
	return 0;
}

