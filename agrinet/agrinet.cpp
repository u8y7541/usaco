#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int N;
	cin>>N;
	int adj[N][N];
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			cin>>adj[i][j];
		}
	}

	int dist[N];
	fill(dist, dist+N, 100001);
	bool visited[N];
	fill(visited, visited+N, false);
	int min;
	dist[0] = 0;
	for (int i = 0; i<N; i++) {
		min = -1;
		for (int j = 0; j<N; j++) {
			if (!visited[j]) {
				if (min = -1 || dist[min]>dist[j]) {
					min = j;
				}
			}
		}
		visited[min] = true;

		for (int j = 0; j<N; j++) {
			if (!visited[j]) {
				if (adj[min][j] && adj[min][j]<dist[j]) {
					dist[j] = adj[min][j];
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i<N; i++) {
		sum += dist[i];
	}
	cout<<sum<<endl;
	for (int i = 0; i<N; i++) {
		cout<<dist[i]<<endl;
	}
	return 0;
}
