#include<bits/stdc++.h>

using namespace std;

struct Node{
	int cnt[41];
	long long val;
	Node(){
		memset(cnt,0,sizeof(cnt));
		val = 0;
	}
	Node operator+(Node other){
		Node res = Node();
		for (int i = 1; i <= 40; i++) res.cnt[i] = cnt[i] + other.cnt[i];
		res.val = val + other.val;
		for (int i = 1, sum = 0; i <= 40; i++){
			res.val += 1ll*cnt[i]*sum;
			sum += other.cnt[i];
		}
		return res;
	}
	int diff(){
		int res =0;
		for (int i = 1; i <= 40; i++) if (cnt[i]) res++;
		return res;
	}
};
Node node[400005];
int n, a[100005], q;
void build(int k, int l, int r){
	if (l==r){
		node[k].cnt[a[l]] = 1;
		node[k].val = 0;
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	node[k] = node[2*k] + node[2*k+1];	
}
Node gett(int k, int l, int r, int u, int v){
	if (l>v||u>r) return Node();
	if (u<=l&&r<=v) return node[k];
	int m = (l+r)/2;
	return gett(2*k,l,m,u,v)+gett(2*k+1,m+1,r,u,v);
}
void updt(int k, int l, int r, int u, int x){
	if (l>u||r<u) return;
	if (l==r){
		node[k].cnt[a[l]] = 0;
		a[l] = x;
		node[k].cnt[a[l]] = 1;
		node[k].val = 0;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,x);
	updt(2*k+1,m+1,r,u,x);
	node[k] = node[2*k] + node[2*k+1];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1,1,n);
	while (q--){
		int type, x, y;
		cin >> type >> x >> y;
		if (type==1){
			cout << gett(1,1,n,x,y).diff() << "\n";
		} else updt(1,1,n,x,y);
	}
	
	
	return 0;
}
