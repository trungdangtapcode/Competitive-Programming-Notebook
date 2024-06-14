#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 5;
int n, m, a[maxN], din[maxN], d[maxN], visied[maxN];
vector<int> edge[maxN];
void dfs(int u){
	visied[u] = 1;
	if (d[u]!=-1) return;
	d[u] = a[u];
	for (int v: edge[u]) if (!visied[v]){
		dfs(v);
		d[u] ^= d[v];
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		din[v]++;
	} 
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = 0;
	for (int i = 1; i <= n; i++){
		if (edge[i].empty()) d[i] = 0;
		else d[i] = -1, res ^= (a[i]&1);
	}
//	for (int i = 1; i <= n; i++){
//		if (!visied[i]) dfs(i);
//	}
//	int res = 0;
//	for (int i = 1; i <= n; i++) cout << d[i] << " ";
//	for (int i = 1; i <= n; i++) if (!din[i]) res ^= (d[i]&1);
	cout << (res?"YES\n":"NO\n");
	
	
	return 0;
}
