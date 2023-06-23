#include<bits/stdc++.h>

using namespace std;
bool visited[1005], circle;
int cnt, num[1005], n, m;
vector<int> edge[1005];
vector<pair<int,int>> edgelist;

void dfs(int u){
	visited[u] = true;
	for (int v: edge[u]) if (!visited[v]) dfs(v); else if (num[v]!=0) circle = true;
//	order[cnt] = u;
	num[u] = cnt--;
}

bool hasPath(int u, int uu, int vv){
	visited[u] = true;
	for (int v: edge[u]) if (!visited[v]){
		if (u==uu&&v==vv) return 1;
		if (v!=vv) if (hasPath(v,uu,vv)) return 1;
	}
	return 0;
}
bool hasAnswer(){
	for (auto it: edgelist){
		int u = it.first, v = it.second;
//		memset(visited,0,sizeof(visited));
		for (int i = 1; i <= n; i++) visited[i] = 0;
		if (hasPath(1,u,v)&&num[u]>num[v]) return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edgelist.push_back({u,v});
	}
	cnt = n;
	dfs(1);
	for (int i = 1; i <= n; i++) if (num[i]==0) num[i] = cnt--;
//	cout << hasAnswer();
	if (hasAnswer()) for (int i = 1; i <= n; i++) cout << num[i] << " ";
	else cout << -1;
	
//	memset(visited,0,sizeof(visited));
//	cout << hasPath(1,4,3);
	return 0;
}
