#include <iostream>
using namespace std;

int x[1080], y[1080], r[1080], count[1080];

bool touching(int x1, int y1, int x2, int y2, int r1, int r2) {
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)==(r1+r2)*(r1+r2));
}

int main(void) {
	int N;
	cin>>N;
	for (int i = 0; i < N; i++) {
		cin>>x[i]>>y[i]>>r[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (touching(x[i], y[i], x[j], y[j], r[i], r[j])) {
				count[i]++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		if ((count[i] == 1) && (x[i]!=0) && (y[i]!=0)) {
			cout<<x[i]<<' '<<y[i];
			break;
		}
	}

	return 0;
}
