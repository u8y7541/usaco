/*
ID: surya.s1
LANG: C++
TASK: palsquare
*/
#include <bits/stdc++.h>
using namespace std;

int B;
const char table[21] = "0123456789ABCDEFGHIJ";

string toBaseB(int x) {
	string result;
	int remainder = 0;
	while (x>0) {
		remainder = x%B;
		result.insert(0, 1, table[remainder]);
		x /= B;
	}
	return result;
}

bool isPalindrome(string s) {
	for (int i = 0; i<s.length(); i++) {
		if (s[i] != s[s.length()-1-i]) return false;
	}
	return true;
}

int main(void) {
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	fin>>B;

	for (int i = 1; i<301; i++) {
		string baseB = toBaseB(i*i);
		if (isPalindrome(baseB)) fout<<toBaseB(i)<<" "<<baseB<<endl;
	}

	return 0;
}
