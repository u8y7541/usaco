/*
ID: surya.s1
LANG: C++
TASK: combo
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, f1, f2, f3, m1, m2, m3;

int near(int x, int c) {
	if (abs(x-c)<3) return true;
	if (N-abs(x-c)<3) return true;
	return false;
}

bool validCombo(int x1, int x2, int x3) {
	return ((near(x1,f1) && near(x2,f2) && near(x3,f3)) ||
			(near(x1,m1) && near(x2,m2) && near(x3,m3)));
}

int main(void) {
	ifstream fin("combo.in");
	ofstream fout("combo.out");

	fin>>N>>f1>>f2>>f3>>m1>>m2>>m3;
	int total = 0;
	for (int i = 0; i<N*N*N; i++) {
		if (validCombo(i%N+1, (i/N)%N+1, i/(N*N))) total++;
	}
	fout<<total<<endl;

	return 0;
}
