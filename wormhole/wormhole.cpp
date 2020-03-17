/*
ID: surya.s1
LANG: C++
TASK: wormhole
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

struct Hole {
	int x;
	int y;
	Hole* dest;
	int num;
};

int N;

int findNext(Hole** holes, int index) {
	Hole h = *holes[index];
	int minIndex = -1;
	for (int i = 0; i<N; i++) {
		if (i == index) continue;
		if ((h.x < holes[i]->x) && (h.y == holes[i]->y))
			if (minIndex == -1 || holes[i]->x < holes[minIndex]->x) minIndex = i;
	}
	return minIndex;
}

bool testLoop(Hole** holes, int index, int* map) {
	int cur = index;
	while (1) {
		if (map[cur] == -1) break;
		cur = holes[map[cur]]->dest->num;
		if (cur == index) return true;
	}
	return false;
}

int total = 0;
void generate(Hole** holes, bool* used, int* map, int cur, int depth) {
	if (depth == N/2) {
		/*for (int i = 0; i<N; i++)
			cout<<"("<<holes[i]->x<<", "<<holes[i]->y<<") <-> ("<<holes[i]->dest->x<<", "<<holes[i]->dest->y<<")"<<endl;
		cout<<endl;*/

		for (int i = 0; i<N; i++) {
			if (testLoop(holes, i, map)) {
				total++;
				return;
			}
		}
	}

	used[cur] = true;
	int curNew = -1;
	for (int i = cur+1; i<N; i++) {
		if (used[i]) continue;

		used[i] = true;

		holes[cur]->dest = holes[i];
		holes[i]->dest = holes[cur];

		curNew = cur+1;
		for (; used[curNew]; curNew++);

		generate(holes, used, map, curNew, depth+1);
		used[i] = false;
	}
	used[cur] = false;
}

int main(void) {
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");

	fin>>N;
	Hole* holes[N];
	for (int i = 0; i<N; i++) {
		holes[i] = (Hole*)malloc(sizeof(Hole));
	}
	for (int i = 0; i<N; i++) {
		fin>>holes[i]->x>>holes[i]->y;
		holes[i]->num = i;
	}
	bool used[N];
	fill(used, used+N, false);
	int map[N];
	for (int i = 0; i<N; i++)
		map[i] = findNext(holes, i);
	generate(holes, used, map, 0, 0);
	fout<<total<<endl;
	for (int i = 0; i<N; i++) {
		free(holes[i]);
	}

	return 0;
}
