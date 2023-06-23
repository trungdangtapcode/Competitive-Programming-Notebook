#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, go[2005][2005], f[2005][2005];
string s;
vector<int> edge[2005];
void dfs(int u, int p, int root){
	go[u][root] = p;
	for (int v: edge[u]) if (v!=p) dfs(v,u,root);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		s = "&" + s;
		for (int i = 1; i <= n; i++) edge[i].clear();
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = 0;
		for (int i = 1, u, v; i < n; i++){
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		queue<ii> q;
		for (int i = 1; i <= n; i++){
			dfs(i, i, i);
			q.push({i,i});
		}
		int res = 0;
		while (q.size()){
			int u = q.front().first, v = q.front().second; q.pop();
			if (f[u][v]) continue;
			f[u][v] = max(f[go[u][v]][v],f[u][go[v][u]]);
			if (s[u]==s[v]) f[u][v] = max(f[u][v],f[go[u][v]][go[v][u]]*(go[u][v]!=v)+(u==v?1:2));
			for (int uu: edge[u]) if (uu!=go[u][v]) q.push({uu,v});
			for (int vv: edge[v]) if (vv!=go[v][u]) q.push({u,vv});
			res = max(res,f[u][v]);
		}
		cout << res << "\n";
	}
	
	return 0;
}
