#include <iostream>
#include <string>
using namespace std;

int lengths[80];

int main(void) {
	string moo1, moo2;
	cin>>moo1>>moo2;

	int counter = 0;
	int j = 0;
	int length = 0;
	for (int i = 0; i < moo1.length(); i++) {
		if (moo2[j] == moo1[i]) {
			length++;
			j++;
			if (i != moo1.length()-1) {
				continue;
			}
		}
		if (length != 0) {
			lengths[counter] = length;
			counter++;
		}
		length = 0;
		j = 0;
	}

	j = 0;
	length = 0;
	for (int i = 0; i < moo2.length(); i++) {
		if (moo1[j] == moo2[i]) {
			length++;
			j++;
			if (i != moo2.length()-1) {
				continue;
			}
		}
		if (length != 0) {
			lengths[counter] = length;
			counter++;
		}
		length = 0;
		j = 0;
	}

	int max = 0;
	for (int i = 0; i < 80; i++) {
		if (lengths[i]>max) {
			max = lengths[i];
		}
	}
	cout<<max;

	return 0;
}
