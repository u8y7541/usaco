#include <iostream>
using namespace std;

int parents[5000];
int P, NS, T;

int main(void) {
	cin>>P>>NS>>T;
	int parent, child1, child2;
	for (int i = 0; i<NS; i++) {
		cin>>parent>>child1>>child2;
		parents[child1]=parent;
		parents[child2]=parent;
	}

	int counter = 1;
	int current = T;
	int path[5000];
	path[0] = T;
	while (current != 1) {
		current = parents[current];
		path[counter] = current;
		counter++;
	}

	cout<<counter<<endl;
	for (int i = counter-1; i>=0; i--) {
		cout<<path[i]<<endl;
	}
}
