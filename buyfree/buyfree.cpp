#include <iostream>
#include <algorithm>
using namespace std;

int H[10000], L[10000];

bool comp(int x, int y) {
	return x>y;
}

int main(void) {
	int N, M;
	cin>>N>>M;
	for (int i = 0; i<N; i++) {
		cin>>H[i];
	}
	for (int i = 0; i<M; i++) {
		cin>>L[i];
	}
	sort(H, H+N, comp);
	sort(L, L+M, comp);

	int ans = N;
	for (int i = 0; i<N && i<M; i++) {
		for (int j = i; j<M; j++) {
			if (H[i] > L[j]) {
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
