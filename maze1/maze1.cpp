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

int W, H, exits[2][2], d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
char maze[300][300];
char& get(int x, int y) {return maze[y][x];}

struct point {
	int x,y,dist;
	point(int x1, int y1, int dist1): x(x1), y(y1), dist(dist1) {}
};


int shortestPath(int x, int y) {
	bool visited[2*H+1][2*W+1];
	fill_n((bool*)visited, (2*H+1)*(2*W+1), false);
	queue<point> q;
	q.push(point(x,y,0));

	int dist = 101*39+123;
	while (!q.empty()) {
		point curP = q.front();
		q.pop();
		int x = curP.x; int y = curP.y;
		if (visited[y][x]) continue;
		visited[y][x] = true;
		int steps = curP.dist+1;
		
		if ((x==exits[0][0] && y==exits[0][1]) || (x==exits[1][0] && y==exits[1][1])) {
			dist = min(steps, dist);
			continue;
		}

		for (int i = 0; i<4; i++) {
			if (get(x+d[i][0],y+d[i][1]) == ' ' && !visited[y+2*d[i][1]][x+2*d[i][0]])
				q.push(point(x+2*d[i][0],y+2*d[i][1],steps));
		}
	}
	return dist;
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

	int maxDist = 0;
	for (int x = 1; x<2*W+1; x+=2) {
		for (int y = 1; y<2*H+1; y+=2)
			maxDist = max(maxDist, shortestPath(x, y));
	}
	fout<<maxDist<<endl;

	return 0;
}
