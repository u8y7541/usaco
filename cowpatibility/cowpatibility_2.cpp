#include <bits/stdc++.h>
using namespace std;

bool share(int f1[5], int f2[5]) {
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			if (f1[i] == f2[j]) {
				return true;
			}
		}
	}
	return false;
}

int main(void) {
	ifstream fin;
	fin.open("cowpatibility.in");
	ofstream fout;
	fout.open("cowpatibility.out");

	int N;
	fin>>N;
	int flavors[N][5];
	for (int i = 0; i<N; i++) {
		fin>>flavors[i][0]>>flavors[i][1]>>flavors[i][2]>>flavors[i][3]>>flavors[i][4];
	}
	fin.close();

	int answer = 0;
	for (int i = 0; i<N-1; i++) {
		for (int j = i+1; j<N; j++) {
			if (!share(flavors[i], flavors[j])) {
				answer++;
			}
		}
	}

	fout<<answer;
	fout.close();
	return 0;
}
