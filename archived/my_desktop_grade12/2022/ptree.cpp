#include<bits/stdc++.h>

using namespace std;

int n, k, f[205][205], trace[205][205], par[205];
vector<int> edge[205];
void dfs(int p, int u){
	par[u] = p;
	for (int v: edge[u]) if (v!=p){
		dfs(u,v);
		for (int i = k; i > 0; i--) for (int j = 1; j<i; j++) 
			tie(f[u][i],trace[v][i]) = max(make_tuple(f[u][i],trace[v][i]),make_tuple(f[u][i-j]+f[v][j],j));
	}
}
void truyvet(int u, int c){
	if (c==0) return;
	cout << u << " ";
	reverse(edge[u].begin(),edge[u].end());
	for (int v: edge[u]) if (v!=par[u]){
		truyvet(v,trace[v][c]);
		c -= trace[v][c];
	}
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = -1e9;
	for (int i = 1; i <= n; i++) cin >> f[i][1];
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	int res1 = -1e9, res2 = 0;
	
	dfs(0,1);
	for (int i = 1; i <= n; i++) tie(res1,res2) = max(make_tuple(res1,res2),make_tuple(f[i][k],i));
	truyvet(res2,k);
	return 0;
}
