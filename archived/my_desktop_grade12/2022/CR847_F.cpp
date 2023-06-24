#include<bits/stdc++.h>

using namespace std;

int n, f[200005], par[200005], c[200005];
vector<int> edge[200005];	
void dfs(int p, int u){
	par[u] = p;
	for (int v: edge[u]) if (v!=p) dfs(u,v);
}

void solve(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 0, u, v; i < n-1; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(0,1);
	for (int i = 1; i <= n; i++) f[i] = 1e9;
	int res = 1e9;
	for (int i = 0; i < n; i++){
		int cur = 0, u = c[i];
		while (u&&cur<res){
			res = min(res,cur+f[u]);
			f[u] = min(f[u],cur);
			++cur;
			u = par[u];
		} 
		if (i) cout << res << " ";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1; cin >>t;
	while (t--){
		solve();
	}
	
	return 0;
}
