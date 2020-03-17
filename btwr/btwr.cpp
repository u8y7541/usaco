#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N;
pair<int, int> bales[20];

string toBinary(int n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
	return r;
}

bool widthSort(pair<int, int> a, pair<int, int> b) {
	return a.first>b.first;
}

int main(void) {
	cin>>N;
	for (int i = 0; i<N; i++) {
		cin>>bales[i].first>>bales[i].second;
	}
	sort(bales, bales+N, widthSort);
	string bin;
	int previous, counter, counter2, max = 0;
	for (int i = 0; i<(1<<N); i++) {
		bin = toBinary(i);
		counter2 = 0;
		for (int j = 0; j<bin.length(); j++) {
			if (bin[j] == '1') {
				counter2++;
			}
		}
		if (counter2<=max) {
			continue;
		}
		while (bin.length()<N) {
			bin = "0"+bin;
		}
		
		previous = 0;
		counter = 0;
		for (int j = 0; j<N; j++) {
			if (bin[j]=='1' && (bales[j].second<previous || previous == 0)) {
				previous = bales[j].second;
				counter++;
			}
		}
		if (counter>max) {
			max = counter;
		}
	}
	cout<<max;
}
