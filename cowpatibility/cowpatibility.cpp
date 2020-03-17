#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream fin;
	fin.open("cowpatibility.in");
	ofstream fout;
	fout.open("cowpatibility.out");

	int N;
	fin>>N;
	multiset<int> flavors;
	set<int> uniqueFlavors;
	int tmp;
	for (int i = 0; i<5*N; i++) {
		fin>>tmp;
		flavors.insert(tmp);
		uniqueFlavors.insert(tmp);
	}
	fin.close();

	int compatiblePairs = 0;
	int n;
	for (set<int>::iterator it = flavors.begin(); it != flavors.end(); it++) {
		n = flavors.count(*it);
		n = n*(n-1)/2;
		compatiblePairs+=n;
	}

	fout<<-1 * ((N*(N-1)/2) - compatiblePairs);
	fout.close();
	return 0;
}
