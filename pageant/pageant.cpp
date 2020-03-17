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

int abs(int x) {
	if (x>0) {
		return x;
	}
	return -x;
}

int main(void) {
	int N, M;
	cin>>N>>M;
	bool hide[N][M];
	char tmp;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			cin>>tmp;
			hide[i][j] = (tmp == '.');
		}
	}
	Maze maze(N, M, (bool*)hide);
	int r, c;
	bool found = false;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			if (!hide[i][j]) {
				r = i;
				c = j;
				found = true;
				break;
			}
		}
		if (found) {break;}
	}
	found = false;

	bool** region1;
	region1 = maze.floodfill_bfs(r, c);

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			if (!hide[i][j] && !region1[i][j]) {
				r = i;
				c = j;
				found = true;
				break;
			}
		}
		if (found) {break;}
	}

	bool** region2;
	region2 = maze.floodfill_bfs(r, c);
	
	int min = -1;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			for (int i1 = 0; i1<N; i1++) {
				for (int j1 = 0; j1<M; j1++) {
					if (region1[i][j] && region2[i1][j1]) {
						if (abs(i-i1)+abs(j-j1)<min || min == -1) {
							min = abs(i-i1)+abs(j-j1);
						}
					}
				}
			}
		}
	}

	cout<<min-1;
	
	delete region1;
	delete region2;
	return 0;
}
