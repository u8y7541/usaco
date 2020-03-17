/*
ID: surya.s1
LANG: C++
TASK: preface
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N;
int totals[7];
char names[8] = "IVXLCDM";

void count(int x) {
	int cur = 0;
	while (x) {
		if (x%10 == 4) {
			totals[cur]++;
			totals[cur+1]++;
		}
		if (x%10 == 9) {
			totals[cur]++;
			totals[cur+2]++;
		}
		if (x%5 < 4) totals[cur] += x%5;
		if (x%10 > 4 && x%10 < 9) totals[cur+1]++;
		x /= 10;
		cur+=2;
	}
}

int main(void) {
	ifstream fin("preface.in");
	ofstream fout("preface.out");

	fin>>N;

	for (int i = 1; i<=N; i++)
		count(i);
	for (int i = 0; i<7; i++)
		if (totals[i]) fout<<names[i]<<' '<<totals[i]<<endl;

	return 0;
}
