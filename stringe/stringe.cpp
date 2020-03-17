#include <iostream>
#include <string>
using namespace std;

string f(int N, string S) {
	return S.substr(N)+S;
}

string strings[105];
int N[105], C[105];

int main(void) {
	int Z;
	cin>>Z;
	for (int i = 0; i<Z; i++) {
		cin>>N[i]>>C[i]>>strings[i];
	}

	for (int i = 0; i<Z; i++) {
		for (int j = 0; j<C[i]; j++) {
			strings[i] = f(N[i], strings[i]);
		}
		cout<<strings[i]<<'\n';
	}
	return 0;
}
