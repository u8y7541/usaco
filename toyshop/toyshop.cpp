#include <iostream>
#include <algorithm>
using namespace std;

double toys[25000][4];

bool sortfunc(int i[4], int j[4]) {
	return (i[3]<j[3]);
}

int main(void) {
	int N;
	cin>>N;
	int tmp1, tmp2;
	for (int i = 0; i<N; i++) {
		cin>>tmp1>>tmp2;
		toys[i][0] = (double) i;
		toys[i][1] = (double) tmp1;
		toys[i][2] = (double) tmp2;
		toys[i][3] = toys[i][1]/toys[i][2];
	}

	//sort(toys[0], toys[0]+N, sortfunc);

	for (int i = 0; i < 3; i++) {
		cout<<toys[i][0]<<'\n';
	}

	return 0;
}
