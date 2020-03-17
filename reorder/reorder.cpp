#include <iostream>
using namespace std;

int A[100], B[100], index[100], N;

int solveCycle(int pos) {
	int cycleLength = 1;
	int tmp = 0;
	char ch;
	cout<<A[pos];
	cout<<A[index[A[pos]-1]-1];
	while (A[pos] != B[pos]) {
		tmp = A[pos];
		cout<<A[pos]<<" ";
		cout<<A[index[A[pos]-1]+1]<<endl;
		cin>>ch;
		A[pos] = A[index[A[pos]-1]-1];
		A[index[A[pos]-1]-1] = tmp;
		cycleLength++;
	}
	return cycleLength;
}

int main(void) {
	cin>>N;
	for (int i = 0; i<N; i++) {
		cin>>A[i];
	}
	for (int i = 0; i<N; i++) {
		cin>>B[i];
		index[B[i]-1] = i+1;
	}
	for (int i = 0; i<N; i++) {
		cout<<index[i];
	}
	cout<<endl;

	int numCycles = 0;
	int maxLength = 0;
	int length = 0;
	for (int i = 0; i<N; i++) {
		if (A[i] != B[i]) {
			length = solveCycle(i);
			if (length>maxLength) {
				maxLength = length;
			}
			numCycles++;
		}
	}
	cout<<numCycles<<' '<<maxLength;
	return 0;
}
