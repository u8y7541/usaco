/*
ID: surya.s1
LANG: C++
TASK: friday
*/
#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int year) {
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int daysInMonth(int year, int month) {
	if ((month<8 && month%2==1) || (month>7 && month%2==0)) return 31;
	if (month == 2) {
		if (isLeapYear(year)) return 29;
		return 28;
	}
	return 30;
}

int main(void) {
	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int N;
	fin>>N;
	
	int distribution[7];
	fill(distribution, distribution+7, 0);
	distribution[0]++;
	int curYear = 1900, curMonth = 1, curDay = 0;
	while (!(curYear == 1900+N-1 && curMonth == 12)) {
		curDay+=daysInMonth(curYear, curMonth);
		curDay%=7;
		distribution[curDay]++;

		curMonth++;
		if (curMonth>12) {
			curMonth = 1;
			curYear++;
		}
	}
	for (int i = 0; i<6; i++) {
		fout<<distribution[i]<<' ';
	}
	fout<<distribution[6]<<endl;

	return 0;
}
