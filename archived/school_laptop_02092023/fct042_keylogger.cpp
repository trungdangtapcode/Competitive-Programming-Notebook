#include<bits/stdc++.h>

using namespace std;

struct node{
    char c;
	node *nxt;
	node *prv;
} *root;
void chen(node *p, char c){
	if (p->prv==p){
		node *tmp = new node;
		p->prv = tmp;
		tmp->c = c;
		tmp->nxt = p;
		tmp->prv = tmp;
		root = tmp;
	} else {
		node *tmp = new node;
		tmp->c = c;
		tmp->nxt = p;
		tmp->prv = p->prv;
		p->prv = tmp;
		tmp->prv->nxt = tmp;
	}
}
void del(node *p){
	if (p->prv==p) return;
	p = p->prv;
	if (p->prv==p){
		root = p->nxt;
		p->nxt->prv = p->nxt;
		free(p);
	} else {
		p->nxt->prv = p->prv;
		p->prv->nxt = p->nxt;
		free(p);
	}
}
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	root = new node;
	root->prv = root;
	root->nxt = root;
	node *p;
	p = root;
	cin >> s;
	for (char c: s){
		if (c=='<') p = p->prv;
		else if (c=='>') p = p->nxt;
		else if (c=='-') del(p);
		else chen(p,c);
	}
	for (node* p = root; p->nxt!=p; p = p->nxt){
		cout << p->c;
	}
	
	
	
	return 0;
}
