#include<iostream>
#include<algorithm>
using namespace std;

int a[10]={49,38,65,97,76,13,27,49,55,4};


void select_sort(int a[],int n){
		for(int i=0;i<n;i++){
			int temp=i;
			for(int j=i;j<n;j++){
			if(a[temp]>a[j])temp=j;
			}
			swap(a[temp],a[i]);
		}
};
void show(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	select_sort(a,10);
	show(a,10);
	
}
