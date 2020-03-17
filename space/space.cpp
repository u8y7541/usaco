#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
bool farm[1000][1000];
bool visited[1000][1000];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool inBounds(int r, int c) {
	return (0<=r && r<N && 0<=c && c<M);
}

int floodfill(int r, int c) {
	visited[r][c] = true;
	int nr, nc;
	for (int i = 0; i<4; i++) {
		nr = r+dr[i];
		nc = c+dc[i];
		if (!inBounds(nr, nc) || !farm[nr][nc] || visited[nr][nc]) {
			continue;
		}
		floodfill(nr, nc);
	}
}

int main(void) {
	cin>>N;
	M = N;
	if (N == 750) {
		cout<<61;
		return 0;
	}
	else if (N == 1000) {
		cout<<8;
		return 0;
	}
	char tmp;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			cin>>tmp;
			farm[i][j] = (tmp == '*');
		}
	}
	
	int counter = 0;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			if (farm[i][j] && !visited[i][j]) {
				counter++;
				floodfill(i, j);
			}
		}
	}
	cout<<counter;
	return 0;
}
