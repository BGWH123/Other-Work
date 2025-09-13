#include <iostream>
using namespace std;
#define max_size 20

typedef struct {
	int sqBitNode[max_size];
	int ElemNum = 0;  // 表示个数
} sqBitNode;
void creat_sq(sqBitNode &root) {
	int a = 0;
	int i = 0;
	cin >> a;
	while (a != 0) {
		root.sqBitNode[i++] = a;
			root.ElemNum++;
		cin >> a;
	}
}
void pre_vist(sqBitNode &root) {
	for (int i = 0; i < root.ElemNum; i++) {
		if (root.sqBitNode[i] != -1) cout << root.sqBitNode[i] << " ";
	}
	cout << endl;
}

bool judgeInorderBST(sqBitNode &root,int k,int *val){
	if(k<root.ElemNum&&root.sqBitNode[k]!=-1){
		if(!judgeInorderBST(root,2*k+1,val))return false;//左
		if(*val>=root.sqBitNode[k])return false;
		*val=root.sqBitNode[k];
		if(!judgeInorderBST(root,2*k+2,val))return false;
	}
}
int main() {
	sqBitNode root;
	cout << "输入二叉树 -1为空 0 结束" << endl;
	creat_sq(root);
	cout << root.ElemNum << endl;
	cout << "先序是：" << endl;
	pre_vist(root);
	return 0;
}
