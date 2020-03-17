/*
ID: surya.s1
LANG: C++
TASK: sort3
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, num[4];

int lookingFor(int i) { return (i<num[1] ? 1:(i<num[1]+num[2] ? 2:3)); }

int main(void) {
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");

	fin>>N;
	int arr[N];
	for (int i = 0; i<N; i++) {
		fin>>arr[i];
		num[arr[i]]++;
	}
	
	int swaps = 0;
	for (int i = 0; i<N; i++) {
		int looking = lookingFor(i);
		if (looking == arr[i]) continue;
		for (int j = i+1; j<N; j++) {
			if (arr[j] == looking && lookingFor(j) == arr[i]) {
				arr[j] = arr[i];
				arr[i] = looking;
				swaps++;
				break;
			}
		}
	}
	for (int i = 0; i<N; i++) {
		if (arr[i] == lookingFor(i)) continue;
		for (int j = 0; j<N; j++) {
			if (i == j) continue;
			if (arr[j] == lookingFor(j)) continue;
			for (int k = 0; k<N; k++) {
				if (i == j || j == k || i == k) continue;
				if (arr[k] == lookingFor(k)) continue;
				if (arr[j] == lookingFor(i) && arr[k] == lookingFor(j) && arr[i] == lookingFor(k)) {
					arr[i] = lookingFor(i);
					arr[j] = lookingFor(j);
					arr[k] = lookingFor(k);
					swaps+=2;
				}
			}
		}
	}
	fout<<swaps<<endl;

	return 0;
}
