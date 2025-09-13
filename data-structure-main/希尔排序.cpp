#include<iostream>
using namespace std;

int a[10] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};


void xier_sort(int a[], int n) {
	for (int d = n / 2; d >= 1; d /= 2) {
		//每次距离
		for(int i=d;i<n;i++){//每次不同组
			if(a[i]<a[i-d]){//插入
				int t=a[i];
				int j=0;
				for(j=i-d;j>=0;j-=d){
					if(a[j]>t)a[j+d]=a[j];
					else break;
				}
				a[j+d]=t;
			}
		}
	}
};
void show(int a[], int n) {
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
int main() {
	xier_sort(a, 10);
	show(a, 10);

}
