#include <bits/stdc++.h>
using namespace std;


int dfs() {


int main(void) {
	/*ifstream fin;
	ofstream fout;
	fin.open("walk.in");
	fout.open("walk.out");*/

	int N, K;
	cin>>N>>K;
	
	int list[(N*(N-1))/2];

	int count = 0;
	for (int x = 1; x<N; i++) {
		for (int y = y+1; y<=N; y++) {
			list[count] = 84*x+48*y;
			count++;
		}
	}
	sort(list, list+(N*(N-1))/2);
