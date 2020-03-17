#include <bits/stdc++.h>
using namespace std;

int barn[200][200];

bool pointInRect(int px, int py, int lx, int ly, int rx, int ry) {
	return (px > lx && px < rx && py > ly && py < ry);
}

bool rectsOverlap(int lx1,int ly1,int rx1,int ry1,int lx2,int ly2,int rx2,int ry2) {
	return pointInRect(lx1, ly1, lx2, ly2, rx2, ry2) || pointInRect(rx1, ry1, lx2, ly2, rx2, ry2) || pointInRect(rx1, ly1, lx2, ly2, rx2, ry2) || pointInRect(lx1, ry1, lx2, ly2, rx2, ry2);
}

int main(void) {
	ifstream fin;
	fin.open("paintbarn.in");
	ofstream fout;
	fout.open("paintbarn.out");
	
	int N, K;
	fin>>N>>K;
	int lx, ly, rx, ry;
	for (int i = 0; i<N; i++) {
		fin>>lx>>ly>>rx>>ry;
		for (int x = lx; x<=rx; x++) {
			for (int y = ly; y<=ry; y++) {
				barn[x][y]++;
			}
		}
	}

	vector<pair<int, int> > relevant;
	for (int x = 0; x<200; x++) {
		for (int y = 0; y<200; y++) {
			if (barn[x][y] = K-1) {
				relevant.push_back(make_pair(x, y));
			}
		}
	}

	int max = 0;
	for (int i = 0; i<relevant.size(); i++) {
		for (int j = i; j<relevant.size(); j++) {
			for (int k = j; k<relevant.size(); k++) {
				for (int l = k; l<relevant.size(); l++) {
					if (relevant[i].first > relevant[j].first || relevant[i].second > relevant[j].second || relevant[k].first > relevant[l].first || relevant[k].second > relevant[l].second) {
						continue;
					}
					if (rectsOverlap(relevant[i].first, relevant[i].second, relevant[j].first, relevant[j].second, relevant[k].first, relevant[k].second, relevant[l].first, relevant[l].second)) {
						continue;
					}
					int newBarn[200][200];
					memcpy((void*)newBarn, (void*)barn, 200*200*sizeof(int));
					for (int x = relevant[i].first; x<=relevant[j].first; x++) {
						for (int y = relevant[i].second; y<=relevant[j].second; y++) {
							newBarn[x][y]++;
						}
					}
					for (int x = relevant[k].first; x<=relevant[l].first; x++) {
						for (int y = relevant[k].second; y<=relevant[l].second; y++) {
							newBarn[x][y]++;
						}
					}
					int ans = 0;
					for (int x = 0; x<200; x++) {
						for (int y = 0; y<200; y++) {
							if (newBarn[x][y] == K) {
								ans++;
							}
						}
					}
					if (ans > max) {
						max++;
					}
				}
			}
		}
	}

	fout<<max<<endl;
	fout.close();

	return 0;
}
