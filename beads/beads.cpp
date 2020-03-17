/*
ID: surya.s1
LANG: C++
TASK: beads
*/
#include <bits/stdc++.h>
using namespace std;

int findSum(char* beads, int N, int breakPoint) {
	// breakPoint = 1 -> break between 0 and 1
	int rightTotal = 0, leftTotal = 0;

	char rightColor = beads[breakPoint%N], leftColor = beads[(breakPoint+N-1)%N];
	if (rightColor == 'w') {
		for (int i = (breakPoint+1)%N; i!=breakPoint%N; i++, i%=N) {
			if (beads[i] != 'w') {
				rightColor = beads[i];
				break;
			}
		}
	}
	if (leftColor == 'w') {
		for (int i = (breakPoint+N-2)%N; i!=(breakPoint+N-1)%N; i--, i+=N, i%=N) {
			if (beads[i] != 'w') {
				leftColor = beads[i];
				break;
			}
		}
	}

	for (int i = breakPoint%N; (beads[i] == rightColor || beads[i] == 'w') && !(i == breakPoint%N && rightTotal>0); i++, i%=N, rightTotal++);
	for (int i = (breakPoint+N-1)%N; (beads[i] == leftColor || beads[i] == 'w') && !(i == (breakPoint+N-1)%N && leftTotal>0); i--, i+=N, i%=N, leftTotal++);
	return (rightTotal+leftTotal>N ? N:rightTotal+leftTotal);
}

int main(void) {
	ifstream fin("beads.in");
	ofstream fout("beads.out");

	int N;
	fin>>N;
	char beads[N];
	for (int i = 0; i<N; i++) {
		fin>>beads[i];
	}

	int max = 0, sum = 0;
	for (int i = 0; i<N; i++) {
		sum = findSum(beads, N, i);
		if (sum > max) {
			max = sum;
		}
	}
	fout<<max<<endl;

	return 0;
}
