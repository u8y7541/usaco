/*
ID: surya.s1
TASK: ride
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream fin("ride.in");
	ofstream fout("ride.out");

	int product1 = 1, product2 = 1;
	char in = 0;
	int n = 0;
	while (1) {
		fin>>noskipws>>in;
		if (in == '\n') {
			break;
		}
		product1 *= (in - 'A') + 1;
		n++;
	}
	while (1) {
		fin>>noskipws>>in;
		if (fin.eof() || in == '\n') {
			break;
		}
		product2 *= (in - 'A') + 1;
	}
	if ((product1 % 47) == (product2 % 47)) {
		fout<<"GO"<<endl;
	}
	else {
		fout<<"STAY"<<endl;
	}
	return 0;
}
