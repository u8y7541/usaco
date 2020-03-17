#include <bits/stdc++.h>
using namespace std;

int N, M, K;

void findPossibilities(int* sylls, int* rhymes, int syllNum, map<int, int>& answer) {
	for (int i = 0; i<N; i++) {
		if (answer.find(rhymes[i]) == answer.end()) {
			answer.insert(make_pair(rhymes[i], 0));
		}
	}

	for (int i = 0; i<N; i++) {
		if (syllNum > sylls[i]) {
			findPossibilities(sylls, rhymes, syllNum-sylls[i], answer);
		}
		if (syllNum == sylls[i]) {
			answer[rhymes[i]] += 1;
		}
	}
}


int main(void) {
	ifstream fin;
	ofstream fout;
	fin.open("poetry.in");
	fout.open("poetry.out");

	fin>>N>>M>>K;
	int sylls[N];
	int rhymes[N];
	set<int> allRhymes;
	for (int i = 0; i<N; i++) {
		fin>>sylls[i]>>rhymes[i];
		allRhymes.insert(rhymes[i]);
	}

	map<char, int> structure;
	char chr;
	for (int i = 0; i<M; i++) {
		fin>>chr;
		if (structure.find(chr) == structure.end()) {
			structure.insert(make_pair(chr, 0));
			continue;
		}
		structure[chr]++;
	}
	fin.close();

	map<int, int> answer;
	findPossibilities(sylls, rhymes, K, answer);

	map<char, int>::iterator it1;
	map<int, int>::iterator it2;
	int mult = 1;
	for (it1 = structure.begin(); it1!=structure.end(); it1++) {
		int sum = 0;
		for (it2 = answer.begin(); it2!=answer.end(); it2++) {
			sum += pow(it2->second, it1->second + 1);
		}
		mult *= (sum%1000000007);
		mult %= 1000000007;
	}
	fout<<mult;
	fout.close();

	return 0;
}
