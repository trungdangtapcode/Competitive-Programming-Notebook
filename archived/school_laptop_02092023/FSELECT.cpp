#include<bits/stdc++.h>

using namespace std;
int d[200005], cha[200005][20], n, k;
vector<int> p[200005], edge[200005];

void dfs(int p, int u){
	d[u] = d[p] + 1;
	cha[u][0] = p;
	for (int i = 1; i <= 19; i++) cha[u][i] = cha[cha[u][i-1]][i-1];
	for (int v: edge[u]) if (v!=p) dfs(u,v);
}
int lca(int u, int v){
	if (d[u]<d[v]) swap(u,v);
	for (int i = 19; i >= 0; i--) if (d[cha[u][i]]>d[v]) u = cha[u][i];
	while (d[u]>d[v]) u = cha[u][0];
	for (int i = 19; i >= 0; i--) if (cha[u][i]!=cha[v][i]) u = cha[u][i], v = cha[v][i];
	while (u!=v) u = cha[u][0], v = cha[v][0];
	return u;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	
	cin >> n >> k;
	for (int i = 1, x, y; i <= n; i++){
		cin >> x >> y;
		p[x].push_back(i);
		if (y!=0) edge[i].push_back(y), edge[y].push_back(i);
	}
	dfs(1,1);
	for (int i = 1; i <= k; i++){
		int x = p[i][0];
		for (int y: p[i]) if (d[y]>d[x]) x = y;
		int res = 0;
		for (int y: p[i]){
			res = max(res,d[x]+d[y]-2*d[lca(x,y)]);
		}
		cout << res << "\n";
	}
	
	
	return 0;
}
