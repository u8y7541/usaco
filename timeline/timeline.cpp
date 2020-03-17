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

int N,M,C;
int S[100005];
//int adj[100005][100005];
int memA[100005], memB[100005], memX[100005];

int main(void) {
	ifstream fin("timeline.in");
	ofstream fout("timeline.out");

	fin>>N>>M>>C;
	for (int i = 0; i<N; i++)
		fin>>S[i];

	int a, b, x;
	for (int i = 0; i<C; i++) {
		fin>>memA[i]>>memB[i]>>memX[i];
		memA[i]--; memB[i]--;
		//cout<<memA[i]<<' '<<memB[i]<<' '<<memX[i]<<endl;
		//adj[a-1][b-1] = x;
	}

	int oldMins[N], newMins[N];
	for (int i = 0; i<N; i++) {oldMins[i] = S[i]; newMins[i] = S[i];}

	bool change = false;
	do {
		change = false;
		//cout<<"oldMins: "; printArr<int>(oldMins, N);
		//cout<<"newMins: "; printArr<int>(newMins, N);
		for (int i = 0; i<C; i++) {
			newMins[memB[i]] = max(newMins[memB[i]], oldMins[memA[i]]+memX[i]);
			if (newMins[memB[i]] != oldMins[memB[i]]) {
				change = true;
			}
		}
		copy(newMins, newMins+N, oldMins);
		/*for (int i = 0; i<N; i++) {
			if (oldMins[i] != newMins[i]) change = true; 
			oldMins[i] = newMins[i];
		}*/
	} while (change);
	for (int i = 0; i<N; i++)
		fout<<newMins[i]<<endl;

	fout.close();
	return 0;
}
