#include <iostream>
using namespace std;

int main(void) {
	int ans = 0, money = 0, debt = 0, firsttopay = -1, N, d;
	cin>>N;
	for (int i = 0; i<N; i++) {
		cin>>d;
		if (d<0) {
			debt -= d;
			if (firsttopay == -1) {
				firsttopay = i;
			}
			ans++;
			continue;
		}
		money += d;
		if (money >= debt) {
			ans += 2*(i-firsttopay);
			firsttopay = -1;
			money-=debt;
			debt = 0;
		}
		ans++;
	}
	cout<<ans;
}
