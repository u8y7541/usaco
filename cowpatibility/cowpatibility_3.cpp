#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream fin;
	fin.open("cowpatibility.in");
	ofstream fout;
	fout.open("cowpatibility.out");

	int N;
	fin>>N;
	map<int, set<int> > flavors;
	set<int> uniqueFlavors;
	int f1, f2, f3, f4, f5;
	for (int i = 0; i<N; i++) {
		fin>>f1>>f2>>f3>>f4>>f5;
		try {
			flavors[f1].insert(i);
		}
		catch (int e) {
			set<int> newSet;
			newSet.insert(i);
			flavors.insert(make_pair(f1, newSet));
		}
		int arr[5] = {f1,f2,f3,f4,f5};
		for (int i = 0; i<5; i++) {
			uniqueFlavors.insert(arr[i]);
		}
	}
	fin.close();

	for (set<int>::iterator it = uniqueFlavors.begin(); it != uniqueFlavors.end() ; it++) {
		cout<<*it<<": ";
		for (set<int>::iterator it2 = flavors[*it].begin(); it2 != flavors[*it].end(); it2++) {
			cout<<*it2<<" ";
		}
		cout<<endl;
	}

	int answer = 0;
	/*for (int i = 0; i<N-1; i++) {
		for (int j = i+1; j<N; j++) {
			if (!share(flavors[i], flavors[j])) {
				answer++;
			}
		}
	}*/

	fout<<answer;
	fout.close();
	return 0;
}
