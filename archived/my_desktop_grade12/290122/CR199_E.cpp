#include<bits/stdc++.h>

using namespace std;

int par[100005][20], d[100005], n, m, f[100005];
vector<int> edge[100005];

void dfs(int p, int u){
	par[u][0] = p;
	for (int i = 1; i < 20; i++) par[u][i] = par[par[u][i-1]][i-1];
	d[u] = d[p] + 1;
	for (int v: edge[u]) if (v!=p) dfs(u,v);
}
int lca(int u, int v){
	if (d[u]>d[v]) swap(u,v);
	for (int i = 19; i >= 0; i--) if (d[par[v][i]]>=d[u]) v = par[v][i];
	for (int i = 19; i >= 0; i--) if (par[v][i]!=par[u][i]) u = par[u][i], v = par[v][i];
	while (u!=v) u = par[u][0], v = par[v][0];
	return u;
}
void bfs(vector<int>& v){
	queue<int> q;
	for (int x: v){
		f[x] = 0;
		q.push(x);
	}
	v.clear();
	while (q.size()){
		int u = q.front(); q.pop();
		for (int v: edge[u]) if (f[v]>f[u]+1){
			f[v] = f[u] + 1;
			q.push(v);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int T = sqrt(n);
	vector<int> cur; cur.push_back(1);
	for (int i = 1; i <= n; i++) f[i] = 1e9;
	for (int i = 0, u, v; i < n-1; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(0,1);
	while (m--){
		int type, u;
		cin >> type >> u;
		if (type==1){
			cur.push_back(u);
			if (cur.size()>T) bfs(cur);
		} else {
			int res = f[u];
			for (int v: cur) res = min(res,d[u]+d[v]-2*d[lca(u,v)]);
			cout << res << "\n";
		}
	}
	
	
	return 0;
}
