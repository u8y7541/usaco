/*
ID: surya.s1
LANG: C++
TASK: milk3
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int A,B,C;
bool answers[25];
set<tuple<int, int, int>> seen;

void solve(int a, int b, int c) {
	if (seen.find(make_tuple(a,b,c)) != seen.end()) return;
	seen.insert(make_tuple(a,b,c));
	if (a == 0) {
		if (answers[c]) return;
		else answers[c] = true;
	}

	solve(a, min(b+c, B), b+c-min(b+c, B));
	solve(a, b+c-min(b+c, C), min(b+c, C));
	solve(min(a+b, A), a+b-min(a+b, A), c);
	solve(a+b-min(a+b, B), min(a+b, B), c);
	solve(min(a+c, A), b, a+c-min(a+c, A));
	solve(a+c-min(a+c, C), b, min(a+c, C));
}

int main(void) {
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	fin>>A>>B>>C;
	solve(0, 0, C);
	int max = 0;
	for (int i = 0; i<25; i++) if (answers[i]) max = i;
	for (int i = 0; i<max; i++) {
		if (answers[i]) fout<<i<<' ';
	}
	fout<<max<<endl;

	return 0;
}
