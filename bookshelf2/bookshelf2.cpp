#include <iostream>
#include <cmath>
#include <numeric>
#include <limits>
using namespace std;

string toBinary(int n) {
	string r;
	while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
	return r;
}

int H[1000000];
int tmp[20];

int main(void) {
	int N, B;
	cin>>N>>B;
	for (int i = 0; i<N; i++) {
		cin>>H[i];
	}

	string binary;
	int solution = numeric_limits<int>::max();
	for (int i = 0; i<(int)(exp2(N)); i++) {
		binary = toBinary(i);
		for (int j = 0; j<N; j++) {
			tmp[j] = binary[j] - '0';
		}
		int product = inner_product(H, H+N, tmp, tmp+N);
		if (product < solution) {
			solution = product;
		}
	}
	cout<<solution;
}
