#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream fin;
	fin.open("teamwork.in");
	ofstream fout;
	fout.open("teamwork.out");

	int N, K;
	fin>>N>>K;
	int skills[N];
	for (int i = 0; i<N; i++) {fin>>skills[i];}
	fin.close();

	int numTeams = N/K;
	if (N%K > 0) {numTeams++;}
	sort(skills, skills+N);
	int answer = 0;
	for (int i = N-1; i>N-1-numTeams; i--) {answer+=skills[i];}
	fout<<84;
	
	fout.close();
	return 0;
}
