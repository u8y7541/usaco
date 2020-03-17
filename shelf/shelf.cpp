#include <iostream>
#include <algorithm>

using namespace std;

int H[20000];

bool comp(int i, int j) {
	return (i>j);
}

int main(void) {
	int N, B;
	cin>>N>>B;
	for (int i = 0; i < N; i++) {
		cin>>H[i];
	}

	sort(H, H+N, comp);
	int sum = 0;
	int counter = 0;
	for (int i = 0; sum<B; i++) {
		sum += H[i];
		counter++;
	}
	cout<<counter;

	return 0;
}
