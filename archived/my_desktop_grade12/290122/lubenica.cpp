#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
iii par[100005][20];
int n, d[100005];
vector<ii> edge[100005];
void dfs(int p, int u, int c = -1){
	par[u][0] = {p,{c,c}};
	d[u] = d[p] + 1;
	for (int i = 1; i < 20; i++) par[u][i] = {
		par[par[u][i-1].first][i-1].first,
		{
			min(par[u][i-1].second.first,par[par[u][i-1].first][i-1].second.first),
			max(par[u][i-1].second.second,par[par[u][i-1].first][i-1].second.second)
		}
	};
	for (auto it: edge[u]){
		int v = it.first, c = it.second;
		if (v==p) continue;
		dfs(u,v,c);
	}
}
ii lca(int u, int v){
	if (d[u]>d[v]) swap(u,v);
	int mmax = -1e9, mmin = 1e9;
	for (int i = 19; i >= 0; i--) if (d[par[v][i].first]>=d[u]){
		mmax = max(mmax,par[v][i].second.second);
		mmin = min(mmin,par[v][i].second.first);
		v = par[v][i].first;
	}
	for (int i = 19; i >= 0; i--) if (par[u][i].first!=par[v][i].first){
		mmin = min(mmin,par[v][i].second.first);
		mmax = max(mmax,par[v][i].second.second);
		mmin = min(mmin,par[u][i].second.first);
		mmax = max(mmax,par[u][i].second.second);
		v = par[v][i].first, u = par[u][i].first;
	}
	while (u!=v){
		int i = 0;
		mmin = min(mmin,par[v][i].second.first);
		mmax = max(mmax,par[v][i].second.second);
		mmin = min(mmin,par[u][i].second.first);
		mmax = max(mmax,par[u][i].second.second);
		v = par[v][i].first, u = par[u][i].first;
	}
	return {mmin,mmax};
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, u,v,c; i < n; i++){
		cin >> u >> v >> c;
		edge[u].push_back({v,c});
		edge[v].push_back({u,c});
	}	
	dfs(0,1);
	int q; cin >> q;
	while (q--){
		int u, v;
		cin >> u >> v;
		auto it = lca(u,v);
		cout << it.first << " " << it.second << "\n";
	}
	return 0;
}
