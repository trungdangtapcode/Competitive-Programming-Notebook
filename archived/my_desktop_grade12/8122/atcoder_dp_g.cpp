#include<bits/stdc++.h>

using namespace std;
int n, f[100005], m;
vector<int> edge[100005];
int dfs(int u){
	for (int v: edge[u]){
		f[u] = max(f[u],(f[v]==0?dfs(v):f[v])+1);
	}
	return f[u];
}
int main(){
	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) if (f[i]==0) res = max(res,dfs(i));
	cout << res;
	
	return 0;
}
