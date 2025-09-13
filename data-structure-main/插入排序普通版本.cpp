#include<iostream>
using namespace std;

int a[10]={49,38,65,97,76,13,27,49,55,4};


void insert_sort(int a[],int n){
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]){
			int t=a[i];
			int j=0;
			for(j=i-1;j>=0;j--){
			if(a[j]>t)a[j+1]=a[j];
			else{
				break;
			}
			}
			a[j+1]=t;
		}
	}
};
void show(int a[],int n){
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	insert_sort(a,10);
	show(a,10);
	
}
