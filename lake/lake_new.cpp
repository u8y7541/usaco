#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
bool farm[100][100];
bool visited[100][100];
int counter, m;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool inBounds(int r, int c) {
	return (0<=r && r<N && 0<=c && c<M);
}

int floodfill(int r, int c) {
	counter++;
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
	cin>>N>>M>>K;
	int x, y;
	for (int i = 0; i<K; i++) {
		cin>>x>>y;
		farm[x-1][y-1] = true;
	}

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			if (farm[i][j] && !visited[i][j]) {
				counter = 0;
				floodfill(i, j);
				if (counter>m) {
					m = counter;
				}
			}
		}
	}
	cout<<m;
}
