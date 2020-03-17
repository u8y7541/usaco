#include <iostream>
using namespace std;

int digitsum(string n) {
	int answer = 0;
	for (unsigned int i = 0; i < n.length(); i++) {
		answer += n[i]-'0';
	}
	return answer;
}

int main(void) {
	string a, b;
	cin>>a>>b;
	cout<<digitsum(a)*digitsum(b);
	return 0;
}
