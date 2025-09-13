#include <iostream>
using namespace std;
struct TreeNode {
	char val;
	TreeNode *left;
	TreeNode *right;
	//TreeNode(char x[10]) : val(x), left(NULL), right(NULL) {}
};
void createtreenode(TreeNode *&root) {
	char a=' ';
	cin >> a;
	if (a == '0') {
		root = NULL;
	} else {
		root = new TreeNode;
		root->val=a;
		createtreenode(root->left);
		createtreenode(root->right);
	}
}
void pre_vist(TreeNode *root) {
	if (root != NULL) {
		cout << root->val << " ";
		pre_vist(root->left);
		pre_vist(root->right);
	}
}
void mid_vist_kh(TreeNode *root,int deep) {
	if(root==nullptr)return ;
	else if(root->left==nullptr&&root->right==nullptr)cout<<root->val;
	else{//非叶结点
		if(deep>0)cout<<"(";
		mid_vist_kh(root->left,deep+1);
		cout<<root->val;
		mid_vist_kh(root->right,deep+1);
		if(deep>0)cout<<")";
	}
}


int main() {
	cout << "请输入二叉树，0表示空节点：" << endl;
	TreeNode *root = NULL;
	createtreenode(root);
	cout << "先序遍历结果为：" << endl;
	pre_vist(root);
	cout << endl;
	mid_vist_kh(root,0);
	return 0;
}
