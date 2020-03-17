#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream fin;
	fin.open("dishes.in");
	ofstream fout;
	fout.open("dishes.out");

	int N;
	fin>>N;
	queue<int> dirty;
	int tmp;
	for (int i = 0; i<N; i++) {
		fin>>tmp;
		dirty.push(tmp);
	}
	fin.close();

	vector<vector<int> > counter;
	vector<int> clean;
	clean.push_back(0);
	int answer = 0;
	bool placed;
	while (!dirty.empty()) {
		placed = false;
		int dish = dirty.front();
		dirty.pop();

		if (counter.empty() || counter.back().front() < dish) {
			vector<int> tmpQ;
			tmpQ.push_back(dish);
			counter.push_back(tmpQ);
			placed = true;
			cout<<dish<<" placed into new stack"<<endl;
			answer++;
			continue;
		}

		for (int i = 0; i<counter.size(); i++) {
			if (counter[i].front() > dish) {
				placed = true;
				while (counter[i].back() < dish) {
					if (counter[i].front() > clean.back()) {
						clean.push_back(counter[i].back());
						cout<<counter[i].back()<<" cleaned"<<endl;
						counter[i].pop_back();
						continue;
					}
					placed = false;
					break;
				}
				if (dish < clean.back()) {
					placed = false;
				}
				counter[i].push_back(dish);
				cout<<dish<<" placed into stack "<<i<<endl;
				cout<<"Placed boolean: "<<placed<<endl;
				break;
			}
		}
		if (!placed) {break;}
		answer++;
	}

	fout<<answer<<endl;
	fout.close();
	
	return 0;
}
