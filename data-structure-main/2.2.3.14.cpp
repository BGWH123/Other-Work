#include<bits/stdc++.h>
using namespace std;
int main(){
	int p[]={-1,0,9};
	int q[]={-25,-10,10,11};
	int	r[]={2,9,17,30,41};
	int i=0,j=0,k=0;
	int ans=INT_MAX;
	while(i<3&&j<4&&k<5&&ans>0){
		ans=min(ans,abs(p[i]-q[j])+abs(p[i]-r[k])+abs(q[j]-r[k]));
		if(i<=j&&i<=k)i++;
		else if(j<=i&&j<=k)j++;
		else k++;
	}
	cout<<ans<<endl;
}
