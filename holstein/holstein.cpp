/*
ID: surya.s1
LANG: C++
TASK: holstein
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int V, G;
int reqs[1000];
int feeds[15][1000];
bool visited[20][20];
int ansNum, minAns;
int depth = -1;
int cur[1000];
int minFeeds = 20;
ofstream fout("holstein.out");

bool valid() {
	for (int i = 0; i<V; i++)
		if (cur[i]<reqs[i]) return false;
	return true;
}

void dfs(int start) {
	if (minFeeds<depth+1) return;
	if (start != -1)
		visited[ansNum][start] = true;
	if (valid()) {
		if (minFeeds>depth) {
			minFeeds = depth;
			minAns = ansNum;
		}
		ansNum++;
		memcpy(visited[ansNum], visited[ansNum-1], G);
	}

	depth++;
	for (int i = start+1; i<G; i++) {
		for (int j = 0; j<V; j++)
			cur[j] += feeds[i][j];
		dfs(i);
		for (int j = 0; j<V; j++)
			cur[j] -= feeds[i][j];
	}
	depth--;
	visited[ansNum][start] = false;
}

int main(void) {
	ifstream fin("holstein.in");

	fin>>V;
	for (int i = 0; i<V; i++) fin>>reqs[i];
	fin>>G;
	for (int i = 0; i<V*G; i++) fin>>feeds[i/V][i%V];

	dfs(-1);
	fout<<minFeeds+1;
	for (int i = 0; i<G; i++) {
		if (visited[minAns][i])
			fout<<' '<<i+1;
	}
	fout<<endl;
	
	return 0;
}
