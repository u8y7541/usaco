/*
ID: surya.s1
LANG: C++
TASK: milk
*/
#include <bits/stdc++.h>
using namespace std;

int cap(int x, int y) {
	return (x>y ? y:x);
}

int main(void) {
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int N, M;
	fin>>N>>M;
	int prices[M];
	map<int, int> farmers;
	int tmp1, tmp2;
	int realM = 0;
	for (int i = 0; i<M; i++) {
		fin>>tmp1>>tmp2;
		if (farmers.find(tmp1) != farmers.end()) {
			farmers[tmp1] += tmp2;
			continue;
		}
		farmers[tmp1] = tmp2;
		prices[realM] = tmp1;
		realM++;
	}

	sort(prices, prices+realM);
	int cost = 0, units = 0;
	for (int i = 0; i<realM; i++) {
		tmp1 = cap(N-units, farmers.find(prices[i])->second);
		units += tmp1;
		cost += tmp1*prices[i];
	}
	fout<<cost<<endl;

	return 0;
}
