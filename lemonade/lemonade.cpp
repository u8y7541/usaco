#include <fstream>
#include <algorithm>
using namespace std;

int main(void) {
	ifstream fin;
	fin.open("lemonade.in");
	int N;
	fin>>N;
	int w[N];
	for (int i = 0; i<N; i++) {
		fin>>w[i];
	}
	fin.close();

	sort(w, w+N);
	int counter = 0;
	for (int i = N-1; i>=0; i--) {
		if (counter>w[i]) {
			break;
		}
		counter++;
	}

	ofstream fout;
	fout.open("lemonade.out");
	fout<<counter;
	fout.close();
}
