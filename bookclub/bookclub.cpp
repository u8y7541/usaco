#include <iostream>
using namespace std;

int main(void) {
	int N, NQ, P;
	cin>>N>>NQ>>P;
	int data[N][NQ];
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<NQ; j++) {
			cin>>data[i][j];
		}
	}
	int queries[P][2];
	for (int i = 0; i<P; i++) {
		cin>>queries[i][0]>>queries[i][1];
	}

	int ans = N;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<P; j++) {
			if (data[i][queries[j][0]-1] != queries[j][1]) {
				ans -= 1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
