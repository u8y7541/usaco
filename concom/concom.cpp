/*
ID: surya.s1
LANG: C++
TASK: concom
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N;
int graph[105][105];
int ownage[105];
bool visited[105];
bool info[105];

void owns(int x) {
	if (visited[x]) return;
	visited[x] = true;
	if (!info[x]) return;
	for (int i = 0; i<105; i++) {
		if (x == i) continue;
		ownage[i] += graph[x][i];
		if (ownage[i] > 50) owns(i);
	}
}

int main(void) {
	ifstream fin("concom.in");
	ofstream fout("concom.out");

	fin>>N;
	int tmp1,tmp2,tmp3;
	for (int i = 0; i<N; i++) {
		fin>>tmp1>>tmp2>>tmp3;
		graph[tmp1][tmp2]=tmp3;
		info[tmp1] = true;
	}

	for (int i = 0; i<105; i++) {
		fill_n(ownage, 105, 0);
		fill_n(visited, 105, false);
		owns(i);
		for (int j = 0; j<105; j++) {
			if (ownage[j]>50 && i != j)
				fout<<i<<' '<<j<<endl;
		}
	}

	return 0;
}
