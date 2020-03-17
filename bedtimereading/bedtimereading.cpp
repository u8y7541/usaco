#include <iostream>
using namespace std;

int main(void) {
	int number;
	cin>>number;
	int answer = 0;
	for (int i = 1; i*i<=number; i++) {
		if (number%i == 0) {
			answer+=i;
			if (i != number/i) {
				answer+=number/i;
			}
		}
	}
	cout<<answer;
}

