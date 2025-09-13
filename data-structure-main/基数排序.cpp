#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<random>
#include<time.h>
#include<cmath>
using namespace std;
int main() {
	vector<queue<int>>v(10);
	srand(time(0));
	vector<int>a(1000);
	for (int i = 0; i < 1000; i++) {
		a[i] = rand() % 900 + 100;
	}//¹¹Ôì
	for (int k = 0; k < 3; k++) { //ÈýÂÖ
		for (auto i : a) {
			int t = (i / static_cast<int>(pow(10.0, k))) % 10;
			//	cout<<t<<endl;
			v[t].push(i);
		}
		int index = 0;
		for (int j = 0; j < 10; j++) {
			while (!v[j].empty()) {
				a[index++] = v[j].front();
				v[j].pop();

			}
		}
	}
	for (auto i : a)cout << i << " ";
}
