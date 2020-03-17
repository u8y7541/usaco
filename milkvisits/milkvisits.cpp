#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, M;
int parent[100002], depth[100002];
bool isHappy(int start, int end, int preference, int* T) {
	int lower, higher;
	if (depth[start]<depth[end]) {
		higher = start;
		lower = end;
	}
	else {
		higher = end;
		lower = start;
	}
	while (depth[higher] != depth[lower]) {
		if (T[lower] == preference) return true;
		lower = parent[lower];
	}
	while (higher != lower) {
		if (T[lower] == preference || T[higher] == preference) return true;
		higher = parent[higher]; lower = parent[lower];
	}
	return T[higher] == preference;
}

int main(void) {
	ifstream fin("milkvisits.in");
	ofstream fout("milkvisits.out");

	fin>>N>>M;
	int T[N+1];
	for (int i = 1; i<=N; i++) fin>>T[i];
	vector<int> edges[N+1];
	int a, b;
	for (int i = 0; i<N-1; i++) {
		fin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	int A[M], B[M], C[M];
	for (int i = 0; i<M; i++) {
		fin>>A[i]>>B[i]>>C[i];
	}

	// Tree-ify
	parent[1] = 1; depth[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i<edges[cur].size(); i++) {
			int node = edges[cur][i];
			if (depth[node]<1) {
				depth[node] = depth[cur]+1;
				parent[node] = cur;
				q.push(node);
			}
		}
	}
	//printArr<int>(depth, N+1);
	//printArr<int>(parent, N+1);

	for (int i = 0; i<M; i++) {
		if (isHappy(A[i], B[i], C[i], T)) fout<<1;
		else fout<<0;
	}
	fout<<endl;

	return 0;
}
