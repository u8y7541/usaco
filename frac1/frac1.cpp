/*
ID: surya.s1
LANG: C++
TASK: frac1
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N;

struct frac {
	int n;
	int d;
};

bool compareFrac(frac a, frac b) { return ((float)(a.n)/a.d<(float)(b.n)/b.d); }

int gcd(int a, int b) {
	if (a*b == 0) return 0;
	if (b%a == 0 || a%b == 0) return min(a, b);
	return gcd(min(a, b), max(a, b)-min(a, b));
}

int main(void) {
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");

	fin>>N;
	frac fracList[(N*(N+1))/2];
	frac zero;
	zero.n = 0; zero.d = 1;
	fracList[0] = zero; 
	int numFracs = 1;
	for (int d = 1; d<=N; d++) {
		for (int n = 0; n<=d; n++) {
			if (gcd(n, d) == 1) {
				frac tmp;
				tmp.n = n; tmp.d = d;
				fracList[numFracs] = tmp;
				numFracs++;
			}
		}
	}
	sort(fracList, fracList+numFracs, compareFrac);

	for (int i = 0; i<numFracs; i++)
		fout<<fracList[i].n<<'/'<<fracList[i].d<<endl;

	return 0;
}
