#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

int main(void) {
	ifstream fin;
	fin.open("shuffle.in");
	int N;
	fin>>N;
	int a[N];
	for (int i = 0; i<N; i++) {
		fin>>a[N];
	}
	fin.close();
	
	int tmp[N] = {-1};
	int path = 0;
	int ans = 0;
	for (int i = 0; i<N; i++) {
		path = i;
		int counter = 0;
		tmp[N] = {-1};
		while (find(tmp, tmp+N, a[path]-1) == tmp+N) {
			path = a[path]-1;
			tmp[counter] = path;
			counter++;
		}
		if (a[path]-1 == i) {
			ans++;
		}
	}

	ofstream fout;
	fout.open("shuffle.out");
	fout<<ans<<endl;
	fout.close();
	return 0;
}
