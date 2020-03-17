/*
ID: surya.s1
LANG: C++
TASK: maze1
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
} 

int W, H, exits[2][2], dist[2][300][300], d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
char maze[300][300];
char& get(int x, int y) {return maze[y][x];}

struct point {
	int x,y;
	point(int x1, int y1): x(x1), y(y1) {}
};

void flood(int x, int y, int exit) {
	fill_n((int*)(dist[exit]), 300*300, -1);
	dist[exit][y][x] = 0;
	queue<point> q;
	q.push(point(x, y));

	while (!q.empty()) {
		point cur = q.front();
		q.pop();
		int x = cur.x, y = cur.y;
		
		for (int i = 0; i<4; i++) {
			int nx = x+d[i][0], ny = y+d[i][1];
			int nxR = x+2*(nx-x), nyR = y+2*(ny-y);
			if (nx<1 || nx==2*W || ny<1 || ny==2*H) continue;
			if (get(nx,ny) == ' ' && (dist[exit][nyR][nxR]<0 || dist[exit][nyR][nxR] > dist[exit][y][x]+1)) {
				q.push(point(nxR,nyR));
				dist[exit][nyR][nxR] = dist[exit][y][x]+1;
			}
		}
	}
}

int main(void) {
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");

	fin>>W>>H;
	int exitNum = 0;
	for (int y = 0; y<2*H+1; y++) {
		for (int x = 0; x<2*W+1; x++) {
			fin>>noskipws>>get(x,y);
			if (get(x,y) == '\n')
				fin>>noskipws>>get(x,y);
			if ((x==0 || x==2*W || y==0 || y==2*H) && (get(x,y) == ' ')) {
				exits[exitNum][0] = x+(x<1 ? 1:(x==2*W ? -1:0));
				exits[exitNum++][1] = y+(y<1 ? 1:(y==2*H ? -1:0));
			}
		}
	}

	flood(exits[0][0],exits[0][1],0);
	flood(exits[1][0],exits[1][1],1);
	int maxOfMins = 0;
	for (int x = 1; x<2*W+1; x+=2) {
		for (int y = 1; y<2*H+1; y+=2)
			maxOfMins = max(maxOfMins, min(dist[0][y][x],dist[1][y][x]));
	}
	fout<<maxOfMins+1<<endl;

	return 0;
}
