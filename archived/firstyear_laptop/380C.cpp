#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;
int n;
string s;

struct Node{
	int val, open, close;
	Node(int _val = 0, int _open = 0, int _close = 0){
		val = _val;
		open = _open;
		close = _close;
	}
	Node operator+(Node other){
		Node res;
		int tmp = min(open,other.close);
		res.val = val+other.val+tmp;
		res.open = open-tmp+other.open;
		res.close = close+other.close-tmp;
		return res;
	}
} val[maxN*4];

void build(int k, int l, int r){
	if (l==r){
		if (s[l]=='(') val[k].open = 1;
		else val[k].close = 1;
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = val[2*k] + val[2*k+1];
}
Node query(int k, int l, int r, int u, int v){
	if (l>v||r<u) return Node();
	if (u<=l&&r<=v) return val[k];
	int m = (l+r)/2;
	return query(2*k,l,m,u,v) + query(2*k+1,m+1,r,u,v);
}


void solve(){
	cin >> s;
	n = s.length();
	s = " " + s;
	build(1,1,n);
	int q; cin >> q;
	while (q--){
		int l, r;
		cin >> l >> r;
		cout << query(1,1,n,l,r).val*2 << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

