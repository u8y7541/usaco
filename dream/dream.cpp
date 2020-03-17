#include <iostream>
#include <string>

using namespace std;

int digitcounts[10];

int main(void) {
	int m, n;
	cin>>m>>n;

	for (int i = m; i<=n; i++) {
		string tmp = to_string(i);
		for (int j = 0; j<tmp.length(); j++) {
			digitcounts[tmp[j] - '0']++;
		}
	}

	for (int i = 0; i<10; i++) {
		cout<<digitcounts[i];
		if (i!=9) {
			cout<<' ';
		}
	}

	return 0;
}
