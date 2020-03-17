#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
using namespace std;

long long L, N, F, B;

bool sortStops(const pair<int, int>& a, const pair<int, int>& b) {
	return (a.second<b.second);
}

int main(void) {
	ifstream fin;
	fin.open("reststops.in");
	fin>>L>>N>>F>>B;
	pair<int, int> stops[N+1];
	stops[0] = make_pair(0, 0);
	for (long long i = 1; i<N+1; i++) {
		fin>>stops[i].first>>stops[i].second;
	}
	fin.close();

	long long tastiness = 0;
	long long cur = 0;
	long long target = 0;

	while (cur != N) {
		target = max_element(stops+cur+1, stops+N+1, sortStops)-stops;
		tastiness += (stops[target].first-stops[cur].first)*(F-B)*(stops[target].second);
		cur = target;
	}

	ofstream fout;
	fout.open("reststops.out");
	fout<<tastiness;
	return 0;
}
