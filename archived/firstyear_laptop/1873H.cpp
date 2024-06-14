#include<bits/stdc++.h>

using namespace std;

int n, a, b, d[200005], pv[200005], f[200005];
vector<int> edge[200005];
bool cycle[200005], visited[200005];
bool dfs(int u, int p){
	bool res = 0;
	visited[u] = 1;
	for (int v: edge[u]) if (v!=p){
		if (visited[v]&&!cycle[v]){
			cycle[v] = cycle[u] = 1;
//			cout << u << "-" << v << " and " << p <<"\n";
			return 1;
		}
		if (visited[v]) return 0;
		if (dfs(v,u)&&!cycle[u]){
			cycle[u] = 1;
			return 1;
		}
	}
	return 0;
}
void dfs2(int u, int p){
	d[u] = d[p] + 1;
	pv[u] = pv[p]; 
	if (cycle[u]) d[u] = 0, pv[u] = u;
	for (int v: edge[u]) if (v!=p){
		if (d[v]!=-1) continue;
		dfs2(v,u);
	}
}
int dfs3(int u, int p, int s, int t){
//	f[u] = 1e9;
//	if (u==t) return 0;
//	for (int v: edge[u]) if (v!=p){
//		if (f[v]!=-1){
//			f[u] = min(f[u],f[v]+1);
//			continue;
//		};
//		f[u] = min(f[u],dfs3(v,u,s,t)+1);
//	}
//	return f[u];
	queue<int> q;
	f[s] = 0;
	q.push(u);
	while(q.size()){
		int u= q.front(); q.pop();
		for (int v: edge[u]) if (f[v]>f[u]+1){
			f[v]= f[u]+1;
			q.push(v);
		}
	}
	return f[t];
}

void solve(){
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (int i = 1; i <= n; i++){
		d[i] = -1;
		cycle[i] = 0;
		visited[i] = 0;
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	for (int i = 1; i <= n; i++) if (cycle[i]){
		dfs2(i,0);
		break;
	}
	for (int i = 1; i<= n; i++) f[i] = 1e9;
//	cout << dfs3(a,0,a,pv[b]) << "\n";
	cout << (d[b]<dfs3(a,0,a,pv[b])?"YES\n":"NO\n");
//	for (int i = 1; i <= n; i++) cout << cycle[i] << " ";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}

