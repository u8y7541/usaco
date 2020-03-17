/*
ID: surya.s1
LANG: C++
TASK: pprime
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int numDigits(int x) {
	int ans = 0;
	while (x>0) {
		x /= 10;
		ans++;
	}
	return ans;
}

int reverse(int x, int d) {
	int ans = 0;
	int pow10 = pow(10, d-1);
	for (; d>0; d--) {
		ans += pow10*(x%10);
		x /= 10;
		pow10 /= 10;
	}
	return ans;
}

int palindromize(int x, int d, bool repeatMidDigit) {
	if (repeatMidDigit) return (x/10)*pow(10, d)+reverse(x, d);
	return x*pow(10, d)+reverse(x, d);
}

bool isPrime(int x) {
	for (int i = 2; i*i<=x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}

int a, b;

bool valid(int x) { return (a<=x && x<=b); }

int main(void) {
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");

	fin>>a>>b;
	
	int x = numDigits(a), y = numDigits(b);
	int starting = pow(10, x/2-1+x%2);
	for (int digits = x; digits<=y; digits++) {
		for (int i = starting; i<starting*10; i++) {
			int p = palindromize(i, digits/2+digits%2, digits%2==1);
			if (!valid(p)) continue;
			if (isPrime(p)) fout<<p<<endl;
		}
		if (digits%2==0) starting *= 10;
	}

	return 0;
}
