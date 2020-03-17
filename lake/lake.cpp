#include <iostream>
using namespace std;

int map[100][100];
int M, N;

bool neighbor(int r, int c) {
	bool up, down, left, right;
	up = (r != 0 && map[r-1][c] == '1');
	down = (r != N && map[r+1][c] == '1');
	left = (c != 0 && map[r][c-1] == '1');
	right = (c != M && map[r][c+1] == '1');
	return (up||down||left||right);
}

int floodfill(int r, int c) {
	map[r][c] = '1';
	bool waytogo = true;
	int counter = 1;
	while (waytogo) {
		waytogo = false;
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<M; j++) {
				if (map[i][j] == '#') {
					if (neighbor(i, j)) {
						counter++;
						waytogo = true;
						map[i][j] = '1';
					}
				}
			}
		}
	}
	return counter;
}

int main(void) {
	int K;
	cin>>N>>M>>K;
	int r, c;
	for (int i = 0; i<K; i++) {
		cin>>r>>c;
		map[r-1][c-1] = '#';
	}
	
	int size = 0;
	int largest = 0;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			if (map[i][j] == '#') {
				size = floodfill(i, j);
				if (size>largest) {
					largest = size;
				}
			}
		}
	}
	cout<<largest;

	return 0;
}
