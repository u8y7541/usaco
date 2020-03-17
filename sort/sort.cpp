#include <fstream>
using namespace std;

int main(void) {
	ifstream fin;
	fin.open("sort.in");
	int N;
	fin>>N;
	int A[N];
	for (int i = 0; i<N; i++) {
		fin>>A[i];
	}
	fin.close();

	bool sorted = false;
	int counter = 0;
	int tmp;
	while (!sorted) {
		sorted = true;
		counter++;
		for (int i = 0; i<N-1; i++) {
			if (A[i+1]<A[i]) {
				tmp = A[i];
				A[i] = A[i+1];
				A[i+1] = tmp;
				sorted = false;
			}
		}
	}

	ofstream fout;
	fout.open("sort.out");
	fout<<counter;
	fout.close();
	return 0;
}
