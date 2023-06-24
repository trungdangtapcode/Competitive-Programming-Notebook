#include<bits/stdc++.h>

using namespace std;
int n, q, par[100005][20], d[100005], rmq[100005][20];
vector<int> edge[100005];

void dfs(int p, int u){
	par[u][0] = p;
	d[u] = d[p] + 1;
	for (int i = 1; i < 20; i++) par[u][i] = par[par[u][i-1]][i-1];
	for (int v: edge[u]) if (v!=p) dfs(u,v);
}
int lca(int u, int v){
	if (d[u]>d[v]) swap(u,v);
	for (int i = 19; i >= 0; i--) if (d[par[v][i]]>=d[u]) v = par[v][i];
	for (int i = 19; i >= 0; i--) if (par[v][i]!=par[u][i]) u = par[u][i], v = par[v][i];
	while (u!=v) u = par[u][0], v= par[v][0];
	return u;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 0, u, v; i < n-1; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,1);
	for (int i = 1; i <= n; i++) rmq[i][0] = i;
	for (int i = 1; i < 20; i++){
		for (int j = 1; j + (1<<i) -1 <= n; j++) rmq[j][i] = lca(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
	}
	while (q--){
		int u, v;
		cin >> u >> v;
		int h = __lg(v-u+1);
		cout << lca(rmq[u][h],rmq[v-(1<<h)+1][h]) << "\n";
	}
	return 0;
}
