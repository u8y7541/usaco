#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int T, C, Ts, Te;
	cin>>T>>C>>Ts>>Te;
	int adj[T][T];
	fill((int*)adj, (int*)adj+T*T, 0);
	int tmp1, tmp2, cost;
	for (int i = 0; i<C; i++) {
		cin>>tmp1>>tmp2>>cost;
		adj[tmp1][tmp2] = cost;
		adj[tmp2][tmp1] = cost;
	}
	int dist[T];
	fill(dist, dist+T, 2147483647);
	bool visited[T];
	fill(visited, visited+T, false);
	dist[Ts] = 0;

	int min, newDist;
	bool allVisited = false;
	//while (!allVisited) {
	for (int k = 0; k<10; k++) {
		min = -1;
		for (int j = 0; j<T; j++) {
			if ((min == -1) || (!(visited[j]) && dist[j]<dist[min])) {
				min = j;
			}
		}
		//cout<<min;
		visited[min] = true;
		for (int j = 0; j<T; j++) {
			if (adj[min][j] != 0) {
				newDist = dist[min] + adj[min][j];
				if (newDist<dist[j]) {
					dist[j] = newDist;
				}
			}
		}

		allVisited = true;
		for (int i = 0; i<T; i++) {
			if (visited[i] == false) {
				allVisited = false;
				break;
			}
		}
		for (int i = 0; i<T; i++) {
			//cout<<dist[i]<<endl;
		}
		//cout<<endl;
	}

	cout<<dist[Te];
	return 0;
}
