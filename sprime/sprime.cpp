#include <iostream>
using namespace std;

int N;

bool isPrime(int n) {
	if (n%2==0 && n>2) {
		return false;
	}
	for (int i = 3; i*i<=n; i+=2) {
		if (n%i==0) {
			return false;
		}
	}
	return true;
}

void solve(int digit, int value) {
	if (!isPrime(value)) {
		return;
	}
	if (digit==N) {
		cout<<value<<endl;
		return;
	}
	solve(digit+1, value*10+1);
	solve(digit+1, value*10+3);
	solve(digit+1, value*10+7);
	solve(digit+1, value*10+9);
}

int main(void) {
	cin>>N;
	solve(1, 2);
	solve(1, 3);
	solve(1, 5);
	solve(1, 7);
	return 0;
}
