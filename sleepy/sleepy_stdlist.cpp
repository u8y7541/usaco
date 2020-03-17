#include <bits/stdc++.h>
using namespace std;

int N;

// Insert first element BEFORE "index"
void moveTo(list<int>& order, iterator<int> it) {
	list<int> tmpList;
	tmpList.push_back(*order.begin());
	order.splice(it, tmpList);
}

int solve(list<int>& order, int* solution) {
	list<int>::iterator<int> bump;
	list<int>::iterator<int> it;
	bool flag = false;
	int bumpIndex = 0;
	for (it = order.rbegin(); it != order.rend(); it++) {
		if (*it < *(it+1)) {
			bump = it;
			flag = true;
			break;
		}
		bumpIndex++;
	}
	if (!flag) {return 0;}

	int moveCount = 0;
	int movedTo = 0;
	while (bumpIndex  > 0) {
		flag = false;
		list<int>::iterator<int> it;
		movedTo = bumpIndex;
		for (it = bump; it != order.end(); it++) {
			if (*it > *order.begin()) {
				moveTo(order, it);
				flag = true;
				break;
			}
			movedTo++;
		}
		if (!flag) {
			moveTo(order, order.end());
		}
		bumpIndex--;

		solution[moveCount] = movedTo - 1;
		moveCount++;
	}

	return moveCount;
}

int main(void) {
	ifstream fin;
	ofstream fout;
	fin.open("sleepy.in");
	fout.open("sleepy.out");

	fin>>N;
	list<int> order;
	int tmp;
	for (int i = 0; i<N; i++) {
		fin>>tmp;
		order.push_back(tmp);
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
