#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
	char data;
	struct LNode *next;
} LNode, *LinkList;

LinkList List_head(LinkList &L){
	LNode *t;
	L=new(LNode);
	L->next=NULL;
	char x;
	cin>>x;
	while(x!='0'){
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
int main(){
	LNode *p,*q,*L1,*L2;
	List_head(L1);
	int m=len(L1);
	cout<<"µÚ¶þ¸ö"<<endl;
	List_head(L2);
	int n=len(L2);
	if(m>n){
		for(p=L1;m>n;m--)p=p->next;
	}
	else{
		for(q=L2;n>m;n--)q=q->next;
	}
	while(p->next!=NULL&&p->next!=q->next);{
		p=p->next;
		q=q->next;
	}
	cout<<q->next->data<<endl;
	
}
