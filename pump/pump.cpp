#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, M;
int cost[1010][1010], flow[1010][1010];
bool isPipe(int a, int b) {return cost[a][b];}

int main(void) {
	ifstream fin("pump.in");
	ofstream fout("pump.out");

	fin>>N>>M;
	int a, b;
	for (int i = 0; i<M; i++) {
		fin>>a>>b;
		fin>>cost[a][b];
		fin>>flow[a][b];
		cost[b][a] = cost[a][b]; flow[b][a] = flow[a][b];
	}

	int dpcost[N+1], dpflow[N+1];
	fill_n(dpcost, N+1, -1); fill_n(dpflow, N+1, -1);
	double dpvalue[N+1];
	bool visited[N+1];
	for (int j = 0; j<5; j++) {
	fill_n(visited, N+1, false);
	queue<int> q;
	q.push(1);
	dpcost[1] = 0; dpflow[1] = 1010;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (visited[cur]) {continue;}
		visited[cur] = true;
		for (int i = 1; i<=N; i++) {
			if (isPipe(cur, i)) {
				cout<<"Testing pipe "<<cur<<' '<<i<<endl;
				int joinFlow = min(dpflow[cur],flow[cur][i]);
				int joinCost = dpcost[cur]+cost[cur][i];
				double joinValue = (1000000*(double)joinFlow)/joinCost;
				if (dpcost[i]<0 || dpflow[i]*joinCost < dpcost[i]*joinFlow) {
					dpflow[i] = joinFlow; dpcost[i] = joinCost; dpvalue[i] = joinValue;
				}
				q.push(i);
			}
		}
	}
	}
	printArr<int>(dpcost, N+1);
	printArr<int>(dpflow, N+1);
	fout<<(int)(dpvalue[N])<<endl;

	return 0;
}
/*
Q with next node to visit, each node has dpcost and dpflow
while (q !empty)
	cur = q.pop
	if already visited continue
	visited[cur] = true
	for each connected to cur
		if (never seen node or dpflow/dpcost can be improved)
			update dpflow, dpcost
		add cur to q
*/
