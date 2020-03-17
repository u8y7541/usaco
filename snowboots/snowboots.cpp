#include <fstream>
using namespace std;

int bound(int value, int boundary) {
	return (value<boundary) ? value:boundary;
}

int main(void) {
	ifstream fin;
	fin.open("snowboots.in");
	int N, B;
	fin>>N>>B;
	int tiles[N];
	for (int i = 0; i<N; i++) {
		fin>>tiles[i];
	}
	int shoes[B][2];
	for (int i = 0; i<B; i++) {
		fin>>shoes[i][0]>>shoes[i][1];
	}
	fin.close();

	int curShoe = 0, pos = 0;
	bool discard;
	while (pos != N-1) {
		discard = true;
		for (int i = bound(pos+shoes[curShoe][1], N-1); i>pos; i--) {
			if (tiles[i]<=shoes[curShoe][0]) {
				pos = i;
				discard = false;
				break;
			}
		}
		if (discard) {
			curShoe++;
		}
	}

	ofstream fout;
	fout.open("snowboots.out");
	fout<<curShoe;
	fout.close();

	return 0;
}
