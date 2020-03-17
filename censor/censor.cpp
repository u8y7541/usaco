#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main(void) {
	ifstream fin;
	fin.open("censor.in");
	string S, T;
	fin>>S>>T;
	fin.close();

	/*int counter = 0;
	for (int i = 0; i<S.length(); i++) {
		if (S[i] = T[counter]) {
			counter++;
		}
		else if (counter>0) {
			counter = 0;
		}
	}*/

	while (S.find(T)!=string::npos) {
		S = regex_replace(S, T, "");
	}

	ofstream fout;
	fout.open("censor.out");
	fout<<S;
	fout.close();

	return 0;
}
