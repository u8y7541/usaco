#include <bits/stdc++.h>
using namespace std;

struct node {
	int value;
	node* next;
	node* prev;
};

int N;

// Insert first element BEFORE "index"
void moveTo(node* begin, node* end, node* index) {
	if (index == nullptr) {
		int val = begin->value;
		node* originalPtr = begin;
		begin = begin->next;

		originalPtr = new node;
		originalPtr->value = val;
		originalPtr->prev = end;
		end->next = originalPtr;
		originalPtr->next = nullptr;
		return;
	}
	int val = begin->value;
	node* originalPtr = begin;
	begin = begin->next;

	originalPtr = new node;
	originalPtr->value = val;
	originalPtr->next = index;
	originalPtr->prev = index->prev;
	index->prev = originalPtr;
}

int solve(node* begin, node* end, int* solution) {
	node* bump = nullptr;
	int bumpIndex = N-1;
	for (node* current = end; current != nullptr; current = current->prev) {
		if (current->value < (current->prev)->value) {
			bump = current;
			break;
		}
		bumpIndex--;
	}

	if (bump == nullptr) {return 0;}

	int moveCount = 0;
	bool flag = false;
	int iValue = 0;
	while (bumpIndex > 0) {
		flag = false;
		iValue = bumpIndex;
		for (node* i = bump; i != nullptr; i = i->next) {
			if (i->value > begin->value) {
				moveTo(begin, end, i);
				flag = true;
				break;
			}
			iValue++;
		}
		if (!flag) {
			moveTo(begin, end, nullptr);
			iValue = N;
		}
		bumpIndex--;

		solution[moveCount] = iValue - 1;
		moveCount++;
	}

	return moveCount;
}

int main(void) {
	ifstream fin;
	ofstream fout;
	fin.open("sleepy.in");
	fout.open("sleepy.out");

	fin>>N;

	int tmp;
	fin>>tmp;
	node* begin = new node;
	begin->value = tmp;
	begin->prev = nullptr;
	node* end = begin;
	for (int i = 0; i<N; i++) {
		fin>>tmp;
		node* newNode = new node;
		newNode->value = tmp;
		newNode->prev = end;
		end->next = newNode;
		end = newNode;
	}
	end->next = nullptr;
	fin.close();

	int solution[N];
	int moveCount = solve(begin, end, solution);
	fout<<moveCount<<endl;
	for (int i = 0; i<moveCount-1; i++) {
		fout<<solution[i]<<' ';
	}
	fout<<solution[moveCount-1]<<endl;
	fout.close();
	
	return 0;
}
