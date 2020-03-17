#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int F, K;
	cin>>F>>K;
	double ans = (double) F;
	int L[K], I[K];
	for (int i=0; i<K; i++) {
		cin>>L[i]>>I[i];
	}

	for (int i=0; i<K; i++) {
		ans *= ((double)(I[i]-1))/I[i];
	}
	int a = floor(ans);
	cout<<a<<'\n';

	for (int i=0; i<K; i++) {
		if (F%I[i] + 1 <= L[i]) {
			cout<<F<<' '<<I[i]<<' '<<L[i]<<'\n';
			a += 1;
		}
	}
	cout<<a;

	return 0;
}
