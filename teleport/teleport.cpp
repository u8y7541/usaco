#include <fstream>
#include <utility>
#include <algorithm>
using namespace std;

bool manureSort(pair<int, int> a, pair<int, int> b) {
	return (a.second<b.second);
}

int abs(int a) {
	if (a>0) {
		return a;
	}
	return -a;
}

int myMin(int a, int b) {
	if (a<b) {
		return a;
	}
	return b;
}

int main(void) {
	ifstream fin;
	fin.open("teleport.in");
	int N;
	fin>>N;
	pair<int, int> manure[N];
	int destinations[N];
	int distances[N];
	int absolutes[N];
	for (int i = 0; i<N; i++) {
		fin>>manure[i].first>>manure[i].second;
		destinations[i] = manure[i].second;
		distances[i] = abs(manure[i].first-manure[i].second);
		absolutes[i] = abs(manure[i].first);
	}

	sort(destinations, destinations+N);
	long long min = -1, sum = 0;
	for (int i = 0; i<N-1; i++) {
		sum = 0;
		for (int j = 0; j<N; j++) {
			sum+=myMin(distances[j], absolutes[j]+abs(destinations[i]+1-manure[j].second));
		}
		if (sum<min || min == -1) {
			min = sum;
		}
	}

	ofstream fout;
	fout.open("teleport.out");
	fout<<min;
	fout.close();

	return 0;
}
