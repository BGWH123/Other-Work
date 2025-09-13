#include<iostream>
using namespace std;

int a[10] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};


void insert_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			int t = a[i];
			int left = 0;
			int right = i - 1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (a[mid] > t) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			}
			for(int k=i-1;k>=left;k--){
				a[k+1]=a[k];
			}
			a[left]=t;
		}

	}
};
void show(int a[], int n) {
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
int main() {
	insert_sort(a, 10);
	show(a, 10);

}
