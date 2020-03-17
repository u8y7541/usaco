/*
ID: surya.s1
LANG: C++
TASK: sprime
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, cur, depth;
int digitPrimes[4] = {2, 3, 5, 7};
int odds[5] = {1, 3, 5, 7, 9};
ofstream fout("sprime.out");

bool isPrime(int x) {
	for (int i = 2; i*i<=x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}

void solve() {
	if (!isPrime(cur)) return;
	if (depth == N) { 
		fout<<cur<<endl;
		return;
	}
	if (depth == 0) {
		for (int i = 0; i<4; i++) {
			cur = digitPrimes[i];
			depth++;
			solve();
			depth--;
		}
		return;
	}
	cur *= 10;
	for (int i = 0; i<5; i++) {
		cur += odds[i];
		depth++;
		solve();
		depth--;
		cur -= odds[i];
	}
	cur /= 10;
}

int main(void) {
	ifstream fin("sprime.in");

	fin>>N;

	solve();

	return 0;
}
