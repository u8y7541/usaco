/*
ID: surya.s1
LANG: C++
TASK: nocows
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, K;
long long dp[202][102];

int main(void) {
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");

	fin>>N>>K;

	dp[1][1] = 1;
	for (int n = 3; n<N+2; n+=2) {
		for (int k = 2; k<K+2; k++) {
			for (int n1 = 1; n1<n; n1+=2) {
				int n2 = n-n1-1;
				for (int k1 = 1; k1<k; k1++) {
					dp[n][k] += dp[n1][k1]*dp[n2][k-1]*(k1==k-1 ? 1:2)%9901;
				}
			}
			dp[n][k] %= 9901;
		}
	}
	fout<<dp[N][K]<<endl;
	return 0;
}
