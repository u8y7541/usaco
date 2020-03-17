/*
ID: surya.s1
LANG: C++
TASK: runround
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

char buf[15];
unsigned long Mnum;

bool isRR(unsigned long x) {
	sprintf(buf, "%lu", x); 
	int nDigits = strlen(buf);

	bool digit[11];
	fill_n(digit, 11, false);
	for (int i = 0; i<nDigits; i++) {
		if (buf[i] == '0') return false;
		if (digit[buf[i]-'0']) return false;
		digit[buf[i]-'0'] = true;
	}
	fill_n(digit, 11, false);

	int cur_index = 0;
	int counter = nDigits;
	while (counter--) {
		if (digit[buf[cur_index]-'0'])
			return false;
		digit[buf[cur_index]-'0'] = true;
		cur_index += buf[cur_index]-'0';
		cur_index %= nDigits;
	}
	return cur_index<1;
}


int main(void) {
	ifstream fin("runround.in");
	ofstream fout("runround.out");

	fin>>Mnum;
	Mnum++;
	for (; !isRR(Mnum); Mnum++);
	fout<<Mnum<<endl;

	return 0;
}
