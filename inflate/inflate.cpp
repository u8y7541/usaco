/*
ID: surya.s1
LANG: C++
TASK: inflate
*/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int M, N, pts[MAXN], mins[MAXN];
double val[MAXN];

int main(void) {
	ifstream fin("inflate.in");
	ofstream fout("inflate.out");

	fin>>M>>N;
	for (int i = 0; i<N; i++) {
		fin>>pts[i]>>mins[i];
		val[i] = (double)(pts[i])/mins[i];
	}

	return 0;
}
