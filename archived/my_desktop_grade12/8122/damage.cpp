#include<bits/stdc++.h>

using namespace std;
bool d[100005], c[100005];
vector<int> edge[100005];
int n, m, k;

void dfs(int u){
	d[u] = 1;
	for (int v: edge[u]) if (!c[v]&&!d[v]) dfs(v);
}

int main(){
	cin >> n >> m >> k;
	for (int i = 0, u, v; i < m; i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 0, x; i < k; i++){
		cin >> x;
		for (auto v: edge[x]) c[v] = 1;
	}
	dfs(1);
	int res = 0;
	for (int i = 1; i <= n; i++) res += (d[i]);
	cout << n-res;
	
	
	return 0;
}
