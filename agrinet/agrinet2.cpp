/*
ID: surya.s1
LANG: C++
TASK: agrinet
*/
#include <bits/stdc++.h>
using namespace std;

#define INF 200000
#define MAXN 100

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, adj[MAXN][MAXN];

int MST(int start) {
	int dist[N], source[N], treesize = 0, treecost = 0;
	bool visited[N];
	fill_n(dist, N, INF);
	fill_n(source, N, -1);
	fill_n(visited, N, false);
	dist[start] = 0; source[start] = 0;

	while (treesize<N) {
		int cur = -1;
		for (int i = 0; i<N; i++)
			if (!visited[i] && (cur<0 || dist[i]<dist[cur])) cur = i;
		visited[cur] = true;
		treesize++;
		treecost += dist[cur];

		for (int i = 0; i<N; i++) {
			if (!visited[i] && dist[i] > adj[cur][i]) {
				dist[i] = adj[cur][i];
				source[i] = cur;
			}
		}
	}
	return treecost;
}

int main(void) {
	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");

	fin>>N;
	for (int i = 0; i<N*N; i++)
		fin>>adj[i/N][i%N];

	fout<<MST(0)<<endl;

	return 0;
}
