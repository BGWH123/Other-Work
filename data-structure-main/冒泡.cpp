#include<iostream>
using namespace std;

int a[10]={49,38,65,97,76,13,27,49,55,4};


void bubble_sort(int a[],int n){
		bool state=true;
		int q=1;
		while(state){
			state=false;//没有交换
			for(int i=n-1;i>=q;i--){
				if(a[i]<a[i-1]){//交换
					int t=a[i];
					a[i]=a[i-1];
					a[i-1]=t;
					state=true;
				}
			}
			q++;			
		}
};
void show(int a[],int n){
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	bubble_sort(a,10);
	show(a,10);
	
}
