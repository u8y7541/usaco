#include <bits/stdc++.h>
using namespace std;

vector<set<int> > groups;
int main(void) {
	int N, G, length, tmp, cur;
	cin>>N>>G;
	vector<int> numberMap[N+1];
	for (int i = 0; i<G; i++) {
		cin>>length;
		groups.push_back(*(new set<int>()));
		for (int j = 0; j<length; j++) {
			cin>>tmp;
			numberMap[tmp].push_back(i);
			groups[i].insert(tmp);
		}
	}

	queue<int> invited;
	invited.push(1);
	int numInvited = 0;
	while (!invited.empty()) {
		cur = invited.front();
		invited.pop();
		for (int i = 0; i<numberMap[cur].size(); i++) {
			groups[numberMap[cur][i]].erase(cur);
			if (groups[numberMap[cur][i]].size() == 1) {
				invited.push(*(groups[numberMap[cur][i]].begin()));
			}
		}
		numInvited++;
	}
	cout<<numInvited<<endl;
	return 0;
}
