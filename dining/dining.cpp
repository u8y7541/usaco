#include <bits/stdc++.h>
using namespace std;

int N, M, K;
void shortestPath(int a, int answerList[], int length, int adjList[][3]) {
	int dist[N];
	fill(dist, dist+N, -1);
	bool visited[N];
	fill(visited, visited+N, false);
	int cur;
	dist[a] = 0;

	while (true) {
		int minIndex = -1;
		for (int i = 0; i<N; i++) {
			if (dist[i] != -1 && !visited[i] && (minIndex == -1 || dist[minIndex] > dist[i])) {
				minIndex = i;
			}
		}
		cur = minIndex;
		if (cur == -1) {
			break;
		}
		int other;
		for (int i = 0; i<M; i++) {
			other = 2;
			if (adjList[i][0] == cur) {
				other = 1;
			}
			if (adjList[i][1] == cur) {
				other = 0;
			}
			if (other < 2) {
				if (visited[adjList[i][other]]) {
					continue;
				}
				if (dist[adjList[i][other]] == -1 || dist[adjList[i][other]] > dist[cur] + adjList[i][2]) {
					dist[adjList[i][other]] = dist[cur] + adjList[i][2];
				}
			}
		}
		visited[cur] = true;
	}

	for (int i = 0; i < length; i++) {
		answerList[i] = dist[answerList[i]];
	}
}

int main(void) {
	ifstream fin;
	fin.open("dining.in");
	ofstream fout;
	fout.open("dining.out");

	fin>>N>>M>>K;
	int adjList[M][3];
	for (int i = 0; i<M; i++) {
		fin>>adjList[i][0]>>adjList[i][1]>>adjList[i][2];
		adjList[i][0]--;
		adjList[i][1]--;
	}
	int yummyList[K][2];
	for (int i = 0; i<K; i++) {
		fin>>yummyList[i][0]>>yummyList[i][1];
		yummyList[i][0]--;
	}
	fin.close();

	int yummyDists[K]; //haystack distances to barn
	for (int i = 0; i<K; i++) {
		yummyDists[i] = yummyList[i][0];
	}
	shortestPath(N-1, yummyDists, K, adjList);

	int cowDists[N-1][K]; //cow distances to each haystack
	for (int i = 0; i<N-1; i++) {
		for (int j = 0; j<K; j++) {
			cowDists[i][j] = yummyList[j][0];
		}
		shortestPath(i, cowDists[i], K, adjList);
	}

	int shortestDists[N-1]; //cow distances to barn
	for (int i = 0; i<N-1; i++) {shortestDists[i] = i;}
	shortestPath(N-1, shortestDists, N-1, adjList);

	int answers[N-1];
	for (int i = 0; i<N-1; i++) {
		answers[i] = 0;
		for (int j = 0; j<K; j++) {
			if (cowDists[i][j] + yummyDists[j] - shortestDists[i] <= yummyList[j][1]) {
				answers[i] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < N-1; i++) {
		fout<<answers[i]<<endl;
	}

	fout.close();
	return 0;
}
