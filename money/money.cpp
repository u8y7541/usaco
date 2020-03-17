/*
ID: surya.s1
LANG: C++
TASK: money
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int V, N;
long long ways[10005];

int main(void) {
	ifstream fin("money.in");
	ofstream fout("money.out");

	fin>>V>>N;
	int coins[V];
	for (int i = 0; i<V; i++) fin>>coins[i];

	ways[0] = 1;
	for (int j = 0; j<V; j++) {
		for (int i = 0; i<N; i++)
			if (i+coins[j] < 10005) ways[i+coins[j]] += ways[i];
	}
	fout<<ways[N]<<endl;

	return 0;
}
