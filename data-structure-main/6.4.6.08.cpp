#include<iostream>
using namespace std;

//四个路由器
//路由器两个连路由器 一个连

//先把IP 和 ID打包
typedef struct Link{
	string ID;
	string IP;
	int metric;
	Link *next;
}Link;
typedef struct Net{
		string profix;
		int metric;
		Net *next;
}Net;


typedef struct Router {
	string Router_ID;
	Link link1;
	Link link2;
	 Router *next_router;//指向router
}router;
