#include<iostream>
#include<limits.h>
using namespace std;
int a[10] = {1, 2, -3, 4, -5, 6, -7, 8, -9, 10};
int b[11]={};//前缀和数组
void show(int a[], int n) {
	for (int i = 0; i < n; i++)cout << a[i] << " ";
};
//前缀和
void pre_sum(int a[],int b[],int n){
	b[0]=0;
	for(int i=0;i<n;i++){
		b[i+1]=a[i]+b[i];
	}
	show(b,11);
}
void func (int b[],int n){
	int pos=-1;
	int s1=0;
	int s2=0;
	int max_sub=INT_MIN;
	int min_num_sub=INT_MAX;
	for(int i=0;i<n;i++){
		int s=abs(b[i+1]-(b[n]-b[i+1]));//算s
		int t=abs((i+1)-(n-i-1));//算个数
		if(max_sub<s||(max_sub==s&&t<min_num_sub)){//利用前缀和算出s1 s2的绝对值小的 如果相等 则判断现在个数的差距
			pos=i;
			max_sub=s;
			min_num_sub=t;
			s1=b[i+1];
			s2=b[n]-b[i+1];//保存
		}
	}
	cout<<"从第"<<pos+1<<" 划分 s1="<<s1<<" s2:"<<s2<<" 元素个数差："<<min_num_sub<<endl;
}


int main(){
	pre_sum(a,b,10);
	func(b,10);	
}
