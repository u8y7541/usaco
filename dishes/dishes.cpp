#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream fin;
	ofstream fout;
	fin.open("dishes.in");
	fout.open("dishes.out");

	int N;
	fin>>N;
	int pileBases[N+1]; // 0 is the first pile base
	int theRest[N]; // not pile bases
	fill(pileBases, pileBases+N+1, 0);
	fill(theRest, theRest+N, 0);
	int baseNum = 0, dishNum;
	bool findingBases = true;
	for (int i = 0; i<N; i++) {
		fin>>dishNum;
		if (findingBases && dishNum>pileBases[baseNum]) {
			baseNum++;
			pileBases[baseNum] = dishNum;
			continue;
		}
		else {
			findingBases = false;
		}
		theRest[i-baseNum] = dishNum;
	}
	fin.close();

	bool marked[N];
	fill(marked, marked+N, false);
	fill(marked, marked+baseNum, true);

	for (int i = 1; i<baseNum+1; i++) {
		int current = pileBases[i-1];
		for (int j = 0; j<N-baseNum; j++) {
			if (theRest[j] > current && theRest[j] < pileBases[i]) {
				marked[j+baseNum] = true;
				current = theRest[j];
			}
		}
	}

	int answer = 0;
	for (int i = 0; i<N; i++) {
		if (marked[i]) {
			answer++;
			continue;
		}
		break;
	}
	fout<<answer<<endl;
	fout.close();

	return 0;
}
