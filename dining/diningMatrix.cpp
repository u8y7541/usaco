#include <bits/stdc++.h>
using namespace std;

int N, M, K;
void shortestPath(int a, int answerList[], int length, int* adjMatrix) {
	int dist[N];
	fill(dist, dist+N, -1);
	bool visited[N];
	fill(visited, visited+N, false);
	int cur;
	dist[a] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push(make_pair(0, a));

	while (!q.empty()) {
		cur = (q.top()).second;
		q.pop();

		for (int i = 0; i<N; i++) {
			if (!visited[i] && adjMatrix[cur*N+i] > 0 && (dist[i] == -1 || dist[cur] + adjMatrix[cur*N+i] < dist[i])) {
				dist[i] = dist[cur] + adjMatrix[cur*N+i];
				q.push(make_pair(dist[i], i));
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
	int adjMatrix[N][N];
	fill((int*)adjMatrix, (int*)adjMatrix+N*N, 0);
	int a, b, t;
	for (int i = 0; i<M; i++) {
		fin>>a>>b>>t;
		adjMatrix[a-1][b-1] = t;
		adjMatrix[b-1][a-1] = t;
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
	shortestPath(N-1, yummyDists, K, (int*)adjMatrix);

	int cowDists[N-1][K]; //cow distances to each haystack
	for (int i = 0; i<N-1; i++) {
		for (int j = 0; j<K; j++) {
			cowDists[i][j] = yummyList[j][0];
		}
		shortestPath(i, cowDists[i], K, (int*)adjMatrix);
	}

	int shortestDists[N-1]; //cow distances to barn
	for (int i = 0; i<N-1; i++) {shortestDists[i] = i;}
	shortestPath(N-1, shortestDists, N-1, (int*)adjMatrix);

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
