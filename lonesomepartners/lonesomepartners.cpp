#include <iostream>
using namespace std;

int distance(int x, int y, int x1, int y1) {
	return (x-x1)*(x-x1)+(y-y1)*(y-y1);
}

int main(void) {
	int N;
	cin>>N;
	int x[N], y[N];
	for (int i = 0; i < N; i++) {
		cin>>x[i]>>y[i];
	}

	int max, dist, a, b;
	max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			dist = distance(x[i], y[i], x[j], y[j]);
			if (dist > max) {
				max = dist;
				a = i; b = j;
			}
		}
	}
	cout<<a+1<<' '<<b+1;
	return 0;
}
