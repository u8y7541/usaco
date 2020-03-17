#include <iostream>
using namespace std;

int f[2][6000];
void factors(int n, int x) {
	int counter = 0;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			f[x][counter] = i;
			counter++;
		}
	}
}

int main(void) {
	int p, q;
	cin>>p>>q;
	factors(p, 0);
	factors(q, 1);

	for (int i = 0; f[0][i] != 0; i++) {
		for (int j = 0; f[1][j] != 0; j++) {
			cout<<f[0][i]<<' '<<f[1][j]<<'\n';
		}
	}
	return 0;
}
