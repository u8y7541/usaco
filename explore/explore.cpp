#include <iostream>
#include <algorithm>
using namespace std;

int landmarks[50000];

int abs(int x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

bool compare(int x, int y) {
	return abs(x)<abs(y);
}

int main(void) {
	int T, N;
	cin>>T>>N;
	for (int i = 0; i < N; i++) {
		cin>>landmarks[i];
	}

	sort(landmarks, landmarks+N, compare);

	int total = landmarks[0];
	for (int i = 0; i < N - 1; i++) {
		if (total + abs(landmarks[i]-landmarks[i+1]) > T) {
			cout<<i+1;
			break;
		}
		total += abs(landmarks[i]-landmarks[i+1]);
	}
	return 0;
}
