#include<iostream>
using namespace std;
#define maxv 20
typedef struct{
	int numVertices,numEdges;//¶¥µãÊý ±ßÊý
	int verticesList[maxv];
	int Edge[maxv][maxv];
}MGraph;

int IsExistEl(MGraph g){
	int ans=0;
	for(int i=0;i<g.numVertices;i++){
		int temp=0;
		for(int j=0;j<g.numVertices;j++){
		if(g.Edge[i][j]!=0)temp++;
		}
		if(temp%2!=0)ans++;
	}
	if(ans==2||ans==0)return 1;
	return 0;
}
