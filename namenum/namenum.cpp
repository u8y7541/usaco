#include <iostream>
#include <string>

char numbers[8][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'},
					  {'J', 'K', 'L'}, {'M', 'N', 'O'}, {'P', 'R', 'S'},
					  {'T', 'U', 'V'}, {'W', 'X', 'Y'}};

string names[5005];

int main(void) {
	int N;
	cin>>N;
	string n = to_string(N);
	int length = 0;
	while (!cin.eof()) {
		cin>>names[length];
		length++;
	}

	bool possibleName = false;
	for (int i = 0; i<length; i++) {
		if (names[i].length() != n.length()) {
			continue;
		}
		for (int j = 0; j<n.length(); j++) {
			int letters[3] = numbers[n[j]-'0'-2];
			bool foundLetter = false;
			for (int k = 0; k<3; k++) {
				if (names[j] == letters[k]) {
					foundLetter = true;
				}
			}
			if (!foundLetter) {
				break;
			}
			if (j == n.length()-1) {
				possibleName = true;
			}
		}
		if (possibleName) {
			cout<<names[i];
			break;
		}
	}
	return 0;
}

}
