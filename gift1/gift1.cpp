/*
ID: surya.s1
LANG: C++
TASK: gift1
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	int NP;
	fin>>NP;
	string names[NP];
	map<string, int> nameToID;
	for (int i = 0; i<NP; i++) {
		fin>>names[i];
		nameToID.insert(pair<string, int>(names[i], i));
	}

	int money[NP];
	fill(money, money+NP, 0);

	string name, name2;
	int id, id2;
	int giftMoney, numSharedTo;
	while (fin>>name) {
		id = nameToID[name];
		fin>>giftMoney>>numSharedTo;
		if (numSharedTo == 0) {
			continue;
		}
		money[id] -= giftMoney - (giftMoney%numSharedTo);
		for (int i = 0; i<numSharedTo; i++) {
			fin>>name2;
			id2 = nameToID[name2];
			money[id2] += giftMoney/numSharedTo;
		}
	}
	for (int i = 0; i<NP; i++) {
		fout<<names[i]<<' '<<money[i]<<endl;
	}

	return 0;
}
