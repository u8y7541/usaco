/*
ID: surya.s1
LANG: C++
TASK:
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, Q;
int A[5001];
struct cmp {
	bool operator() (pair<int,int> a, pair<int,int> b) const {
		return a.first<b.first;
	}
};
set<pair<int,int>, cmp> As; // first is value, second is index
int pairwise[5000][5000];
vector<pair<int, int> > triples; // first is min, second is max, mid doesn't matter

int main(void) {
	ifstream fin("threesum.in");
	ofstream fout("threesum.out");

	fin>>N>>Q;
	for (int i = 0; i<N; i++) {
		fin>>A[i];
		As.insert(make_pair(A[i], i));
	}

	int64_t locOfIndexStart[N+5]; // Gives the first index in triples of where the first element is the argument
	fill_n(locOfIndexStart, N+5, -1);
	int curIndex = -1;
	for (int i = 0; i<N; i++) {
		for (int j = i+1; j<N; j++) {
			set<pair<int,int> >::iterator it = As.find(make_pair(-A[i]-A[j], 0));
			int index = (*it).second;
			if (index >= i) continue;

			if (it != As.end()) {
				triples.push_back(make_pair(index, j));
				if (index != curIndex) {
					curIndex = index;
					locOfIndexStart[curIndex] = triples.size()-1;
				}
				cout<<index<<' '<<i<<' '<<j<<endl;
			}
		}
	}
	int64_t curValue = -1;
	for (int i = N+4; i>=0; i--) {
		if (locOfIndexStart[i] != -1) {
			curValue = locOfIndexStart[i];
			continue;
		}
		locOfIndexStart[i] = curValue;
	}

	for (int64_t i = 0; i<triples.size(); i++) {
		cout<<triples[i].first<<' '<<triples[i].second<<endl;
	}

	for (int i = 0; i<Q; i++) {
		int a, b;
		fin>>a>>b;
		a--; b--;
		int64_t tot = 0;
		/*for (int64_t j = locOfIndexStart[a]; (j<triples.size() && triples[j].first < b); j++) {
			if (triples[j].second > b) continue;
			tot++;
		}
		fout<<tot<<endl;*/
		for (int64_t j = 0; j<triples.size(); j++)
			if (triples[j].first>=a && triples[j].second<=b) tot++;
		fout<<tot<<endl;
	}	

	fout.close();
	return 0;
}
