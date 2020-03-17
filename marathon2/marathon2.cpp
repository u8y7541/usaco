#include <iostream>
#include <stdlib.h>
using namespace std;

int map[100000][2];
int manhattan(int i, int j) {
	return abs(map[i][0]-map[j][0]) + abs(map[i][1]-map[j][1]);
}

int main(void) {
	int N;
	cin>>N;
	for (int i = 0; i<N; i++) {
		cin>>map[i][0]>>map[i][1];
	}
	
	int totalDist = 0;
	for (int i = 0; i<N-1; i++) {
		totalDist += manhattan(i, i+1);
	}

	int best = 0;
	for (int i = 1; i<N-1; i++) {
		int dist1 = manhattan(i-1, i) + manhattan(i, i+1);
		int dist2 = manhattan(i-1, i+1);
		if ((dist1-dist2) > best) {
			best = dist1-dist2;
		}
	}

	cout<<totalDist - best;
	return 0;
}
