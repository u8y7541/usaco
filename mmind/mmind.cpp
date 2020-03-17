#include <iostream>
#include <string>
using namespace std;

int positive(int x, string b) {
	string a = to_string(x);
	int counter = 0;
	for (int i = 0; i<4; i++) {
		if (a[i] == b[i]) {
			counter++;
		}
	}
	return counter;
}

int negative(int x, string b) {
	string a = to_string(x);
	for (int i = 0; i<4; i++) {
		if (a[i] == b[i]) {
			a[i] = '*';
			b[i] = '+';
		}
	}

	int counter = 0;
	for (int i = 0; i<4; i++) {
		for (int j = 0; j<4; j++) {
			if (a[i] == b[j]) {
				counter++;
				break;
			}
		}
	}
	return counter;
}

int compatible(int x, string b, int pos, int neg) {
	return (positive(x, b) == pos && negative(x, b) == neg);
}

string numbers[105];
int pos[105], neg[105];

int main(void) {
	int N;
	cin>>N;
	for (int i = 0; i<N; i++) {
		cin>>numbers[i]>>pos[i]>>neg[i];
	}

	bool answer;
	for (int i = 1000; i<10000; i++) {
		answer = true;
		for (int j = 0; j<N; j++) {
			if (!compatible(i, numbers[j], pos[j], neg[j])) {
				answer = false;
				break;
			}
		}
		if (answer) {
			cout<<i;
			break;
		}
		if (i == 9999) {
			cout<<"NONE";
		}
	}
	return 0;
}
