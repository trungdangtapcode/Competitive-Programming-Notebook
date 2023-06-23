#include<bits/stdc++.h>

using namespace std;
int d[200005], f[200005], n, m;
vector<int> edge[200005];
void bfs(){
	fill(d,d+n+1,1e9);
	queue<int> q;
	q.push(1);
	d[1] = 0;
	while (q.size()){
		int u = q.front(); q.pop();
		for (int v: edge[u]) if (d[v]>d[u]+1){
			d[v] = d[u]+1;
			q.push(v);
		};
	}
}
int dfs(int u){
	if (f[u]!=-1) return f[u];
	f[u] = d[u]; 
	for (int v: edge[u]) if (d[v]>d[u]){
		f[u] = min(f[u],dfs(v));
	} else f[u] = min(f[u],d[v]);
	return f[u];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++) edge[i].clear();
		fill(f,f+n+1,-1);
		for (int i = 0, u, v; i < m; i++){
			cin >> u >> v;
			edge[u].push_back(v);
		}
		bfs();
		dfs(1);
		for (int i = 1; i <= n; i++) cout << f[i] << " "; cout << "\n";
	}
	return 0;
}
