/*
ID: surya.s1
LANG: C++
TASK: ttwo
*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
void printArr(T* arr, int len) {
	for (int i = 0; i<len; i++) cout<<arr[i]<<' ';
	cout<<endl;
}

char grid[10][10];
int Fx, Fy, Cx, Cy, Fdir, Cdir, dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
bool visited[10][10][10][10][4][4];
// Fx, Fy, Cx, Cy, Fdir, Cdir

char& get(int x, int y) {return grid[y][x];}
bool valid(int a) {return (0<=a && a<10);}
void moveFJ() {
	Fx+=dir[Fdir][0]; Fy+=dir[Fdir][1];
	if (!valid(Fx) || !valid(Fy) || get(Fx, Fy) == '*') {
		Fx-=dir[Fdir][0]; Fy-=dir[Fdir][1];
		Fdir++;
		Fdir%=4;
	}
}
void moveC() {
	Cx+=dir[Cdir][0]; Cy+=dir[Cdir][1];
	if (!valid(Cx) || !valid(Cy) || get(Cx, Cy) == '*') {
		Cx-=dir[Cdir][0]; Cy-=dir[Cdir][1];
		Cdir++;
		Cdir%=4;
	}
}

int main(void) {
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");

	for (int y = 0; y<10; y++) {
		for (int x = 0; x<10; x++) {
			fin>>get(x,y);
			if (get(x,y) == 'F') {
				Fx = x;
				Fy = y;
			}
			if (get(x,y) == 'C') {
				Cx = x;
				Cy = y;
			}
		}
	}

	int mins = 0;
	while (Fx != Cx || Fy != Cy) {
		visited[Fx][Fy][Cx][Cy][Fdir][Cdir] = true;
		moveFJ();
		moveC();
		mins++;
		if (visited[Fx][Fy][Cx][Cy][Fdir][Cdir]) {
			fout<<0<<endl;
			return 0;
		}
	}
	fout<<mins<<endl;

	return 0;
}
