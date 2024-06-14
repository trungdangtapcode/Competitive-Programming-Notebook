#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 2e5+5;
int n, timer, tin[maxN], tout[maxN], a[maxN], p[maxN], q;
vector<int> edge[maxN];
void dfs(int u, int p){
	tin[u] = ++timer;
	for (int v: edge[u]) if (v!=p){
		dfs(v,u);
	}
	tout[u] = timer;
}
set<int> val[4*maxN]; 
void build(int k, int l, int r){
	val[k].clear();
	if (l==r){
		val[k].insert(a[l]);
		return;
	}
	int m = (l+r)/2;
	build(2*k,l,m);
	build(2*k+1,m+1,r);
	for (int x: val[2*k]) val[k].insert(x);
	for (int x: val[2*k+1]) val[k].insert(x);
}
int query(int k, int l, int r, int u, int v, int x){
	if (u>r||v<l) return 1e9;	
	if (u<=l&&r<=v){
		auto it = val[k].lower_bound(x);
		return (it==val[k].end()?1e9:*it);
	}
	int m = (l+r)/2;
	return min(query(2*k,l,m,u,v,x),query(2*k+1,m+1,r,u,v,x));
}

void solve(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1; i < n; i++){
		int u, v; 
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	timer = 0;
	dfs(1,0);
	for (int i = 1; i <= n; i++){
		cin >> p[i];
		a[i] = tin[p[i]];
	}
	build(1,1,n);
	while (q--){
		int l, r, x;
		cin >> l >> r >> x;
		int y = query(1,1,n,l,r,tin[x]);
		cout << (y<=tout[x]?"YES\n":"NO\n");
	}
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) 
	solve();
	
	return 0;
}
