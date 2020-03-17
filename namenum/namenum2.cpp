/*
ID: surya.s1
LANG: C++
TASK: namenum
*/
#include <bits/stdc++.h>
using namespace std;

int letterMap[26] = {
	2,2,2,
	3,3,3,
	4,4,4,
	5,5,5,
	6,6,6,
	7,10,7,7,
	8,8,8,
	9,9,9,10
};


int main(void) {
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");

	int num[12];
	int size = 0;
	char tmp = 0;
	while (1) {
		fin>>tmp;
		if (fin.eof()) break;
		num[size] = tmp-'0';
		size++;
	}
	
	ifstream dict("dict.txt");
	string name;
	bool nameFound = false;
	while (1) {
		dict>>name;
		if (dict.eof()) break;
		if (name.size() != size) continue;
		bool flag = false;
		for (int i = 0; i<size; i++) {
			if (letterMap[name[i]-'A'] != num[i]) {flag = true; break;}
		}
		if (flag) continue;
		nameFound = true;
		fout<<name<<endl;
	}
	if (!nameFound) fout<<"NONE"<<endl;

	return 0;
}
