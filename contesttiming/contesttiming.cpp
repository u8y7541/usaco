#include <iostream>

using namespace std;
int main(void) {
	int d, h, m;
	cin>>d>>h>>m;
	d-=11; h-=11; m-=11;
	int answer = d*24*60+h*60+m;
	if (answer<0) {
		cout<<-1;
		return 0;
	}
	cout<<answer;
	return 0;
}
	
