#include <bits/stdc++.h>
using namespace std;

int N;

// Insert first element BEFORE "index"
/*void moveTo(int* order, int index) {
	int first = order[0];
	for (int i = 1; i<index; i++) {
		order[i-1] = order[i];
	}
	order[index-1] = first;
}*/

int solve(int* order, int* solution) {
	int bump = -1;
	for (int i = N-1; i>0; i--) {
		if (order[i]<order[i-1]) {
			bump = i;
			break;
		}
	}
	if (bump < 0) {return 0;}

	set<int> ordered;
	for (int i = bump; i<N; i++) {
		ordered.insert(order[i]);
	}
	int current = 0;
	int iValue = 0;
	int moveCount = 0;
	bool flag = false;
	while (bump > 0) {
		set<int>::iterator it;
		iValue = bump;
		ordered.insert(order[current]);
		it = ordered.find(order[current]);
		iValue = bump+distance(ordered.begin(), it);

		current++;
		solution[moveCount] = iValue - 1;
		moveCount++;
		bump--;
	}

	return moveCount;
}

int main(void) {
	ifstream fin;
	ofstream fout;
	fin.open("sleepy.in");
	fout.open("sleepy.out");

	fin>>N;
	int order[N];
	for (int i = 0; i<N; i++) {
		fin>>order[i];
	}
	fin.close();

	int solution[N];
	int moveCount = solve(order, solution);
	fout<<moveCount<<endl;
	for (int i = 0; i<moveCount-1; i++) {
		fout<<solution[i]<<' ';
	}
	fout<<solution[moveCount-1]<<endl;
	fout.close();
	
	return 0;
}
