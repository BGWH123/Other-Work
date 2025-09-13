#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *link;
} LNode, *LinkList;

int search_k(LinkList list, int k) {
	LNode *p = list->link;
	LNode *q = list->link;
	while (p != nullptr && k > 1) {
		p = p->link;
		k--;
	}
	if (k > 1)return 0;
	else {
		while (p ->link!= nullptr) {
			q = q->link;
			p = p->link;
		}
		cout << "ans:"<<q->data;
		return 0;


	}

}

LinkList List_head(LinkList &L){
	LNode *t;
	L=new(LNode);
	L->link=NULL;
	int x;
	cin>>x;
	while(x!=0){
		t=new(LNode);
		t->data=x;
		t->link=L->link;
		L->link=t;
		cin>>x;
	}
}

int main(){
	LNode *L;
	List_head(L);
	search_k(L,3);
	
}
