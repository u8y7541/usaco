/*
ID: surya.s1
LANG: C++
TASK: castle
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

bool left(int x) { return x&1; }
bool up(int x) { return x&2; }
bool right(int x) { return x&4; }
bool down(int x) {return x&8; }

int M, N, curComponent, maxRoomSize, maxConnectedRoom, mcrX, mcrY;
bool mcrD;
int castle[55][55];
int components[55][55];
vector<int> roomSizes;

int get(int x, int y) {
	if (0<=x && x<M && 0<=y && y<N) return castle[y][x];
	return 0;
}
int getComponent(int x, int y) {
	if (0<=x && x<M && 0<=y && y<N) return components[y][x];
	return 0;
}

void floodFill(int x, int y) {
	curComponent++;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	components[y][x] = curComponent;

	int curX, curY, roomSize = 0;
	while (!q.empty()) {
		curX = q.front().first;
		curY = q.front().second;
		q.pop();
		roomSize++;

		if (getComponent(curX+1, curY) == 0 && !right(get(curX, curY)) && !left(get(curX+1, curY))) {
			q.push(make_pair(curX+1, curY));
			components[curY][curX+1] = curComponent;
		}
		if (getComponent(curX-1, curY) == 0 && !left(get(curX, curY)) && !right(get(curX-1, curY))) {
			q.push(make_pair(curX-1, curY));
			components[curY][curX-1] = curComponent;
		}
		if (getComponent(curX, curY+1) == 0 && !down(get(curX, curY)) && !up(get(curX, curY+1))) {
			q.push(make_pair(curX, curY+1));
			components[curY+1][curX] = curComponent;
		}
		if (getComponent(curX, curY-1) == 0 && !up(get(curX, curY)) && !down(get(curX, curY-1))) {
			q.push(make_pair(curX, curY-1));
			components[curY-1][curX] = curComponent;
		}
	}
	roomSizes.push_back(roomSize);
	maxRoomSize = max(maxRoomSize, roomSize);
}

void getAllComponents() {
	fill((int*)components, (int*)components+M*N, 0);
	for (int x = 0; x<M; x++) {
		for (int y = 0; y<N; y++)
			if (getComponent(x, y) == 0) floodFill(x, y);
	}
}

void joinRooms() {
	// Each tuple is: component1, component2, wallX, wallY, direction (true = N, false = E) 
	vector<tuple<int, int, int, int, bool> > componentMap;
	bool connected[curComponent+1][curComponent+1];
	fill((bool*)connected, (bool*)connected+(curComponent+1)*(curComponent+1), false);
	for (int i = 0; i<curComponent+1; i++)
		connected[i][i] = true;

	for (int x = 0; x<M; x++) {
		for (int y = N-1; y>=0; y--) {
			if (up(get(x, y)) && getComponent(x, y-1)) {
				if (!connected[getComponent(x, y)][getComponent(x, y-1)]) {
					connected[getComponent(x, y)][getComponent(x, y-1)] = true;
					connected[getComponent(x, y-1)][getComponent(x, y)] = true;
					componentMap.push_back(make_tuple(getComponent(x, y), getComponent(x, y-1), x, y, true));
				}
			}
			if (right(get(x, y)) && getComponent(x+1, y)) {
				if (!connected[getComponent(x, y)][getComponent(x+1, y)]) {
					connected[getComponent(x, y)][getComponent(x+1, y)] = true;
					connected[getComponent(x+1, y)][getComponent(x, y)] = true;
					componentMap.push_back(make_tuple(getComponent(x, y), getComponent(x+1, y), x, y, false));
				}
			}
		}
	}

	for (int i = 0; i<componentMap.size(); i++) {
		tuple<int, int, int, int, bool> tmp = componentMap[i];
		int combined = roomSizes[get<0>(tmp)-1]+roomSizes[get<1>(tmp)-1];
		if (combined>maxConnectedRoom) {
			mcrX = get<2>(tmp);
			mcrY = get<3>(tmp);
			mcrD = get<4>(tmp);
			maxConnectedRoom = combined;
		}
	}
}

int main(void) {
	ifstream fin("castle.in");
	ofstream fout("castle.out");

	fin>>M>>N;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			fin>>castle[i][j];
		}
	}
	getAllComponents();
	fout<<curComponent<<endl;
	fout<<maxRoomSize<<endl;
	joinRooms();
	fout<<maxConnectedRoom<<endl;
	fout<<mcrY+1<<' '<<mcrX+1<<' '<<(mcrD? 'N':'E')<<endl;

	return 0;
}
