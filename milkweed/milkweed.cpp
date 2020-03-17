#include <iostream>
using namespace std;

char m[100][100];
int M, N;

bool neighbor(int r, int c) {
	bool up, down, left, right;
	up = (r != 0 && m[r-1][c] == '1');
	down = (r != N && m[r+1][c] == '1');
	left = (c != 0 && m[r][c-1] == '1');
	right = (c != M && m[r][c+1] == '1');
	return (up||down||left||right);
}

int floodfill(int r, int c) {
	m[r][c] = '1';
	bool waytogo = true;
	int counter = 1;
	int nod = 0;
	while (waytogo) {
		waytogo = false;
		nod++;
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<M; j++) {
				if (m[i][j] == '*') {
					if (neighbor(i, j)) {
						counter++;
						waytogo = true;
						m[i][j] = '+';
					}
				}
			}
		}
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<M; j++) {
				if (m[i][j]=='+') {
					m[i][j] = '1';
				}
			}
		}
	}
	return nod;
}

int main(void) {
	int Mx, My;
	cin>>M>>N>>Mx>>My;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			cin>>m[i][j];
		}
	}
	cout<<floodfill(N-Mx, My-1);

	return 0;
}
