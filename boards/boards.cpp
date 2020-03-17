/*
ID: surya.s1
LANG: C++
TASK:
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, P;
int Px1[100011], Py1[100011], Px2[100011], Py2[100011], skip[100011];
bool adj(int a, int b) {
	return (Px2[a]<=Px1[b] && Py2[a]<=Py1[b]);
}

int main(void) {
	ifstream fin("boards.in");
	ofstream fout("boards.out");

	fin>>N>>P;
	for (int i = 0; i<P; i++) {
		fin>>Px1[i]>>Py1[i]>>Px2[i]>>Py2[i];
		skip[i] = Px2[i]+Py2[i]-Px1[i]-Py1[i];
	}
	Px1[P]=N;Px2[P]=N;Py1[P]=N;Py2[P]=N;skip[P]=0;
	Px1[P+1]=0;Px2[P+1]=0;Py1[P+1]=0;Py2[P+1]=0;skip[P+1]=0;
	
	vector<int> adjlist[P+2];
	for (int i = 0; i<P+2; i++) {
		for (int j = 0; j<P+2; j++)
			if (i!=j && adj(i,j)) adjlist[i].push_back(j);
	}

	int totalSkip[P+2];
	fill_n(totalSkip, P+2, -1);
	totalSkip[P+1] = 0;
	queue<int> q;
	q.push(P+1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i<adjlist[cur].size(); i++) {
			int tmp = adjlist[cur][i];
			if (totalSkip[tmp]<0 || totalSkip[tmp]<totalSkip[cur]+skip[tmp]) {
				q.push(tmp);
				totalSkip[tmp] = totalSkip[cur]+skip[tmp];
			}
		}
	}

	fout<<2*N-totalSkip[P]<<endl;

	return 0;
}
