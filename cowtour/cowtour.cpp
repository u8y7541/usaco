/*
ID: surya.s1
LANG: C++
TASK: cowtour
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, loc[151][2], num, regions[151];
double adj[151][151], maxes[151];

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void FW_max() {
	double path[N][N];
	for (int i = 0; i<N*N; i++)
		path[i/N][i%N] = adj[i/N][i%N];

	for (int k = 0; k<N; k++) {
		for (int i = 0; i<N; i++) {
			if (path[i][k] == -1) continue;
			for (int j = 0; j<N; j++) {
				if (i == j) continue;
				if (path[k][j]==-1) continue;
				if (path[i][j]==-1 || path[i][k]+path[k][j]<path[i][j])
					path[i][j] = path[i][k]+path[k][j];
			}
		}
	}

	for (int i = 0; i<N; i++) {
		double maxDist = 0;
		for (int j = 0; j<N; j++)
			maxDist = max(maxDist, path[i][j]);
		maxes[i] = maxDist;
	}
}

void flood(int x) {
	num++;
	queue<int> q;
	q.push(x);
	regions[x] = num;
	bool visited[N];
	fill_n(visited, N, false);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		visited[cur] = true;

		for (int i = 0; i<N; i++) {
			if (adj[cur][i]>0 && !visited[i]) {
				regions[i] = num;
				q.push(i);
			}
		}
	}
}

void floodAll() {
	fill_n(regions, N, 0);
	num = 0;
	for (int i = 0; i<N; i++) {
		if (!regions[i])
			flood(i);
	}
}

int main(void) {
	ifstream fin("cowtour.in");
	ofstream fout("cowtour.out");

	fin>>N;
	for (int i = 0; i<N; i++) fin>>loc[i][0]>>loc[i][1];
	char tmp;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			fin>>tmp;
			if (tmp>'0')
				adj[i][j] = dist(loc[i][0],loc[i][1],loc[j][0],loc[j][1]); 
			else
				adj[i][j] = -1;
		}
	}

	FW_max();
	floodAll();
	double diameters[num+1];
	fill_n(diameters, num+1, 0);
	for (int i = 0; i<N; i++)
		diameters[regions[i]] = max(diameters[regions[i]],maxes[i]);

	double minDiameter = -1;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			if (regions[i] == regions[j]) continue;
			double distance = dist(loc[i][0],loc[i][1],loc[j][0],loc[j][1]);
			double newMin = max(diameters[regions[i]], distance+maxes[i]+maxes[j]); 
			newMin = max(newMin, diameters[regions[j]]);
			minDiameter = min(minDiameter, newMin);
			if (minDiameter == -1)
				minDiameter = newMin;
		}
	}
	char str[50];
	sprintf(str, "%.6f", minDiameter);
	fout<<str<<endl;

	return 0;
}
