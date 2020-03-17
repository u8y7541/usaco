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

int N, M, C, m[1010], maxm;
vector<int> adjlist[1010];

int totalProfit, totalMoney, totalDays, maxTotalMoney;
void dfs(int start, bool trueStart = true) {
	if (trueStart) {
		totalProfit = 0;
		totalMoney = 0;
		totalDays = -1;
	}
	totalProfit += m[start];
	totalDays++;
	totalMoney = totalProfit - C*totalDays*totalDays;
	//cout<<totalMoney<<endl;
	if (maxm < C*(2*totalDays+1)) return; // Exit path if losing money

	if (start == 0 && !trueStart) {
		//cout<<totalProfit<<' '<<totalDays<<' '<<totalMoney<<endl;
		maxTotalMoney = max(maxTotalMoney, totalMoney);
	}
	for (vector<int>::iterator it = adjlist[start].begin(); it != adjlist[start].end(); it++) {
		int v = *it;
		dfs(v, false);
		totalProfit -= m[v];
		totalDays--;
	}
}

int main(void) {
	ifstream fin("time.in");
	ofstream fout("time.out");

	fin>>N>>M>>C;
	for (int i = 0; i<N; i++) {
		fin>>m[i];
		maxm = max(maxm, m[i]);
	}
	for (int i = 0; i<M; i++) {
		int tmp1, tmp2;
		fin>>tmp1>>tmp2;
		//cout<<tmp1<<tmp2<<endl;
		adjlist[tmp1-1].push_back(tmp2-1);
	}

	// Verts with 0 or 1 outgoing connections or 0 incoming connections are "dead"
	dfs(0);

	fout<<maxTotalMoney;
	fout.close();
	return 0;
}
