#include<iostream>
using namespace std;

int a[10]={49,38,65,97,76,13,27,49,55,4};


int parttition(int a[],int low,int hight){
	int pivot=a[low];
	while(low<hight){
		while(hight>low&&a[hight]>=pivot)hight--;
		a[low]=a[hight];
		while(low<hight&&a[low]<=pivot)low++;
		a[hight]=a[low];
	}
	a[low]=pivot;
	return low;
};

void quick_sort(int a[],int low,int hight){
	if(low<hight){
		int pos=parttition(a,low,hight);
		quick_sort(a,low,pos-1);
		quick_sort(a,pos+1,hight);
	}
};
void show(int a[],int n){
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	quick_sort(a,0,9);
	show(a,10);	
}
