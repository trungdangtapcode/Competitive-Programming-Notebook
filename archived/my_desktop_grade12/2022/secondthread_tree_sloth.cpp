#include<bits/stdc++.h>

using namespace std;
vector<int> edge[300005];
int par[300005][20], d[300005], n;
void dfs(int p, int u){
	d[u] = d[p]+1;
	par[u][0] = p;
	for (int i = 1; i < 20; i++) par[u][i] = par[par[u][i-1]][i-1];
	for (int v: edge[u]) if (p!=v){
		dfs(u,v);
	}
}
int lca(int u, int v){
	if (d[u]>d[v]) swap(u,v);
	for (int i = 19; i >= 0; i--) if (d[par[v][i]]>=d[u]) v = par[v][i];
	for (int i = 19; i >= 0; i--) if (par[u][i]!=par[v][i]) u = par[u][i], v = par[v][i];
	while (u!=v) u = par[u][0], v = par[v][0];
	return u;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0, u, v; i < n-1; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,1);
	int q; cin >> q;
	while (q--){
		int a, b, c, act;
		cin >> a >> b >> c;
		act = lca(a,b);
		if (d[a]+d[b]-2*d[act]<=c){
			cout << b << "\n";
		} else if (d[a]-d[act]<=c) {
			c -= d[a]-d[act];
			for (int i = 19; i >= 0; i--) if (d[par[b][i]]-d[act]>=c) b = par[b][i];
			cout << b << "\n";
		} else {
			c = d[a]-d[act]-c;
			for (int i = 19; i >= 0; i--) if (d[par[a][i]]-d[act]>=c) a = par[a][i];
			cout << a << "\n";
		}
	}
	
	return 0;
}
