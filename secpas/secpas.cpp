#include <iostream>
using namespace std;

int count[10000];

int main(void) {
	int N;
	cin>>N;
	for (int i = 0; i*i<=N; i++) {
		for (int j = 0; j*j<=N; j++) {
			if (i*i+j*j<=N) {
				count[i*i+j*j]++;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i <= N; i++) {
		answer += count[i]*count[N-i];
	}
	cout<<answer;
	
	return 0;
}
