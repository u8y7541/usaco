#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0 , -1, 0};

int N;

class Maze {
	private:
		int width, height;
		int** data;
		bool done;
		void recurseFloodfill(int r, int c, bool** answer, int num1, int num2); 
		bool** newBoolArray();

	public:
		Maze(int x, int y, int* maze);
		bool inBounds(int r, int c);
		bool** floodfill_dfs(int r, int c, int num1, int num2);
};

Maze::Maze(int x, int y, int* maze) {
	height = x;
	width = y;
	done = false;
	data = new int*[height];
	for (int i = 0; i<height; i++) {
		data[i] = new int[width];
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

void Maze::recurseFloodfill(int r, int c, bool** answer, int num1, int num2) {
	answer[r][c] = true;
	int nr, nc;
	for (int i = 0; i<4; i++) {
		nr = r+dr[i];
		nc = c+dc[i];
		if (!inBounds(nr, nc) || (data[nr][nc] != num1 && data[nr][nc] != num2) || answer[nr][nc]) {
			continue;
		}
		recurseFloodfill(nr, nc, answer, num1, num2);
	}
}

bool** Maze::floodfill_dfs(int r, int c, int num1, int num2) {
	bool** answer = newBoolArray();
	recurseFloodfill(r, c, answer, num1, num2);
	done = false;
	return answer;
}

bool regionsTouching(bool** region1, bool** region2) {
	int nr, nc;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			for (int k = 0; k<4; k++) {
				nr = i+dr[k];
				nc = j+dc[k];
				if (nr>N-1 || nr<0 || nc>N-1 || nc<0 || !region2[nr][nc]) {
					continue;
				}
				return true;
			}
		}
	}
	return false;
}

int main(void) {
	ifstream fin;
	fin.open("multimoo.in");
	ofstream fout;
	fout.open("multimoo.out");
	fin>>N;
	int board[N][N];
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			fin>>board[i][j];
		}
	}
	fin.close();
	/*for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			cout<<board[i][j];
		}
		cout<<endl;
	}*/

	Maze b(N, N, (int*)board);
	bool combined[N][N];
	memset(combined, false, N*N);
	vector<int> ids;
	bool** flood;
	int counter, max = 0;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			if (!combined[i][j]) {
				flood = b.floodfill_dfs(i, j, board[i][j], -1);
				if (find(ids.begin(), ids.end(), board[i][j]) == ids.end()) {
					ids.push_back(board[i][j]);
				}
				
				counter = 0;
				for (int x = 0; x<N; x++) {
					for (int y = 0; y<N; y++) {
						if (flood[x][y]) {
							combined[x][y] = true;
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
	fout<<max<<endl;
	
	bool** regions[ids.size()];
	for (int i = 0; i<ids.size(); i++) {
		regions[i] = (bool**)malloc(N*sizeof(bool*));
		for (int j = 0; j<N; j++) {
			regions[i][j] = (bool*)malloc(N*sizeof(bool));
			for (int k = 0; k<N; k++) {
				regions[i][j][k] = false;
			}
		}
	}
	/*int reverseID[ids.size()+3];
	for (int i = 0; i<ids.size(); i++) {
		reverseID[ids[i]] = i;
	}*/
	/*for (int i = 0; i<ids.size(); i++) {
		cout<<ids[i]<<' ';
	}
	cout<<endl;*/
	for (int x = 0; x<N; x++) {
		for (int y = 0; y<N; y++) {
			regions[find(ids.begin(), ids.end(), board[x][y])-ids.begin()][x][y] = true;
		}
	}
	
	/*for (int i = 0; i<ids.size(); i++) {
		for (int x = 0; x<N; x++) {
			for (int y = 0; y<N; y++) {
				cout<<regions[i][x][y];
			}
			cout<<endl;
		}
		cout<<endl;
	}*/

	int max2 = 0;
	for (int i = 0; i<ids.size(); i++) {
		for (int j = i; j<ids.size(); j++) {
			if (regionsTouching(regions[i], regions[j])) {
				counter = 0;
				bool** tmp;
				bool bl = false;
				for (int x = 0; x<N; x++) {
					for (int y = 0; y<N; y++) {
						if (regions[i][x][y]) {
							tmp = b.floodfill_dfs(x, y, ids[i], ids[j]); 
							bl = true;
							break;
						}
					}
					if (bl) {break;}
				}
				for (int x = 0; x<N; x++) {
					for (int y = 0; y<N; y++) {
						if (tmp[x][y]) {
							counter++;
						}
					}
				}
				if (counter>max2) {
					max2 = counter;
				}
				delete tmp;
			}
		}
	}
	fout<<max2;
	fout.close();

	return 0;
}
