#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode, *LinkList;

LinkList List_head(LinkList &L){
	LNode *t;
	L=new(LNode);
	L->next=NULL;
	int x;
	cin>>x;
	while(x!=0){
		t=new(LNode);
		t->data=x;
		t->next=L->next;
		L->next=t;
		cin>>x;
	}
}
int len (LNode *head){
	int len=0;
	while(head->next!=nullptr){
		len++;
		head=head->next;
	}
}
void show_t(LNode* L){
	LNode *t = L->next;
		while (t!= nullptr) {
			cout << t->data << " ";
			t = t->next;
		}
}
int main(){
	LNode *L,*q,*p;
	List_head(L);
	q=p=L;
	while(q->next!=nullptr){
		p=p->next;
		q=q->next;
		if(q->next!=nullptr)q=q->next;
	}
	q=p->next;
	LNode *t=nullptr;
	while(q!=nullptr){
		LNode *r=q->next;
		q->next=t;
		t=q;
		q=r;
	}
	p->next=t;
	cout<<1<<endl;
	show_t(L);//·­×ªºó
	LNode *s=L->next;
	q=p->next;
	p->next=nullptr;//!!!!!!!!!
	while(q!=nullptr){
	LNode *r=q->next;
	q->next=s->next;
	s->next=q;
	s=q->next;
	q=r;	
	}
	cout<<"MM"<<endl;
	show_t(L);
	
}
