#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
const int maxN = 3e5+5;
int n, a[maxN];
vector<int> edge[maxN];
set<ii> vec[maxN];

int val[maxN*4], lazy[maxN*4];
void down(int k){
	if (lazy[k]==0) return;
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	val[2*k] += lazy[k];
	val[2*k+1] += lazy[k];
	lazy[k] = 0;
}
void updt(int k, int l, int r, int u, int v, int x){
	if (l>v||r<u) return;
	if (u<=l&&r<=v){
		val[k] += x;
		lazy[k] += x;
		return;
	}
	down(k);
	int m = (l+r)/2;
	updt(2*k,l,m,u,v,x);
	updt(2*k+1,m+1,r,u,v,x);
	val[k] = max(val[2*k],val[2*k+1]);
}
int gett(int k, int l,int r, int u, int v){
	if (l>v||r<u) return -1e9;
	if (u<=l&&r<=v){
		return val[k];
	}
	down(k);
	int m = (l+r)/2;
	return max(gett(2*k,l,m,u,v),gett(2*k+1,m+1,r,u,v));
}
int tin[maxN], tout[maxN], timer;
void dfs(int u){
	tin[u] = ++timer;
	for (int v: edge[u]){
		dfs(v);
	}
	tout[u] = timer;
}
int res = 0;
void dfs2(int u){
	vector<int> tmp;
	int tmpm2 = 1;
	for (int v: edge[u]){
		dfs2(v);
	}
	auto it = vec[a[u]].lower_bound({tin[u],1e9});
	while (it!=vec[a[u]].end()&&(*it).first<=tout[u]){
		tmp.push_back((*it).second);
		vec[a[u]].erase(it);
		it = vec[a[u]].lower_bound({tin[u],1e9});
	}
//	cout << u << ":"; for (int x: tmp) cout << x << ", "; cout << "\n";
	for (int x: tmp){
		updt(1,1,n,tin[x],tout[x],-1);
	}
	updt(1,1,n,tin[u],tout[u],1);
	for (int v: edge[u]){
//		dfs2(v);
	
		int tmpm1 = gett(1,1,n,tin[v],tout[v]);
//		tmpm2 = max(tmpm1,tmpm2);
		res = max(res,tmpm1*tmpm2);
		tmpm2 = max(tmpm1,tmpm2);
	}
}
void solve(){
	cin >> n;
	timer = 0;
	for (int i = 1; i <= 4*n; i++) val[i] = lazy[i] = 0;
	for (int i = 1; i <= n; i++) edge[i].clear(), vec[i].clear();
	for (int i = 2, x; i <= n; i++){
		cin >> x;
		edge[x].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		vec[a[i]].insert({tin[i],i});
	}
//	updt(1,1,n,1,1,2);
//	cout << gett(1,1,n,1,2) << "\n";
	res = 1;
	dfs2(1);
	cout << res << "\n";
}

main(){
 	ios::sync_with_stdio(0);
 	cin.tie(0); cout.tie(0);
 	int t; cin >> t;
 	while (t--)
	solve();
	
	return 0;
}
