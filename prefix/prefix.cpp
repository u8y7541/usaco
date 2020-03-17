/*
ID: surya.s1
LANG: C++
TASK: prefix
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

char primitives[205][12];
int numPs;
char S[200005];
bool possible[200005];
int lenS, maxPrefix;

void update(int index) {
	if (!possible[index]) return;
	for (int i = 0; i<numPs; i++) {
		bool flag = true;
		int j = 0;
		for (; primitives[i][j] != '\0'; j++) {
			if (primitives[i][j] != S[index+j+1]) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		possible[index+j] = true;
		maxPrefix = max(maxPrefix, index+j);
	}
}

int main(void) {
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");

	char tmp[10];
	fin>>tmp;
	while (tmp[0] != '.') {
		memcpy(primitives[numPs], tmp, 10);
		fin>>tmp;
		numPs++;
	}
	while (fin>>S[lenS+1]) lenS++;

	possible[0] = true;
	for (int i = 0; i<lenS; i++)
		update(i);
	fout<<maxPrefix<<endl;

	return 0;
}
