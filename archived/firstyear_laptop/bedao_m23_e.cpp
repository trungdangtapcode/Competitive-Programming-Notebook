#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 5e5+5;
int n, a[maxN], k, lazy[maxN*4];
typedef pair<int,int> pii;
pii val[maxN*4];
void build(int k, int l, int r){
	if (l==r){
		val[k] = {a[l],l};
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	val[k] = min(val[2*k],val[2*k+1]);
}
void down(int k){
	if (lazy[k]==0) return;
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	val[2*k].first -= lazy[k];
	val[2*k+1].first -= lazy[k];
	lazy[k] = 0;
}
void updt(int k, int l, int r, int u, int v, int x){
	if (r<u||l>v) return;
	if (u<=l&&r<=v){
		val[k].first -= x;
		lazy[k] += x;
		return;
	}
	down(k);
	int m = (l+r)/2;
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	val[k] = min(val[2*k],val[2*k+1]);
}
pii gett(int k, int l, int r, int u, int v){
	if (l>v||r<u) return {1e18,-1};
	if (u<=l&&r<=v) return val[k];
	down(k);
	int m = (l+r)/2;
	return min(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
}

int bit_val[maxN];
void bit_updt(int x, int y){
	for (;x <= n; x += x&-x){
		bit_val[x] += y;
	}
}
int bit_get(int x){
	int res = 0;
	for (; x; x -= x&-x){
		res += bit_val[x];
	}
	return res;
}



main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] -= k;
	}
	build(1,1,n);
	int q;
	cin >> q;
	while (q--){
		int t, l, r, x;
		cin >> t;
		if (t==1){
			cin >> l >> r >> x;
			updt(1,1,n,l,r,x);
		} else {
			while (1){
				auto it = gett(1,1,n,1,n);
				if (it.first>0) break;
				int u = it.second;
				updt(1,1,n,u,u,-1e18);
				bit_updt(u,1); 
			}
			cin >> l >> r;
			cout << bit_get(r)-bit_get(l-1) << "\n";
		}
	}
	
	
	return 0;
}
