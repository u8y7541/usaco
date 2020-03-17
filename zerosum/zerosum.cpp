/*
ID: surya.s1
LANG: C++
TASK: zerosum
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, blanks[8];

bool test() {
	int actual[N];
	actual[0] = 1;
	int num = 0;
	for (int i = 0; i<N-1; i++) {
		if (blanks[i]<2) {
			actual[++num] = i+2;
		}
		else {
			actual[num] *= 10;
			actual[num] += i+2;
		}
	}

	int ans = actual[0];
	int counter = 0;
	for (int i = 0; i<N-1; i++) {
		if (blanks[i] == 2) continue;
		if (!blanks[i])
			ans += actual[++counter];
		if (blanks[i] == 1)
			ans -= actual[++counter];
	}
	return !ans;
}

int main(void) {
	ifstream fin("zerosum.in");
	ofstream fout("zerosum.out");

	fin>>N;

	for (int i = 0; i<pow(3, N-1); i++) {
		int data = i;
		for (int j = 0; j<N-1; j++) {
			blanks[N-2-j] = (data+2)%3;
			data /= 3;
		}
		if (test()) {
			for (int j = 0; j<N-1; j++)
				fout<<j+1<<(blanks[j] == 0 ? '+':(blanks[j] == 1 ? '-':' '));
			fout<<N<<endl;
		}
	}

	return 0;
}
