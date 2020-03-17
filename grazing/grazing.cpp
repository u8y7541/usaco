#include <iostream>
using namespace std;

bool maze[5][5];
bool visited[5][5];
int K;
int counter = 0;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int r, int c, int nsteps) {
	if (r>4 || r<0 || c>4 || c<0 || maze[r][c] || visited[r][c]) {
		return;
	}
	if (r+c==8 && nsteps == 24 - K) {
		counter++;
		return;
	}

	/*if (r+c == 8) {
		cout<<nsteps<<endl;
		for (int i = 0; i<5; i++) {
			for (int j = 0; j<5; j++) {
				if (maze[i][j]) {
					cout<<" x ";
				}
				else if (i == r && j == c) {
					cout<<" B ";
				}
				else if (visited[i][j]) {
					cout<<" V ";
				}
				else {
					cout<<" . ";
				}
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}*/

	visited[r][c] = true;
	for (int i = 0; i<4; i++) {
		dfs(r+dr[i], c+dc[i], nsteps+1);
	}
	visited[r][c] = false;
}

int main(void) {
	cin>>K;
	int x = 0, y = 0;
	for (int i = 0; i<K; i++) {
		cin>>x>>y;
		maze[x-1][y-1] = true;
	}
	/*for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			if (maze[i][j]) {
				cout<<" x ";
			}
			else {
				cout<<" . ";
			}
		}
		cout<<endl;
	}*/

	dfs(0, 0, 0);
	cout<<counter;

	return 0;
}
