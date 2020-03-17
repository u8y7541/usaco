/*
ID: surya.s1
LANG: C++
TASK: subset
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N;
long long numWays[1000];

int main(void) {
	ifstream fin("subset.in");
	ofstream fout("subset.out");

	fin>>N;
	if (N%4 == 1 || N%4 == 2) {
		fout<<0<<endl;
		return 0;
	}

	numWays[0] = 1;
	for (int i = 1; i<=N; i++) {
		for (int j = (N*N+N)/2-i; j>=0; j--)
			numWays[i+j] += numWays[j];
	}
	fout<<numWays[(N*N+N)/4]/2<<endl;

	return 0;
}
