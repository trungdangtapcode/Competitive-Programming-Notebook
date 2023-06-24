#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
vector<int> edge[1005];
vector<ii> topo, edgelist;
bool visit[1005], cycle;
int n, m, res[1005], st;

bool hasPath(int u, int s, int t){
	visit[u] = true;
	for (int v: edge[u]){
		if (!visit[v]&&(u==s&&v==t||v!=t&&hasPath(v,s,t))) return 1;
	}
	return 0;
}
void dfs(int u){
	visit[u] = true;
	for (int v: edge[u]) if (!visit[v]) dfs(v); else if (!res[v]) cycle = true;
	res[u] = st--;
}

int main(){
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edgelist.push_back({u,v});
	}
	
	for (auto it: edgelist){
		int u = it.first, v = it.second;
		memset(visit,0,sizeof(visit));
		if (hasPath(1,u,v)) topo.push_back({u,v});
	}
	for (int i = 1; i <= n; i++) edge[i].clear();
	for (auto it: topo){
		int u = it.first, v = it.second;
		edge[u].push_back(v);
	}
	memset(visit,0,sizeof(visit));
	st = n;
	dfs(1);
	for (int i = 1; i <= n; i++) if (!res[i]) res[i] = st--; //i hate this line
	if (cycle) cout << -1 << "\n";
	else for (int i = 1; i <= n; i++) cout << res[i] << " ";
	
	return 0;
}
