/*
ID: surya.s1
LANG: C++
TASK: barn1
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int M, S, C;
	fin>>M>>S>>C;
	bool stalls[S];
	fill(stalls, stalls+S, false);
	int nums[C];
	for (int i = 0; i<C; i++) {
		fin>>nums[i];
		stalls[nums[i]-1] = true;
	}
	
	sort(nums, nums+C);
	int gaps[C];
	int numGaps = 0;
	for (int i = 1; i<C; i++) {
		if (nums[i]-nums[i-1] > 1) {
			gaps[numGaps] = nums[i]-nums[i-1];
			numGaps++;
		}
	}
	sort(gaps, gaps+numGaps);
	int numBoards = 0;
	for (int i = 0; i<S; i++) {
		if ((i == 0 && stalls[0]) || (i>0 && stalls[i] && !stalls[i-1]))
			numBoards++;
	}
	int ans = C;
	int gapNum = 0;
	while (numBoards > M && gapNum<numGaps) {
		ans += gaps[gapNum]-1;
		numBoards--;
		gapNum++;
	}
	fout<<ans<<endl;

	return 0;
}
