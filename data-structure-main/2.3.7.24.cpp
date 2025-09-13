#include<bits/stdc++.h>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *link;
} LNode, *LinkList;

void deletS(LinkList &list, int m[]) {
	LNode *p = list->link;
	LNode *q = list;
	while (p->link != nullptr) {
		if (m[abs(p->data)-1] != 0) {
			LNode *t = p;
			q->link = p->link;
			p = p->link;
			free(t);
		} else {
			m[abs(p->data)-1] = 1;
			p = p->link;
			q=q->link;
		}
	}
	LNode *t = list->link;
	while (t!= nullptr) {
		cout << t->data << " ";
		t = t->link;
	}
	

}


LinkList List_head(LinkList &L) {
	LNode *t;
	L = new (LNode);
	L->link = NULL;
	int x;
	cin >> x;
	while (x != 0) {
		t = new (LNode);
		t->data = x;
		t->link = L->link;
		L->link = t;
		cin >> x;
	}
}

int main() {
	LNode *L;
	int m[5];
	for (auto &i : m) {
		i = 0;
	}
	List_head(L);
	deletS(L, m);

}
