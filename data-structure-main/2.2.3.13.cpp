#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[n];
    for(int i=0;i<n;i++){
        b[i]=0;
    }
    for(int i=0;i<n;i++){
        if(a[i]>0){
            b[a[i]-1]++;
        }
    }
        for(int i=0;i<n;i++){
            if(b[i]==0){
				cout<<i+1;
				return -1;
			}
        }
        cout<<"aa"<<endl;
        cout<< n+1;
    }
