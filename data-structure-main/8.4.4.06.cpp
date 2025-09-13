#include<iostream>
#include<time.h>
#include<random>
#include<algorithm>
#include<limits>
using namespace std;

int a[100000]={};
int ans[10]={};

void adjust_heap(int a[],int k){
	int temp=a[k];
	int i=2*k+1;
	while(i<10){//大根堆
		if(i<9&&a[i+1]>a[i])i++;
		if(a[i]<=temp)break;
		else{
			a[k]=a[i];//把根覆盖了
			k=i;//修改当前根
			i=2*k+1;//修改i！！
		}
	}
	a[k]=temp;
}

void build_heap(int a[]){
	for(int i=4;i>=0;i--){
		adjust_heap(a,i);
	}
}
void _sort(int a[],int ans[]){
		for(int i=10;i<100000;i++){
			if(a[i]<ans[0]){
				ans[0]=a[i];
				adjust_heap(ans,0);
			}
		}
};
void show(int a[]){
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	srand(time(0));
	for(int i=0;i<100000;i++){
		a[i]=rand()%6000000+25;
	}
	for(int i=0;i<10;i++)ans[i]=a[i];
	build_heap(ans);
	_sort(a,ans);
	show(ans);
	
}
