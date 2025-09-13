#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void createtreenode(TreeNode *&root) {
int a = 0;
cin >> a;
if (a == -1) {
root = NULL;
} else {
root = new TreeNode(a);
createtreenode(root->left);
createtreenode(root->right);
}
}


void pre_vist(TreeNode *root) {
if (root != nullptr) {
cout << root->val << " ";
pre_vist(root->left);
pre_vist(root->right);
}
}
int ans=0;
void WPL(TreeNode *root,int deep){
	if(root->left==nullptr&&root->right==nullptr){
		ans+=(deep*root->val);
	}
	if(root->left!=nullptr)WPL(root->left,deep+1);
	if(root->right!=nullptr)WPL(root->right,deep+1);
}

int main() {
cout << "请输入二叉树，-1表示空节点：" << endl;
TreeNode *root = NULL;
createtreenode(root);
cout << "先序遍历结果为：" << endl;
pre_vist(root);
WPL(root,0);
cout<<endl;
cout<<"ans:"<<endl;
cout<<ans<<endl;
}
