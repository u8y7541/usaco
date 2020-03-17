#include <bits/stdc++.h>
using namespace std;

int find_path_score(int begin, int end, int* parent, int* level, int* enjoyment){
	int shallow = begin, deep = end;
	if (level[begin] > level[end]) {
		shallow = end; deep = begin;
	}

	// Move up deep to make it same level as shallow
	int result = enjoyment[deep] ^ enjoyment[shallow];
	while (level[shallow] != level[deep]) {
		deep = parent[deep];
		if (shallow == deep) { // Special case
			return result;
		}
		result ^= enjoyment[deep];
	}

	// Move them up the tree at the same speed
	while (1) {
		shallow = parent[shallow];
		deep = parent[deep];
		if (shallow == deep) {
			result ^= enjoyment[deep];
			break;
		}
		result ^= enjoyment[shallow] ^ enjoyment[deep];
	}
	return result;
}

int main(void) {
	ifstream fin;
	ofstream fout;
	fin.open("cowland.in");
	fout.open("cowland.out");

	int N, Q;
	fin>>N>>Q;
	int enjoyment[N];
	for (int i = 0; i<N; i++) {fin>>enjoyment[i];}
	set<int> adjlist[N];
	int n1, n2;
	for (int i = 0; i<N-1; i++) {
		fin>>n1>>n2;
		n1--; n2--;
		adjlist[n1].insert(n2);
		adjlist[n2].insert(n1);
	}

	int parent[N]; // parent[i] gives i's parent
	int level[N]; // leve[i] gives tree leve i

	level[0] = 0; // make tree with first node as top
	parent[0] = 0;
	queue<int> current;
	current.push(0);
	while (!current.empty()) {
		int node = current.front();
		current.pop();
		set<int>::iterator it;
		for (it = adjlist[node].begin(); it != adjlist[node].end(); it++) {
			if (*it == parent[node]) {continue;}
			current.push(*it);
			level[*it] = level[node] + 1;
			parent[*it] = node;
		}
	}

	int type;
	for (int i = 0; i<Q; i++) {
		fin>>type>>n1>>n2;
		if (type == 1) {
			enjoyment[n1-1] = n2;
			continue;
		}
		n1--; n2--;
		fout<<find_path_score(n1, n2, parent, level, enjoyment)<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}
