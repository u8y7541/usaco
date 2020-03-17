/*
ID: surya.s1
LANG: C++
TASK: milk2
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

	int N;
	fin>>N;
	int times[N][2];
	int maxTime = 0;
	int minTime = 1000010;
	for (int i = 0; i<N; i++) {
		fin>>times[i][0]>>times[i][1];
		if (times[i][0]<minTime) minTime = times[i][0];
		if (times[i][1]>maxTime) maxTime = times[i][1];
	}

	bool timeArray[maxTime];
	fill(timeArray, timeArray+maxTime, false);
	for (int i = 0; i<N; i++) fill(timeArray+times[i][0], timeArray+times[i][1], true);

	bool milking = timeArray[minTime];
	int curMilking = 0, maxMilking = 0, curIdle = 0, maxIdle = 0;
	for (int i = minTime; i<maxTime; i++) {
		if (timeArray[i]) {
			curMilking++;
			if (milking) continue;
			milking = true;
			if (curIdle > maxIdle) maxIdle = curIdle;
			curIdle = 0;
			continue;
		}
		curIdle++;
		if (!milking) continue;
		milking = false;
		if (curMilking > maxMilking) maxMilking = curMilking;
		curMilking = 0;
	}
	if (curMilking>maxMilking) maxMilking = curMilking;
	if (curIdle > maxIdle) maxIdle = curIdle;

	fout<<maxMilking<<' '<<maxIdle<<endl;

	return 0;
}
