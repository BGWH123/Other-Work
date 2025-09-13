#include<iostream>
using namespace std;

int a[10] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};

void func(int a[], int n) {
	bool state = true;
	int pivot = 0;
	int left = 0;
	int right = n - 1;
	int left_temp=0;//记录中间的left
	int right_temp=n-1;//记录中间的right
	while (state) {
		while (left < right) {
			pivot = a[left];
			while (left < right && (pivot <= a[right]))
				right--;
			a[left] = a[right];
			while (left < right && (pivot >= a[left]))left++;
			a[right] = a[left];
		}
		a[left] = pivot;
		if(left==(n/2-1))state=false;
		if(left<(n/2-1)){//说明前面的元素小
			left_temp=++left;
			right=right_temp;
		}
		else{
			left=left_temp;
			right_temp=--right;
		}
	}
	cout<<"ans:"<<endl;
	int s1=0;
	int s2=0;
	for(int i=0;i<n/2;i++){
		s1+=a[i];
		s2+=a[n/2+i+1];
	}
	cout<<s2-s1w<<endl;
}
void show(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() {

func(a,10);

}
