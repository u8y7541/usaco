/*
ID: surya.s1
LANG: C++
TASK: crypt1
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

int N;

bool checkInArr(int x, int* arr) {
	for (int i = 0; i<N; i++) {
		if (arr[i] == x) return true;
	}
	return false;
}

int main(void) {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	fin>>N;
	int digits[N];
	for (int i = 0; i<N; i++) {
		fin>>digits[i];
	}

	int a1,a2,a3,b1,b2,n1,n2,p1,p2,p11,p12,p13,p21,p22,p23,m,m1,m2,m3,m4;
	int total = 0;
	for (int i = 0; i<N*N*N*N*N; i++) {
		a1 = digits[(i/(1))%N];
		a2 = digits[(i/(N))%N];
		a3 = digits[(i/(N*N))%N];
		b1 = digits[(i/(N*N*N))%N];
		b2 = digits[(i/(N*N*N*N))%N];
		n1 = 100*a1+10*a2+a3; n2 = 10*b1+b2;
		p1 = n1*b2; p2 = n1*b1;
		m = n1*n2;

		if (p1 > 999 || p2 > 999 || m > 9999) continue;
		
		p11 = p1/100; p12 = (p1/10)%10; p13 = p1%10;
		p21 = p2/100; p22 = (p2/10)%10; p23 = p2%10;
		if (!(checkInArr(p11,digits) && checkInArr(p12,digits) && checkInArr(p13,digits) &&
			  checkInArr(p21,digits) && checkInArr(p22,digits) && checkInArr(p23,digits))) continue;
		m1 = m/1000; m2 = (m/100)%10; m3 = (m/10)%10; m4 = m%10;
		if (!(checkInArr(m1,digits) && checkInArr(m2,digits) &&
			  checkInArr(m3,digits) && checkInArr(m4,digits))) continue;

		cout<<n1<<endl<<n2<<endl<<p1<<endl<<p2<<' '<<endl<<m;
		total++;
	}
	fout<<total<<endl;

	return 0;
}
