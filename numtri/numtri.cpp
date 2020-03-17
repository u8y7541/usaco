/*
ID: surya.s1
LANG: C++
TASK: numtri
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int triangle[1000][1000];
int memoize[1000][1000];
int R;

int solve(int r, int c) {
	if (memoize[r][c] != -1) return memoize[r][c];
	if (r == R) {
		return 0;
	}

	int ans = max(solve(r+1, c), solve(r+1, c+1))+triangle[r][c];
	memoize[r][c] = ans;
	return ans;
}

int main(void) {
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	fin>>R;
	for (int i = 0; i<R; i++) {
		for (int j = 0; j<i+1; j++) {
			fin>>triangle[i][j];
		}
	}

	fill((int*)memoize, (int*)memoize+1000*1000, -1);
	fout<<solve(0, 0)<<endl;

	return 0;
}
