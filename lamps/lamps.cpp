/*
ID: surya.s1
LANG: C++
TASK: lamps
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, C;
bool lamps[105];
int restrictions[105];
int state[8] = {1, 11, 2, 8, 9, 3, 10, 0};
bool possible[8];

void generate(int buttons) {
	fill(lamps, lamps+105, true);
	if (buttons&1)
		for (int i = 0; i<N; i++) lamps[i] = !lamps[i];
	if (buttons&2)
		for (int i = 0; i<N; i+=2) lamps[i] = !lamps[i];
	if (buttons&4)
		for (int i = 1; i<N; i+=2) lamps[i] = !lamps[i];
	if (buttons&8)
		for (int i = 0; i<N; i+=3) lamps[i] = !lamps[i];
}

int main(void) {
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");

	fin>>N>>C;
	int tmp;
	fill(restrictions, restrictions+N, -1);
	while (1) {
		fin>>tmp;
		if (tmp == -1) break;
		restrictions[tmp-1] = 1;
	}
	while (1) {
		fin>>tmp;
		if (tmp == -1) break;
		restrictions[tmp-1] = 0;
	}

	possible[0] = (C>0);
	possible[1] = (C>1);
	possible[2] = (C>0);  
	possible[3] = (C>0 && C!=2);
	possible[4] = (C>1);
	possible[5] = (C>0);
	possible[6] = (C>1);
	possible[7] = (C!=-1);

	bool impossible = true;
	for (int i = 0; i<8; i++) {
		if (!possible[i]) continue;
		generate(state[i]);
		bool flag = true;
		for (int j = 0; j<N; j++)
			if (restrictions[j] != -1 && lamps[j] != restrictions[j]) {flag = false; break;}
		if (!flag) continue;
		for (int j = 0; j<N; j++) fout<<lamps[j];
		fout<<endl;
		impossible = false;
	}
	if (impossible) fout<<"IMPOSSIBLE"<<endl;

	return 0;
}
