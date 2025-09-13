#include<iostream>
#include<algorithm>
using namespace std;

int a[11] = {0,53,17,9,35,65,87,32,32,2,8};


void adjust_sort(int a[], int n, int k) {
		a[0]=a[k];
	for(int i=k;i<=n;i++){
		if(i<n&&a[i]>a[i+1])i++;
		if(a[i]>a[0])break;
		else{
			a[k]=a[i];//放到顶上面
			k=i;
		}
	}
	a[k]=a[0];
};

void build_sort(int a[], int n) {
	for (int i = n / 2; i >0; i--) {
		adjust_sort(a,n,i);
	}
}


void heap_sort(int a[], int n) {
	build_sort(a,n);
	for(int i=n;i>1;i--){
		swap(a[1],a[i]);
		adjust_sort(a,i-1,1);//每次调整前i-1个
	}
}
void show(int a[], int n) {
	for (int i = 1; i < n; i++) {
		cout << a[i] << " ";
	}
}
int main() {
	heap_sort(a, 10);
	show(a, 11);

}
