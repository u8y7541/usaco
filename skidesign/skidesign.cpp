/*
ID: surya.s1
LANG: C++
TASK: skidesign
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N;

int main(void) {
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");

	fin>>N;
	int hills[N];
	for (int i = 0; i<N; i++) fin>>hills[i];

	sort(hills, hills+N);
	int cost, minCost = -1;
	for (int i = 0; i<84; i++) {
		cost = 0;
		for (int j = 0; j<N; j++) {
			if (hills[j]<i)
				cost += (i-hills[j])*(i-hills[j]);
			if (hills[j]>i+17)
				cost += (hills[j]-i-17)*(hills[j]-i-17);
		}
		if (minCost == -1 || cost < minCost)
			minCost = cost;
	}
	fout<<minCost<<endl;

	return 0;
}
