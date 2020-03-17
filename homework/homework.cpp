#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int q[100000];
int main(void) {
	ifstream input;
	input.open("homework.in");
	int N, sum;
	input>>N;
	for (int i = 0; i<N; i++) {
		input>>q[i];
		sum+=q[i];
	}
	input.close();

	int max = 0, partialSum = 0, min = 0;
	double avg = 0;
	for (int i = 1; i<N-2; i++) {
		partialSum+=q[i];
		min = *min_element(q+i, q+N);
		avg = ((double)(sum-partialSum-min))/(N-i-1);
		if (avg>max) {
			max = avg;
		}
	}

	ofstream output;
	output.open("homework.out");
	partialSum = 0; min = 0; avg = 0;
	for (int i = 1; i<N-2; i++) {
		partialSum+=q[i];
		min = *min_element(q+i, q+N);
		avg = ((double)(sum-partialSum-min))/(N-i-1);
		if (avg==max) {
			output<<i<<endl;
		}
	}
	output.close();
	return 0;
}
