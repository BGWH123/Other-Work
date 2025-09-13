#include<iostream>
#include<algorithm>
using namespace std;

int a[10]={49,38,65,97,76,13,27,49,55,4};


void merge(int a[],int left,int mid,int right){
	int b[10];
	for(int i=left;i<=right;i++){
		b[i]=a[i];
	}
	int p=left;
	int q=mid;
	int m=mid+1;
	int n=right;
	int i=left;
	while(p<=q&&m<=n){
		if(b[p]<=b[m]){
			a[i++]=b[p++];	
		}
		else a[i++]=b[m++];
	}
	while(p<=q)a[i++]=b[p++];
	while(m<=n)a[i++]=b[m++];
};

void merge_sort(int a[],int left,int right){
		if(left<right){
			int mid=left+(right-left)/2;
			merge_sort(a,left,mid);
			merge_sort(a,mid+1,right);
			merge(a,left,mid,right);
		}
};
void show(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	merge_sort(a,0,9);
	show(a,10);
	
}
