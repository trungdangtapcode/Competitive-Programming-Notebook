#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 5e5+5;
int a[maxN], n;
int timer = 0, tin[maxN], tout[maxN], q, t[maxN], x[maxN], y[maxN], f[maxN];
vector<int> edge[maxN];
void dfs(int u){
//	cout << u << "\n";
	tin[u] = ++timer;
	for (int v: edge[u]){
		dfs(v);
	}
	tout[u] = timer;
}
int val[maxN*4], lazy[maxN*4];
void down(int k, int l, int r,int m){
	if (lazy[k] == 0) return;
	int t = lazy[k];
	lazy[2*k] += t;
	lazy[2*k+1] += t;
	val[2*k] += t;
	val[2*k+1] += t;
	lazy[k] = 0;
}
void updt(int k, int l, int r, int u, int v, int x){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
		val[k] += x;
		lazy[k] += x;
		return;
	}
	int m = (l+r)/2;
	down(k, l,r,m);
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
}
int query(int k, int l, int r, int u){
	if (l>u||r<u) return 0;
	if (l==r) return val[k];
	int m = (l+r)/2;
	down(k,l,r,m);
	return query(2*k,l,m,u) + query(2*k+1,m+1,r,u);
}
void dfs2(int u, int p){
	f[u] += f[p];
	for (int v: edge[u]){
		dfs2(v, u);
	}
}

void solve(){
	cin >> q;
	n = 1;
	for (int i = 1; i <= q; i++) edge[i].clear();
	for (int i = 1; i <= q; i++){
		cin >> t[i];
		if (t[i]==1){
			cin >> x[i];
		}
		else cin >> y[i] >> x[i];
		if (t[i]==1){
			edge[x[i]].push_back(++n);
			y[i] = n;
		}
	}
	timer = 0;
	dfs(1);
	for (int i = 1; i <= 4*n; i++) val[i] = lazy[i] = 0;
	for (int i = 1; i <= n; i++) f[i] = 0;
	for (int i = 1; i <= q; i++){
		if (t[i]==1){
			int u = tin[y[i]], v = tout[y[i]];
			int tmp = query(1,1,n,u);
//			cout << y[i] << ": " << tmp << "\n";
			f[y[i]] -= tmp;
			updt(1,1,n,u,v,-tmp);
		} else {
			f[y[i]] += x[i];
			int u = tin[y[i]], v = tout[y[i]];
//			cout << y[i] << " " << u << ".." << v << " " << x[i]<< "\n";
			updt(1,1,n,u,v,x[i]);
//			for (int i = 1; i <= n; i++) cout << query(1,1,n,i) << " "; cout << "\n";
		}
	}
	dfs2(1,0);
	for (int i = 1; i<= n; i++) cout << f[i] << " "; cout << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	solve();
	return 0;
}
