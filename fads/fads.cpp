#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];
int main(void) {
	int N, L, K;
	cin>>N>>L>>K;
	for (int i = 0; i<N; i++) {
		cin>>a[i];
	}
	sort(a, a+N);

	int cur = 0;
	while (a[cur]<=L && cur<N) {
		L+=K;
		cur++;
	}
	cout<<cur;
	return 0;
}
