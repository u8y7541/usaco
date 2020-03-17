/*
ID: surya.s1
LANG: C++
TASK: ariprog
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, M, num=0;
ofstream fout("ariprog.out");

void solve(bool* bsqs, int* bNums) {
	bool written = false;
	for (int diff = 1; diff<2*M*M+1; diff++) {
		if (N>4 && diff%4 > 0) continue;
		for (int i = 0; i<num; i++) {
			bool found = true;
			if (bNums[i]+diff*(N-1)>2*M*M) continue;
			for (int j = 0; j<N; j++) {
				if (!bsqs[bNums[i]+diff*j]) {found = false; break;}
			}
			if (!found) continue;
			fout<<bNums[i]<<' '<<diff<<endl;
			written = true;
		}
	}
	if (!written) fout<<"NONE"<<endl;
}


int main(void) {
	ifstream fin("ariprog.in");

	fin>>N>>M;

	bool bsqs[2*M*M];
	int bNums[(M+1)*(M+2)/2];
	fill(bsqs, bsqs+2*M*M, false);
	for (int i = 0; i<=M; i++) {
		for (int j = i; j<=M; j++) {
			if (!bsqs[i*i+j*j]) {
				bNums[num] = i*i+j*j;
				bsqs[i*i+j*j]=true;
				num++;
			}
		}
	}
	sort(bNums, bNums+num);
	solve(bsqs, bNums);

	return 0;
}
