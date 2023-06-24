#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector<ii> edge[300005];
ii par[300005][20];
int n, m, d[300005];
void dfs(int p, int u, int c){
	d[u] = d[p]+1;
	par[u][0] = {p,c};
	for (int i = 1; i < 20; i++) par[u][i] = {
		par[par[u][i-1].first][i-1].first,
		min(par[u][i-1].second,par[par[u][i-1].first][i-1].second)
	};
	for (auto it: edge[u]){
		int v = it.first, c = it.second;
		if (v==p) continue;
		dfs(u,v,c);
	}
}
int lca(int u, int v){
	int res = 1e9;
	if (d[u]>d[v]) swap(u,v);
	for (int i = 19; i >= 0; i--) if (d[par[v][i].first]>=d[u]){
		res = min(res,par[v][i].second);
		v = par[v][i].first;
	}
	for (int i = 19; i >= 0; i--) if (par[v][i].first!=par[u][i].first){
		res = min(res,par[v][i].second);
		res = min(res,par[u][i].second);
		v = par[v][i].first; u = par[u][i].first;
	}
	while (u!=v){
		res = min(res,par[v][0].second);
		res = min(res,par[u][0].second);
		v = par[v][0].first; u = par[u][0].first;
	}
//	cout << u << " <== lca\n";
//	cout << par[2][19].second << "\n";
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0, u, v, w; i < m; i++){
		cin >> u >> v >> w;
		edge[u].push_back({v,w});
		edge[v].push_back({u,w});
	}
	dfs(1,1,1e9);
	int q; cin >> q;
	while (q--){
		int a, b; cin >> a >> b;
		cout << lca(a,b) << "\n";
	}
	
	return 0;
}
