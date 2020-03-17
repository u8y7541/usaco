#include <iostream>
#include <algorithm>
using namespace std;

int times[5000];

int main(void) {
	int h, m, s, N;
	cin>>N;
	for (int i = 0; i < N; i++) {
		cin>>h>>m>>s;
		times[i] = h*10000+m*100+s;
	}
	
	sort(times, times + N);

	int time;
	for (int i = 0; i < N; i++) {
		time = times[i];
		cout<<time/10000<<' '<<(time/100)%100<<' '<<time%100<<'\n';
	}

	return 0;
}
