#include <iostream>
using namespace std;

int S[10000], B[100], T[10000];

int main(void) {
	int N, Q;
	cin>>N>>Q;
	for (int i = 0; i < N; i++) {
		cin>>B[i];
	}
	for (int i = 0; i < Q; i++) {
		cin>>T[i];
	}

	int counter = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < B[i]; j++) {
			S[counter] = i;
			counter++;
		}
	}

	for (int i = 0; i < Q; i++) {
		cout<<S[T[i]]+1<<'\n';
	}
		
	return 0;
}
