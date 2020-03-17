/*
ID: surya.s1
LANG: C++
TASK: hamming
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, B, D;
bool visited[1000];
ofstream fout("hamming.out");

int hamming(int x, int y) {
	int ans = 0;
	for (; x+y>0; x/=2, y/=2)
		ans += (x^y)&1;
	return ans;
}

int adj(int x, int y) { 
	return hamming(x, y)>=D;
}

bool valid(int x) {
	for (int i = 0; i<(2<<B); i++) {
		if (visited[i] && !adj(x, i)) return false;
	}
	return true;
}

void flood() {
	int i = 0;
	int prevNum = -1;
	for (int x = 0; i<N && x<(2<<B); x++) {
		if (valid(x)) {
			visited[x] = true;
			if (prevNum != -1) fout<<prevNum<<(i%10 == 0 ? '\n':' ');
			prevNum = x;
			i++;
		}
	}
	fout<<prevNum<<endl;
}

int main(void) {
	ifstream fin("hamming.in");

	fin>>N>>B>>D;

	flood();

	return 0;
}
