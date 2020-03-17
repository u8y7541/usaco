#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int binarySearch(int* begin, int length, int toFind) {
	int* i = upper_bound(begin, begin+length, toFind);
	if (i == begin+length || (toFind>*i)) {
		return length;
	}
	else {
		return i-begin-1;
	}
}

int abs(int a) {
	if (a>0) {
		return a;
	}
	return -a;
}

int main(void) {
	ifstream fin;
	fin.open("sort.in");
	int N;
	fin>>N;
	int A[N];
	int sorted[N];
	for (int i = 0; i<N; i++) {
		fin>>A[i];
		sorted[i] = A[i];
	}
	fin.close();

	sort(sorted, sorted+N);
	int distance = 0, max = 0;
	for (int i = 0; i<N; i++) {
		distance = i-binarySearch(sorted, N, A[i]);
		if (distance>max) {
			max = distance;
		}
	}

	ofstream fout;
	fout.open("sort.out");
	fout<<max+1;
	fout.close();
	return 0;
}
