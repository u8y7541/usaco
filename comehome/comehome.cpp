/*
ID: surya.s1
LANG: C++
TASK: comehome
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int P, adj[128][128];
char minDistChar = 0;

int minDist(int start) {
	int dist[128];
	fill_n(dist, 128, -1);
	queue<int> q;
	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i<128; i++) {
			if (adj[cur][i] && (dist[i] == -1 || dist[i]>dist[cur]+adj[cur][i])) {
				dist[i] = dist[cur]+adj[cur][i];
				q.push(i);
			}
		}
	}

	int minDist = -1;
	for (int i = 0; i<90; i++) {
		if (dist[i]<0) continue;
		if (minDist<0 || dist[i]<minDist) {
			minDist = dist[i];
			minDistChar = (char)i;
		}
	}
	return minDist;
}

int main(void) {
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");

	fin>>P;
	char tmp1, tmp2;
	int dist;
	for (int i = 0; i<P; i++) {
		fin>>tmp1>>tmp2>>dist;
		adj[tmp1][tmp2] = min(adj[tmp1][tmp2], dist);
		if (!adj[tmp1][tmp2])
			adj[tmp1][tmp2] = dist;
		adj[tmp2][tmp1] = adj[tmp1][tmp2];
	}

	int min = minDist((int)'Z');
	fout<<minDistChar<<' '<<min<<endl;

	return 0;
}
