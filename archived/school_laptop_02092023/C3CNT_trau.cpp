#include<bits/stdc++.h>

using namespace std;
int n, m;
bool visited[1005], c[1005][1005];
vector<int> edge[1005];
int res = 0;
void dfs(int p, int u, int l){
	visited[u] = true;
	for (int v: edge[u]) if (!visited[v]) {
		if (l==1) res += (c[v][p]);
		else dfs(u,v,1);
	}
	visited[u] = false;
}

int main(){
	
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		c[u][v] = true;
	}
	for (int i = 1; i <= n; i++) dfs(-1,i,0);
	cout << res;
	
	
	return 0;
}
