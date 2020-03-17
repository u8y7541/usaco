#include <fstream>
#include <set>
#include <utility>
using namespace std;

char min(char a, char b) {
	if (a>b) {
		return b;
	}
	return a;
}

char max(char a, char b) {
	if (a>b) {
		return a;
	}
	return b;
}

int main(void) {
	ifstream fin;
	fin.open("tttt.in");
	char board[3][3];
	for (int i = 0; i<3; i++) {
		for (int j = 0; j<3; j++) {
			fin>>board[i][j];
		}
	}
	fin.close();

	int checks[8][3][2] = {{{0, 0}, {0, 1}, {0, 2}},
						   {{1, 0}, {1, 1}, {1, 2}},
						   {{2, 0}, {2, 1}, {2, 2}},
						   {{0, 0}, {1, 0}, {2, 0}},
						   {{0, 1}, {1, 1}, {2, 1}},
						   {{0, 2}, {1, 2}, {2, 2}},
						   {{0, 0}, {1, 1}, {2, 2}},
						   {{0, 2}, {1, 1}, {2, 0}}};
	set<char> singles;
	set<pair<char, char> > doubles;
	char chars[3] = {'-', '-', '-'};
	for (int i = 0; i<8; i++) {
		chars[0] = '-';
		chars[1] = '-';
		chars[2] = '-';
		for (int j = 0; j<3; j++) {
			chars[j] = board[checks[i][j][0]][checks[i][j][1]];
		}
		if (chars[0] == chars[1] && chars[0] == chars[2]) {
			singles.insert(chars[0]);
		}
		if (chars[0] == chars[1] && chars[0] != chars[2]) {
			doubles.insert(make_pair(min(chars[0], chars[2]), max(chars[0], chars[2])));
		}
		else if (chars[0] == chars[2] && chars[0] != chars[1]) {
			doubles.insert(make_pair(min(chars[0], chars[1]), max(chars[0], chars[1])));
		}
		else if (chars[1] == chars[2] && chars[0] != chars[1]) {
			doubles.insert(make_pair(min(chars[0], chars[1]), max(chars[0], chars[1])));
		}
	}

	ofstream fout;
	fout.open("tttt.out");
	fout<<singles.size()<<endl<<doubles.size();
	fout.close();

	return 0;
}
