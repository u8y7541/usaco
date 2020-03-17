/*
ID: surya.s1
LANG: C++
TASK: transform
*/
#include <bits/stdc++.h>
using namespace std;



int N;
char at(char* grid, int i, int j) {return grid[i*N+j];}

bool check90Rotation(char* grid1, char* grid2) {
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			if (at(grid1, i, j) != at(grid2, j, N-1-i)) return false;
		}
	}
	return true;
}
bool check180Rotation(char* grid1, char* grid2) {
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			if (at(grid1, i, j) != at(grid2, N-1-i, N-1-j)) return false;
		}
	}
	return true;
}
bool check270Rotation(char* grid1, char* grid2) {
	return check90Rotation(grid2, grid1);
}
bool checkReflection(char* grid1, char* grid2) {
	for (int i = 0; i<N*N; i++) {
		if (grid1[i] != at(grid2, i/N, N-1-i%N)) return false;
	}
	return true;
}
bool checkCombination(char* grid1, char* grid2) {
	char reflected[N*N];
	for (int i = 0; i<N*N; i++) reflected[i] = at(grid1, i/N, N-1-i%N);
	return (check90Rotation(reflected, grid2) || check180Rotation(reflected, grid2) || check270Rotation(reflected, grid2));
}
bool checkSame(char* grid1, char* grid2) {
	for (int i = 0; i<N*N; i++) {
		if (grid1[i] != grid2[i]) return false;
	}
	return true;
}

int main(void) {
	ifstream fin("transform.in");
	ofstream fout("transform.out");

	fin>>N;
	char grid1[N*N], grid2[N*N];
	for (int i = 0; i<N*N; i++) fin>>grid1[i];
	for (int i = 0; i<N*N; i++) fin>>grid2[i];

	int ans = 7;
	if (check90Rotation(grid1, grid2)) ans = 1;
	else if (check180Rotation(grid1, grid2)) ans = 2;
	else if (check270Rotation(grid1, grid2)) ans = 3;
	else if (checkReflection(grid1, grid2)) ans = 4;
	else if (checkCombination(grid1, grid2)) ans = 5;
	else if (checkSame(grid1, grid2)) ans = 6;
	fout<<ans<<endl;

	return 0;
}
