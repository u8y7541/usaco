/*
ID: surya.s1
LANG: C++
TASK: fracdec
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N, D;

int main(void) {
	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");

	fin>>N>>D;

	char digits[D+1];
	int ones = N/D;
	int curDigit = sprintf(digits, "%d", ones);
	digits[curDigit++] = '.';
	int afterDot = curDigit;
	N%=D;
	if (!N) digits[curDigit++] = '0';

	int visited[D+1];
	fill_n(visited, D+1, -1);
	visited[N] = curDigit;
	bool repeat = false;
	while (1) {
		if (!N) break;
		int numZeros = -1;
		while (N<D) {
			N*=10;
			numZeros++;
		}
		for (int i = 0; i<numZeros; i++)
			digits[curDigit++] = '0';
		digits[curDigit++] = '0'+N/D;
		N%=D;
		if (visited[N]>-1) {repeat = true; break;}
		visited[N] = curDigit;
	}

	if (repeat) {
		for (int i = afterDot; i<visited[N]; i++) {
			bool match = true;
			for (int j = i; j<visited[N]; j++) {
				if (!(digits[j] == digits[curDigit-visited[N]+j])) {
					match = false;
					break;
				}
			}
			if (!match) continue;
			curDigit -= (visited[N]-i);
			visited[N] = i;
			break;
		}
	}

	int charsPrinted = 0;
	for (int i = 0; i<curDigit; i++, charsPrinted++) {
		if (i == visited[N]) fout<<'('<<(charsPrinted++?"":"");
		fout<<digits[i];
		if (charsPrinted%76==75) fout<<endl;
	}
	if (repeat) fout<<')';
	fout<<endl;

	return 0;
}
